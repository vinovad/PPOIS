/*
 * Тесты для VariantComparisonAgent
 * Агент сравнивает варианты размещения складов и выбирает лучший
 */

#include <sc-memory/test/sc_test.hpp>
#include <sc-memory/sc_memory.hpp>
#include <iostream>
#include <iomanip>

#include "agents/ClusteringAgent.hpp"
#include "agents/CostCalculationAgent.hpp"
#include "agents/VariantComparisonAgent.hpp"
#include "keynodes/LogisticsKeynodes.hpp"

using VariantComparisonAgentTest = ScMemoryTest;

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

static double ExtractEconomy(ScAgentContext & ctx, ScAddr variantAddr)
{
  ScIterator5Ptr iter = ctx.CreateIterator5(
      variantAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
      ScType::ConstPermPosArc, LogisticsKeynodes::nrel_economy_percent);
  if (iter->Next())
  {
    std::string str;
    ctx.GetLinkContent(iter->Get(2), str);
    return std::stod(str);
  }
  return 0.0;
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

// Тест 1: Сравнение трёх вариантов и выбор лучшего
TEST_F(VariantComparisonAgentTest, CompareThreeVariants_SelectBest)
{
  std::cout << "\n=== ТЕСТ: VariantComparisonAgent - сравнение 3 вариантов ===" << std::endl;
  std::cout << "Входные данные:" << std::endl;
  std::cout << "  5 магазинов, 3 варианта размещения (K=1, K=2, K=3)" << std::endl;
  std::cout << "Ожидаемый результат: выбран вариант с минимальными затратами" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();
  m_ctx->SubscribeAgent<VariantComparisonAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  // Создаём 3 варианта
  std::vector<ScAddr> variants(3);
  double costs[3];

  for (int k = 1; k <= 3; k++)
  {
    ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
    ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
    m_ctx->SetLinkContent(kLink, std::to_string(k));
    clusterAction.SetArguments(networkAddr, kLink);
    ASSERT_TRUE(clusterAction.InitiateAndWait(10000));
    ASSERT_TRUE(clusterAction.IsFinishedSuccessfully());
    variants[k-1] = ExtractVariant(*m_ctx, clusterAction.GetResult());
    ASSERT_TRUE(variants[k-1].IsValid());

    ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
    costAction.SetArguments(variants[k-1], networkAddr);
    ASSERT_TRUE(costAction.InitiateAndWait(10000));
    ASSERT_TRUE(costAction.IsFinishedSuccessfully());
    costs[k-1] = ExtractCost(*m_ctx, variants[k-1]);
  }

  std::cout << "Затраты до сравнения:" << std::endl;
  for (int k = 1; k <= 3; k++)
    std::cout << "  K=" << k << ": " << std::fixed << std::setprecision(0) << costs[k-1] << " руб/мес" << std::endl;

  // Вызываем агент сравнения
  std::cout << "Запуск VariantComparisonAgent..." << std::endl;
  ScAction compareAction = m_ctx->GenerateAction(LogisticsKeynodes::action_compare_variants);
  compareAction.SetArguments(variants[0], variants[1], variants[2]);
  ASSERT_TRUE(compareAction.InitiateAndWait(10000));
  ASSERT_TRUE(compareAction.IsFinishedSuccessfully());

  // Проверяем результат
  ScAddr bestVariant = ExtractBestVariant(*m_ctx, compareAction.GetResult());
  ASSERT_TRUE(bestVariant.IsValid()) << "Лучший вариант не найден в результате";

  // Определяем какой K у лучшего варианта
  int bestK = 0;
  double minCost = costs[0];
  for (int k = 1; k <= 3; k++)
  {
    if (variants[k-1] == bestVariant) bestK = k;
    if (costs[k-1] < minCost) minCost = costs[k-1];
  }

  std::cout << "Результат: лучший вариант K=" << bestK << std::endl;
  
  // Проверяем что выбран вариант с минимальной стоимостью
  double bestCost = ExtractCost(*m_ctx, bestVariant);
  EXPECT_NEAR(bestCost, minCost, 1.0) << "Выбран не самый дешёвый вариант";

  // Проверяем что добавлена экономия
  double economy2 = ExtractEconomy(*m_ctx, variants[1]);
  double economy3 = ExtractEconomy(*m_ctx, variants[2]);
  std::cout << "Экономия K=2: " << std::fixed << std::setprecision(1) << economy2 << "%" << std::endl;
  std::cout << "Экономия K=3: " << std::fixed << std::setprecision(1) << economy3 << "%" << std::endl;

  EXPECT_GT(economy2, 0.0) << "Экономия K=2 должна быть > 0";
  EXPECT_GT(economy3, economy2) << "Экономия K=3 должна быть больше K=2";

  std::cout << "ТЕСТ ПРОЙДЕН: агент корректно сравнил варианты" << std::endl;

  m_ctx->UnsubscribeAgent<VariantComparisonAgent>();
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 2: Проверка расчёта экономии
TEST_F(VariantComparisonAgentTest, EconomyCalculation)
{
  std::cout << "\n=== ТЕСТ: VariantComparisonAgent - расчёт экономии ===" << std::endl;
  std::cout << "Проверяем формулу: economy = 100 * (1 - cost_k / cost_1)" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();
  m_ctx->SubscribeAgent<VariantComparisonAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  std::vector<ScAddr> variants(3);
  double costs[3];

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
    costs[k-1] = ExtractCost(*m_ctx, variants[k-1]);
  }

  // Сравнение
  ScAction compareAction = m_ctx->GenerateAction(LogisticsKeynodes::action_compare_variants);
  compareAction.SetArguments(variants[0], variants[1], variants[2]);
  ASSERT_TRUE(compareAction.InitiateAndWait(10000));
  ASSERT_TRUE(compareAction.IsFinishedSuccessfully());

  // Проверяем расчёт экономии
  double expectedEconomy2 = 100.0 * (1.0 - costs[1] / costs[0]);
  double expectedEconomy3 = 100.0 * (1.0 - costs[2] / costs[0]);

  double actualEconomy1 = ExtractEconomy(*m_ctx, variants[0]);
  double actualEconomy2 = ExtractEconomy(*m_ctx, variants[1]);
  double actualEconomy3 = ExtractEconomy(*m_ctx, variants[2]);

  std::cout << "K=1: экономия = " << actualEconomy1 << "% (ожидается 0%)" << std::endl;
  std::cout << "K=2: экономия = " << actualEconomy2 << "% (ожидается " << expectedEconomy2 << "%)" << std::endl;
  std::cout << "K=3: экономия = " << actualEconomy3 << "% (ожидается " << expectedEconomy3 << "%)" << std::endl;

  EXPECT_NEAR(actualEconomy1, 0.0, 0.1);
  EXPECT_NEAR(actualEconomy2, expectedEconomy2, 0.5);
  EXPECT_NEAR(actualEconomy3, expectedEconomy3, 0.5);

  std::cout << "ТЕСТ ПРОЙДЕН: экономия рассчитана корректно" << std::endl;

  m_ctx->UnsubscribeAgent<VariantComparisonAgent>();
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}
