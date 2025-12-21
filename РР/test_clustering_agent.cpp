/*
 * Тесты для ClusteringAgent
 * Агент выполняет K-means кластеризацию магазинов и определяет координаты складов
 */

#include <sc-memory/test/sc_test.hpp>
#include <sc-memory/sc_memory.hpp>
#include <iostream>
#include <cmath>
#include <iomanip>

#include "agents/ClusteringAgent.hpp"
#include "keynodes/LogisticsKeynodes.hpp"
#include "utils/GeometryUtils.hpp"

using namespace logistics;
using ClusteringAgentTest = ScMemoryTest;

// Вспомогательная функция для создания магазина
static ScAddr CreateShop(ScAgentContext & ctx, ScAddr networkAddr, int id, double x, double y, double volume)
{
  ScAddr shopAddr = ctx.GenerateNode(ScType::ConstNode);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::concept_shop, shopAddr);
  ctx.GenerateConnector(ScType::ConstPermPosArc, networkAddr, shopAddr);

  ScAddr idLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(idLink, std::to_string(id));
  ScAddr idArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, idLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_id, idArc);

  ScAddr xLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(xLink, std::to_string(x));
  ScAddr xArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, xLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_x, xArc);

  ScAddr yLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(yLink, std::to_string(y));
  ScAddr yArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, yLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_y, yArc);

  ScAddr volLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(volLink, std::to_string(volume));
  ScAddr volArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, volLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_delivery_volume, volArc);

  return shopAddr;
}

static ScAddr CreateNetwork(ScAgentContext & ctx)
{
  ScAddr networkAddr = ctx.GenerateNode(ScType::ConstNode);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::concept_trading_network, networkAddr);
  return networkAddr;
}

// Структура для хранения координат склада
struct WarehouseCoord { double x, y; };

// Извлечение координат складов из результата
static std::vector<WarehouseCoord> ExtractWarehouses(ScAgentContext & ctx, ScStructure const & result)
{
  std::vector<WarehouseCoord> coords;
  ScIterator3Ptr variantIt = ctx.CreateIterator3(result, ScType::ConstPermPosArc, ScType::ConstNode);
  
  while (variantIt->Next())
  {
    ScAddr nodeAddr = variantIt->Get(2);
    ScIterator5Ptr whIt = ctx.CreateIterator5(
        nodeAddr, ScType::ConstCommonArc, ScType::ConstNode,
        ScType::ConstPermPosArc, LogisticsKeynodes::nrel_warehouse);

    while (whIt->Next())
    {
      ScAddr warehouseAddr = whIt->Get(2);
      WarehouseCoord wh = {0, 0};

      ScIterator5Ptr xIt = ctx.CreateIterator5(
          warehouseAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
          ScType::ConstPermPosArc, LogisticsKeynodes::nrel_x);
      if (xIt->Next())
      {
        std::string xStr;
        ctx.GetLinkContent(xIt->Get(2), xStr);
        wh.x = std::stod(xStr);
      }

      ScIterator5Ptr yIt = ctx.CreateIterator5(
          warehouseAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
          ScType::ConstPermPosArc, LogisticsKeynodes::nrel_y);
      if (yIt->Next())
      {
        std::string yStr;
        ctx.GetLinkContent(yIt->Get(2), yStr);
        wh.y = std::stod(yStr);
      }

      coords.push_back(wh);
    }
  }
  return coords;
}

// Тест 1: Кластеризация с K=1 (один склад - взвешенный центроид)
TEST_F(ClusteringAgentTest, Clustering_K1_SingleWarehouse)
{
  std::cout << "\n=== ТЕСТ: ClusteringAgent - K=1 (один склад) ===" << std::endl;
  std::cout << "Входные данные (5 магазинов):" << std::endl;
  std::cout << "  ID=1: x=10, y=15, volume=200 т/мес" << std::endl;
  std::cout << "  ID=2: x=25, y=30, volume=350 т/мес" << std::endl;
  std::cout << "  ID=3: x=45, y=20, volume=180 т/мес" << std::endl;
  std::cout << "  ID=4: x=35, y=45, volume=280 т/мес" << std::endl;
  std::cout << "  ID=5: x=55, y=35, volume=320 т/мес" << std::endl;

  // Рассчитываем ожидаемые координаты (взвешенный центроид)
  std::vector<ShopData> shops = {
    {1, "", 10, 15, 200}, {2, "", 25, 30, 350}, {3, "", 45, 20, 180},
    {4, "", 35, 45, 280}, {5, "", 55, 35, 320}
  };
  auto expected = GeometryUtils::KMeansClustering(shops, 1);
  std::cout << "Ожидаемый результат: склад в точке (" 
            << std::fixed << std::setprecision(2) 
            << expected[0].position.x << ", " << expected[0].position.y << ")" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "1");
  action.SetArguments(networkAddr, kLink);

  std::cout << "Запуск агента кластеризации с K=1..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  ASSERT_TRUE(action.IsFinishedSuccessfully());

  auto coords = ExtractWarehouses(*m_ctx, action.GetResult());
  ASSERT_EQ(coords.size(), 1u);

  std::cout << "Результат: склад в точке (" 
            << std::fixed << std::setprecision(2) 
            << coords[0].x << ", " << coords[0].y << ")" << std::endl;

  EXPECT_NEAR(coords[0].x, expected[0].position.x, 0.1);
  EXPECT_NEAR(coords[0].y, expected[0].position.y, 0.1);

  std::cout << "ТЕСТ ПРОЙДЕН: координаты склада корректны" << std::endl;
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 2: Кластеризация с K=2 (два склада)
TEST_F(ClusteringAgentTest, Clustering_K2_TwoWarehouses)
{
  std::cout << "\n=== ТЕСТ: ClusteringAgent - K=2 (два склада) ===" << std::endl;
  std::cout << "Входные данные: 5 магазинов" << std::endl;
  std::cout << "Ожидается: 2 склада в пределах области магазинов [10-55, 15-45]" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "2");
  action.SetArguments(networkAddr, kLink);

  std::cout << "Запуск агента кластеризации с K=2..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  ASSERT_TRUE(action.IsFinishedSuccessfully());

  auto coords = ExtractWarehouses(*m_ctx, action.GetResult());
  ASSERT_EQ(coords.size(), 2u);

  std::cout << "Результат:" << std::endl;
  for (size_t i = 0; i < coords.size(); i++)
  {
    std::cout << "  Склад " << i+1 << ": (" 
              << std::fixed << std::setprecision(2) 
              << coords[i].x << ", " << coords[i].y << ")" << std::endl;
    EXPECT_GE(coords[i].x, 10.0);
    EXPECT_LE(coords[i].x, 55.0);
    EXPECT_GE(coords[i].y, 15.0);
    EXPECT_LE(coords[i].y, 45.0);
  }

  // Проверяем что склады разнесены
  double dist = std::sqrt(std::pow(coords[0].x - coords[1].x, 2) + std::pow(coords[0].y - coords[1].y, 2));
  std::cout << "Расстояние между складами: " << dist << std::endl;
  EXPECT_GT(dist, 5.0);

  std::cout << "ТЕСТ ПРОЙДЕН: 2 склада созданы корректно" << std::endl;
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 3: Кластеризация с K=3 (три склада)
TEST_F(ClusteringAgentTest, Clustering_K3_ThreeWarehouses)
{
  std::cout << "\n=== ТЕСТ: ClusteringAgent - K=3 (три склада) ===" << std::endl;
  std::cout << "Входные данные: 5 магазинов" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "3");
  action.SetArguments(networkAddr, kLink);

  std::cout << "Запуск агента кластеризации с K=3..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  ASSERT_TRUE(action.IsFinishedSuccessfully());

  auto coords = ExtractWarehouses(*m_ctx, action.GetResult());
  ASSERT_EQ(coords.size(), 3u);

  std::cout << "Результат:" << std::endl;
  for (size_t i = 0; i < coords.size(); i++)
  {
    std::cout << "  Склад " << i+1 << ": (" 
              << std::fixed << std::setprecision(2) 
              << coords[i].x << ", " << coords[i].y << ")" << std::endl;
  }

  std::cout << "ТЕСТ ПРОЙДЕН: 3 склада созданы" << std::endl;
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 4: Ошибка - невалидное K=0
TEST_F(ClusteringAgentTest, Error_InvalidK_Zero)
{
  std::cout << "\n=== ТЕСТ: ClusteringAgent - ошибка K=0 ===" << std::endl;
  std::cout << "Входные данные: K=0 (невалидное значение)" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "0");
  action.SetArguments(networkAddr, kLink);

  std::cout << "Запуск агента с K=0..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  EXPECT_TRUE(action.IsFinishedWithError());

  std::cout << "ТЕСТ ПРОЙДЕН: агент корректно вернул ошибку" << std::endl;
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 5: Ошибка - K больше количества магазинов
TEST_F(ClusteringAgentTest, Error_K_MoreThanShops)
{
  std::cout << "\n=== ТЕСТ: ClusteringAgent - ошибка K > количества магазинов ===" << std::endl;
  std::cout << "Входные данные: 2 магазина, K=5" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "5");
  action.SetArguments(networkAddr, kLink);

  std::cout << "Запуск агента с K=5 при 2 магазинах..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  EXPECT_TRUE(action.IsFinishedWithError());

  std::cout << "ТЕСТ ПРОЙДЕН: агент корректно вернул ошибку" << std::endl;
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}
