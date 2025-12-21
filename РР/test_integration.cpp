/*
 * Интеграционные тесты модуля логистики
 * Проверка полной цепочки агентов: Validation -> Clustering -> Cost -> Comparison
 */

#include <sc-memory/test/sc_test.hpp>
#include <sc-memory/sc_memory.hpp>
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "agents/DataValidationAgent.hpp"
#include "agents/ClusteringAgent.hpp"
#include "agents/CostCalculationAgent.hpp"
#include "agents/VariantComparisonAgent.hpp"
#include "keynodes/LogisticsKeynodes.hpp"

using IntegrationTest = ScMemoryTest;

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

static double ExtractCost(ScAgentContext & ctx, ScAddr variantAddr)
{
  ScIterator5Ptr costIter = ctx.CreateIterator5(
      variantAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
      ScType::ConstPermPosArc, LogisticsKeynodes::nrel_monthly_cost);
  if (costIter->Next())
  {
    std::string costStr;
    ctx.GetLinkContent(costIter->Get(2), costStr);
    return std::stod(costStr);
  }
  return -1.0;
}

static int CountWarehouses(ScAgentContext & ctx, ScAddr variantAddr)
{
  int count = 0;
  ScIterator5Ptr iter = ctx.CreateIterator5(
      variantAddr, ScType::ConstCommonArc, ScType::ConstNode,
      ScType::ConstPermPosArc, LogisticsKeynodes::nrel_warehouse);
  while (iter->Next()) count++;
  return count;
}

// Интеграционный тест: полный пайплайн с 5 магазинами
TEST_F(IntegrationTest, FullPipeline_SmallData)
{
  std::cout << "\n========================================" << std::endl;
  std::cout << "ИНТЕГРАЦИОННЫЙ ТЕСТ: Полный пайплайн" << std::endl;
  std::cout << "========================================" << std::endl;
  
  std::cout << "\nВходные данные (5 магазинов):" << std::endl;
  std::cout << "  ID | X  | Y  | Volume (т/мес)" << std::endl;
  std::cout << "  ---|----|----|---------------" << std::endl;
  std::cout << "   1 | 10 | 15 | 200" << std::endl;
  std::cout << "   2 | 25 | 30 | 350" << std::endl;
  std::cout << "   3 | 45 | 20 | 180" << std::endl;
  std::cout << "   4 | 35 | 45 | 280" << std::endl;
  std::cout << "   5 | 55 | 35 | 320" << std::endl;

  // Подписываем все агенты
  m_ctx->SubscribeAgent<DataValidationAgent>();
  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();
  m_ctx->SubscribeAgent<VariantComparisonAgent>();

  // Создаём данные
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  // ШАГ 1: Валидация
  std::cout << "\n[ШАГ 1] DataValidationAgent - проверка данных..." << std::endl;
  {
    ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_validate_data);
    action.SetArguments(networkAddr);
    ASSERT_TRUE(action.InitiateAndWait(10000));
    ASSERT_TRUE(action.IsFinishedSuccessfully());
    std::cout << "  Результат: данные корректны" << std::endl;
  }

  // ШАГ 2-4: Кластеризация для K=1,2,3
  std::vector<ScAddr> variants(3);
  double costs[3] = {0, 0, 0};

  for (int k = 1; k <= 3; k++)
  {
    std::cout << "\n[ШАГ " << k+1 << "] ClusteringAgent K=" << k << "..." << std::endl;
    
    ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
    ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
    m_ctx->SetLinkContent(kLink, std::to_string(k));
    clusterAction.SetArguments(networkAddr, kLink);
    ASSERT_TRUE(clusterAction.InitiateAndWait(10000));
    ASSERT_TRUE(clusterAction.IsFinishedSuccessfully());

    variants[k-1] = ExtractVariant(*m_ctx, clusterAction.GetResult());
    ASSERT_TRUE(variants[k-1].IsValid());
    
    int whCount = CountWarehouses(*m_ctx, variants[k-1]);
    std::cout << "  Результат: создано " << whCount << " складов" << std::endl;
    EXPECT_EQ(whCount, k);

    // Расчёт стоимости
    std::cout << "  CostCalculationAgent - расчёт затрат..." << std::endl;
    ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
    costAction.SetArguments(variants[k-1], networkAddr);
    ASSERT_TRUE(costAction.InitiateAndWait(10000));
    ASSERT_TRUE(costAction.IsFinishedSuccessfully());

    costs[k-1] = ExtractCost(*m_ctx, variants[k-1]);
    std::cout << "  Результат: " << std::fixed << std::setprecision(0) 
              << costs[k-1] << " руб/мес" << std::endl;
    EXPECT_GT(costs[k-1], 0.0);
  }

  // ШАГ 5: Сравнение вариантов
  std::cout << "\n[ШАГ 5] VariantComparisonAgent - выбор лучшего варианта..." << std::endl;
  ScAddr bestVariantAddr;
  {
    ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_compare_variants);
    action.SetArguments(variants[0], variants[1], variants[2]);
    ASSERT_TRUE(action.InitiateAndWait(10000));
    ASSERT_TRUE(action.IsFinishedSuccessfully());

    ScStructure result = action.GetResult();
    ScIterator3Ptr iter = m_ctx->CreateIterator3(result, ScType::ConstPermPosArc, ScType::ConstNode);
    while (iter->Next())
    {
      ScAddr nodeAddr = iter->Get(2);
      ScIterator5Ptr recIter = m_ctx->CreateIterator5(
          nodeAddr, ScType::ConstCommonArc, ScType::ConstNode,
          ScType::ConstPermPosArc, LogisticsKeynodes::nrel_recommendation);
      if (recIter->Next())
      {
        bestVariantAddr = recIter->Get(2);
        break;
      }
    }
    ASSERT_TRUE(bestVariantAddr.IsValid());
  }

  // Определяем какой вариант лучший
  int bestK = 0;
  for (int k = 1; k <= 3; k++)
  {
    if (variants[k-1] == bestVariantAddr)
    {
      bestK = k;
      break;
    }
  }
  std::cout << "  Результат: рекомендован вариант с " << bestK << " складами" << std::endl;

  // Итоговая таблица
  std::cout << "\n========================================" << std::endl;
  std::cout << "ИТОГОВЫЕ РЕЗУЛЬТАТЫ:" << std::endl;
  std::cout << "========================================" << std::endl;
  std::cout << "  Вариант | Складов | Затраты (руб/мес)" << std::endl;
  std::cout << "  --------|---------|------------------" << std::endl;
  for (int k = 1; k <= 3; k++)
  {
    std::string mark = (k == bestK) ? " <-- ЛУЧШИЙ" : "";
    std::cout << "     K=" << k << "  |    " << k << "    | " 
              << std::fixed << std::setprecision(0) << std::setw(10) << costs[k-1] 
              << mark << std::endl;
  }

  // КЛЮЧЕВАЯ ПРОВЕРКА ЗАДАЧИ: больше складов = меньше затрат
  std::cout << "\n[ПРОВЕРКА ГЛАВНОГО ТРЕБОВАНИЯ ЗАДАЧИ]" << std::endl;
  std::cout << "  Затраты должны уменьшаться с увеличением количества складов" << std::endl;
  EXPECT_GE(costs[0], costs[1]) << "cost(K=1) должен быть >= cost(K=2)";
  EXPECT_GE(costs[1], costs[2]) << "cost(K=2) должен быть >= cost(K=3)";
  std::cout << "  ПРОВЕРКА ПРОЙДЕНА: cost(K=1) >= cost(K=2) >= cost(K=3)" << std::endl;

  // Проверка что выбран вариант с минимальной стоимостью
  double minCost = std::min({costs[0], costs[1], costs[2]});
  double bestCost = costs[bestK - 1];
  EXPECT_NEAR(bestCost, minCost, 1.0) << "Должен быть выбран вариант с минимальными затратами";

  std::cout << "\nТЕСТ ПРОЙДЕН: полный пайплайн работает корректно" << std::endl;

  m_ctx->UnsubscribeAgent<VariantComparisonAgent>();
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
  m_ctx->UnsubscribeAgent<DataValidationAgent>();
}

// Интеграционный тест с 15 магазинами
TEST_F(IntegrationTest, FullPipeline_FullData)
{
  std::cout << "\n========================================" << std::endl;
  std::cout << "ИНТЕГРАЦИОННЫЙ ТЕСТ: 15 магазинов" << std::endl;
  std::cout << "========================================" << std::endl;

  m_ctx->SubscribeAgent<DataValidationAgent>();
  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();
  m_ctx->SubscribeAgent<VariantComparisonAgent>();

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

  std::cout << "Входные данные: 15 магазинов" << std::endl;

  // Валидация
  {
    ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_validate_data);
    action.SetArguments(networkAddr);
    ASSERT_TRUE(action.InitiateAndWait(10000));
    ASSERT_TRUE(action.IsFinishedSuccessfully());
  }

  // Кластеризация и расчёт для K=1,2,3
  std::vector<ScAddr> variants(3);
  double costs[3];

  for (int k = 1; k <= 3; k++)
  {
    ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
    ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
    m_ctx->SetLinkContent(kLink, std::to_string(k));
    clusterAction.SetArguments(networkAddr, kLink);
    ASSERT_TRUE(clusterAction.InitiateAndWait(15000));
    ASSERT_TRUE(clusterAction.IsFinishedSuccessfully());

    variants[k-1] = ExtractVariant(*m_ctx, clusterAction.GetResult());
    ASSERT_TRUE(variants[k-1].IsValid());
    EXPECT_EQ(CountWarehouses(*m_ctx, variants[k-1]), k);

    ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
    costAction.SetArguments(variants[k-1], networkAddr);
    ASSERT_TRUE(costAction.InitiateAndWait(10000));
    ASSERT_TRUE(costAction.IsFinishedSuccessfully());

    costs[k-1] = ExtractCost(*m_ctx, variants[k-1]);
    EXPECT_GT(costs[k-1], 0.0);
  }

  // Сравнение
  ScAction compareAction = m_ctx->GenerateAction(LogisticsKeynodes::action_compare_variants);
  compareAction.SetArguments(variants[0], variants[1], variants[2]);
  ASSERT_TRUE(compareAction.InitiateAndWait(10000));
  ASSERT_TRUE(compareAction.IsFinishedSuccessfully());

  std::cout << "\nРезультаты:" << std::endl;
  for (int k = 1; k <= 3; k++)
  {
    std::cout << "  K=" << k << ": " << std::fixed << std::setprecision(0) 
              << costs[k-1] << " руб/мес" << std::endl;
  }

  std::cout << "\nТЕСТ ПРОЙДЕН" << std::endl;

  m_ctx->UnsubscribeAgent<VariantComparisonAgent>();
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
  m_ctx->UnsubscribeAgent<DataValidationAgent>();
}
