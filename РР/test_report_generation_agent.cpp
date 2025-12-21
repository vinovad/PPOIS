/*
 * Тесты для ReportGenerationAgent
 * Агент формирует итоговый отчёт по оптимизации размещения складов
 */

#include <sc-memory/test/sc_test.hpp>
#include <sc-memory/sc_memory.hpp>
#include <iostream>
#include <iomanip>

#include "agents/ClusteringAgent.hpp"
#include "agents/CostCalculationAgent.hpp"
#include "agents/VariantComparisonAgent.hpp"
#include "agents/ReportGenerationAgent.hpp"
#include "keynodes/LogisticsKeynodes.hpp"

using ReportGenerationAgentTest = ScMemoryTest;

// Вспомогательные функции
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

static ScAddr ExtractVariant(ScAgentContext & ctx, ScStructure const & result)
{
  ScIterator3Ptr iter = ctx.CreateIterator3(result, ScType::ConstPermPosArc, ScType::ConstNode);
  while (iter->Next())
  {
    ScAddr nodeAddr = iter->Get(2);
    if (ctx.CheckConnector(LogisticsKeynodes::concept_placement_variant, nodeAddr, ScType::ConstPermPosArc))
      return nodeAddr;
  }
  return ScAddr();
}

static ScAddr ExtractBestVariant(ScAgentContext & ctx, ScStructure const & result)
{
  ScIterator3Ptr iter = ctx.CreateIterator3(result, ScType::ConstPermPosArc, ScType::ConstNode);
  while (iter->Next())
  {
    ScAddr nodeAddr = iter->Get(2);
    ScIterator5Ptr recIter = ctx.CreateIterator5(
        nodeAddr, ScType::ConstCommonArc, ScType::ConstNode,
        ScType::ConstPermPosArc, LogisticsKeynodes::nrel_recommendation);
    if (recIter->Next())
      return recIter->Get(2);
  }
  return ScAddr();
}

// Извлечение отчёта из результата
static ScAddr ExtractReport(ScAgentContext & ctx, ScStructure const & result)
{
  ScIterator3Ptr iter = ctx.CreateIterator3(result, ScType::ConstPermPosArc, ScType::ConstNode);
  while (iter->Next())
  {
    ScAddr nodeAddr = iter->Get(2);
    if (ctx.CheckConnector(LogisticsKeynodes::concept_optimization_report, nodeAddr, ScType::ConstPermPosArc))
      return nodeAddr;
  }
  return ScAddr();
}

// Извлечение количества магазинов из отчёта
static int ExtractShopCount(ScAgentContext & ctx, ScAddr reportAddr)
{
  ScIterator5Ptr iter = ctx.CreateIterator5(
      reportAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
      ScType::ConstPermPosArc, LogisticsKeynodes::nrel_shop_count);
  if (iter->Next())
  {
    std::string str;
    ctx.GetLinkContent(iter->Get(2), str);
    return std::stoi(str);
  }
  return -1;
}

// Проверка наличия варианта в отчёте
static bool HasVariantInReport(ScAgentContext & ctx, ScAddr reportAddr, ScAddr variantAddr, ScAddr relationAddr)
{
  ScIterator5Ptr iter = ctx.CreateIterator5(
      reportAddr, ScType::ConstCommonArc, variantAddr,
      ScType::ConstPermPosArc, relationAddr);
  return iter->Next();
}

// Тест 1: Формирование отчёта с 5 магазинами
TEST_F(ReportGenerationAgentTest, GenerateReport_5Shops)
{
  std::cout << "\n=== ТЕСТ: ReportGenerationAgent - формирование отчёта ===" << std::endl;
  std::cout << "Входные данные:" << std::endl;
  std::cout << "  Торговая сеть: 5 магазинов" << std::endl;
  std::cout << "  3 варианта размещения (K=1, K=2, K=3)" << std::endl;
  std::cout << "  Лучший вариант (из VariantComparisonAgent)" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();
  m_ctx->SubscribeAgent<VariantComparisonAgent>();
  m_ctx->SubscribeAgent<ReportGenerationAgent>();

  // Создаём данные
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  // Создаём варианты
  std::vector<ScAddr> variants(3);
  for (int k = 1; k <= 3; k++)
  {
    ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
    ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
    m_ctx->SetLinkContent(kLink, std::to_string(k));
    clusterAction.SetArguments(networkAddr, kLink);
    ASSERT_TRUE(clusterAction.InitiateAndWait(10000));
    variants[k-1] = ExtractVariant(*m_ctx, clusterAction.GetResult());

    ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
    costAction.SetArguments(variants[k-1], networkAddr);
    ASSERT_TRUE(costAction.InitiateAndWait(10000));
  }

  // Сравниваем варианты
  ScAction compareAction = m_ctx->GenerateAction(LogisticsKeynodes::action_compare_variants);
  compareAction.SetArguments(variants[0], variants[1], variants[2]);
  ASSERT_TRUE(compareAction.InitiateAndWait(10000));
  ScAddr bestVariant = ExtractBestVariant(*m_ctx, compareAction.GetResult());
  ASSERT_TRUE(bestVariant.IsValid());

  // Генерируем отчёт
  std::cout << "Запуск ReportGenerationAgent..." << std::endl;
  ScAction reportAction = m_ctx->GenerateAction(LogisticsKeynodes::action_generate_report);
  reportAction.SetArguments(networkAddr, variants[0], variants[1], variants[2], bestVariant);
  ASSERT_TRUE(reportAction.InitiateAndWait(10000));
  ASSERT_TRUE(reportAction.IsFinishedSuccessfully());

  // Проверяем результат
  ScStructure result = reportAction.GetResult();
  EXPECT_FALSE(result.IsEmpty()) << "Результат не должен быть пустым";

  ScAddr reportAddr = ExtractReport(*m_ctx, result);
  ASSERT_TRUE(reportAddr.IsValid()) << "Отчёт не найден в результате";

  // Проверяем содержимое отчёта
  std::cout << "Проверка содержимого отчёта:" << std::endl;

  // 1. Количество магазинов
  int shopCount = ExtractShopCount(*m_ctx, reportAddr);
  std::cout << "  Количество магазинов: " << shopCount << std::endl;
  EXPECT_EQ(shopCount, 5) << "Должно быть 5 магазинов";

  // 2. Вариант 1 склад
  bool hasVar1 = HasVariantInReport(*m_ctx, reportAddr, variants[0], LogisticsKeynodes::nrel_single_warehouse_variant);
  std::cout << "  Вариант 1 склад: " << (hasVar1 ? "есть" : "нет") << std::endl;
  EXPECT_TRUE(hasVar1) << "Вариант K=1 должен быть в отчёте";

  // 3. Вариант 2 склада
  bool hasVar2 = HasVariantInReport(*m_ctx, reportAddr, variants[1], LogisticsKeynodes::nrel_two_warehouses_variant);
  std::cout << "  Вариант 2 склада: " << (hasVar2 ? "есть" : "нет") << std::endl;
  EXPECT_TRUE(hasVar2) << "Вариант K=2 должен быть в отчёте";

  // 4. Вариант 3 склада
  bool hasVar3 = HasVariantInReport(*m_ctx, reportAddr, variants[2], LogisticsKeynodes::nrel_three_warehouses_variant);
  std::cout << "  Вариант 3 склада: " << (hasVar3 ? "есть" : "нет") << std::endl;
  EXPECT_TRUE(hasVar3) << "Вариант K=3 должен быть в отчёте";

  // 5. Рекомендация
  bool hasRec = HasVariantInReport(*m_ctx, reportAddr, bestVariant, LogisticsKeynodes::nrel_recommendation);
  std::cout << "  Рекомендация: " << (hasRec ? "есть" : "нет") << std::endl;
  EXPECT_TRUE(hasRec) << "Рекомендация должна быть в отчёте";

  std::cout << "ТЕСТ ПРОЙДЕН: отчёт сформирован корректно" << std::endl;

  m_ctx->UnsubscribeAgent<ReportGenerationAgent>();
  m_ctx->UnsubscribeAgent<VariantComparisonAgent>();
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 2: Отчёт для 15 магазинов
TEST_F(ReportGenerationAgentTest, GenerateReport_15Shops)
{
  std::cout << "\n=== ТЕСТ: ReportGenerationAgent - отчёт для 15 магазинов ===" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();
  m_ctx->SubscribeAgent<VariantComparisonAgent>();
  m_ctx->SubscribeAgent<ReportGenerationAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);
  CreateShop(*m_ctx, networkAddr, 6, 12, 40, 150);
  CreateShop(*m_ctx, networkAddr, 7, 65, 25, 240);
  CreateShop(*m_ctx, networkAddr, 8, 30, 12, 190);
  CreateShop(*m_ctx, networkAddr, 9, 8, 25, 160);
  CreateShop(*m_ctx, networkAddr, 10, 48, 55, 220);
  CreateShop(*m_ctx, networkAddr, 11, 70, 40, 200);
  CreateShop(*m_ctx, networkAddr, 12, 18, 60, 130);
  CreateShop(*m_ctx, networkAddr, 13, 40, 8, 170);
  CreateShop(*m_ctx, networkAddr, 14, 22, 50, 210);
  CreateShop(*m_ctx, networkAddr, 15, 60, 15, 260);

  std::vector<ScAddr> variants(3);
  for (int k = 1; k <= 3; k++)
  {
    ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
    ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
    m_ctx->SetLinkContent(kLink, std::to_string(k));
    clusterAction.SetArguments(networkAddr, kLink);
    ASSERT_TRUE(clusterAction.InitiateAndWait(15000));
    variants[k-1] = ExtractVariant(*m_ctx, clusterAction.GetResult());

    ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
    costAction.SetArguments(variants[k-1], networkAddr);
    ASSERT_TRUE(costAction.InitiateAndWait(10000));
  }

  ScAction compareAction = m_ctx->GenerateAction(LogisticsKeynodes::action_compare_variants);
  compareAction.SetArguments(variants[0], variants[1], variants[2]);
  ASSERT_TRUE(compareAction.InitiateAndWait(10000));
  ScAddr bestVariant = ExtractBestVariant(*m_ctx, compareAction.GetResult());

  ScAction reportAction = m_ctx->GenerateAction(LogisticsKeynodes::action_generate_report);
  reportAction.SetArguments(networkAddr, variants[0], variants[1], variants[2], bestVariant);
  ASSERT_TRUE(reportAction.InitiateAndWait(10000));
  ASSERT_TRUE(reportAction.IsFinishedSuccessfully());

  ScAddr reportAddr = ExtractReport(*m_ctx, reportAction.GetResult());
  ASSERT_TRUE(reportAddr.IsValid());

  int shopCount = ExtractShopCount(*m_ctx, reportAddr);
  std::cout << "Количество магазинов в отчёте: " << shopCount << std::endl;
  EXPECT_EQ(shopCount, 15);

  std::cout << "ТЕСТ ПРОЙДЕН" << std::endl;

  m_ctx->UnsubscribeAgent<ReportGenerationAgent>();
  m_ctx->UnsubscribeAgent<VariantComparisonAgent>();
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}
