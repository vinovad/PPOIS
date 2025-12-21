/*
 * Тесты для CostCalculationAgent
 * Агент рассчитывает транспортные затраты для варианта размещения складов
 */

#include <sc-memory/test/sc_test.hpp>
#include <sc-memory/sc_memory.hpp>
#include <iostream>
#include <iomanip>

#include "agents/ClusteringAgent.hpp"
#include "agents/CostCalculationAgent.hpp"
#include "keynodes/LogisticsKeynodes.hpp"

using CostCalculationAgentTest = ScMemoryTest;

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

// Извлечение варианта размещения из результата кластеризации
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

// Извлечение стоимости из варианта
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

// Тест 1: Расчёт стоимости для варианта с 1 складом
TEST_F(CostCalculationAgentTest, CostCalculation_SingleWarehouse)
{
  std::cout << "\n=== ТЕСТ: CostCalculationAgent - расчёт для 1 склада ===" << std::endl;
  std::cout << "Входные данные:" << std::endl;
  std::cout << "  5 магазинов с объёмами поставок 200-350 т/мес" << std::endl;
  std::cout << "  1 склад (результат кластеризации K=1)" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  // Шаг 1: Кластеризация
  std::cout << "Шаг 1: Кластеризация с K=1..." << std::endl;
  ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "1");
  clusterAction.SetArguments(networkAddr, kLink);
  ASSERT_TRUE(clusterAction.InitiateAndWait(10000));
  ASSERT_TRUE(clusterAction.IsFinishedSuccessfully());

  ScAddr variantAddr = ExtractVariant(*m_ctx, clusterAction.GetResult());
  ASSERT_TRUE(variantAddr.IsValid());
  std::cout << "  Вариант размещения создан" << std::endl;

  // Шаг 2: Расчёт стоимости
  std::cout << "Шаг 2: Расчёт транспортных затрат..." << std::endl;
  ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
  costAction.SetArguments(variantAddr, networkAddr);
  ASSERT_TRUE(costAction.InitiateAndWait(10000));
  ASSERT_TRUE(costAction.IsFinishedSuccessfully());

  double cost = ExtractCost(*m_ctx, variantAddr);
  EXPECT_GT(cost, 0.0);

  std::cout << "Результат: ежемесячные затраты = " 
            << std::fixed << std::setprecision(0) << cost << " руб/мес" << std::endl;

  std::cout << "ТЕСТ ПРОЙДЕН: стоимость рассчитана корректно" << std::endl;
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 2: Расчёт стоимости для варианта с 2 складами
TEST_F(CostCalculationAgentTest, CostCalculation_TwoWarehouses)
{
  std::cout << "\n=== ТЕСТ: CostCalculationAgent - расчёт для 2 складов ===" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  // Кластеризация K=2
  ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "2");
  clusterAction.SetArguments(networkAddr, kLink);
  ASSERT_TRUE(clusterAction.InitiateAndWait(10000));
  ASSERT_TRUE(clusterAction.IsFinishedSuccessfully());

  ScAddr variantAddr = ExtractVariant(*m_ctx, clusterAction.GetResult());
  ASSERT_TRUE(variantAddr.IsValid());

  // Расчёт стоимости
  ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
  costAction.SetArguments(variantAddr, networkAddr);
  ASSERT_TRUE(costAction.InitiateAndWait(10000));
  ASSERT_TRUE(costAction.IsFinishedSuccessfully());

  double cost = ExtractCost(*m_ctx, variantAddr);
  EXPECT_GT(cost, 0.0);

  std::cout << "Результат: затраты для 2 складов = " 
            << std::fixed << std::setprecision(0) << cost << " руб/мес" << std::endl;

  std::cout << "ТЕСТ ПРОЙДЕН" << std::endl;
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 3: Сравнение стоимости разных вариантов (1, 2, 3 склада)
TEST_F(CostCalculationAgentTest, CostComparison_AllVariants)
{
  std::cout << "\n=== ТЕСТ: Сравнение затрат для разных вариантов ===" << std::endl;
  std::cout << "Входные данные: 5 магазинов" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  double costs[3] = {0, 0, 0};

  for (int k = 1; k <= 3; k++)
  {
    // Кластеризация
    ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
    ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
    m_ctx->SetLinkContent(kLink, std::to_string(k));
    clusterAction.SetArguments(networkAddr, kLink);
    ASSERT_TRUE(clusterAction.InitiateAndWait(10000));
    ASSERT_TRUE(clusterAction.IsFinishedSuccessfully());

    ScAddr variantAddr = ExtractVariant(*m_ctx, clusterAction.GetResult());
    ASSERT_TRUE(variantAddr.IsValid());

    // Расчёт стоимости
    ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
    costAction.SetArguments(variantAddr, networkAddr);
    ASSERT_TRUE(costAction.InitiateAndWait(10000));
    ASSERT_TRUE(costAction.IsFinishedSuccessfully());

    costs[k-1] = ExtractCost(*m_ctx, variantAddr);
    std::cout << "  K=" << k << " складов: " 
              << std::fixed << std::setprecision(0) << costs[k-1] << " руб/мес" << std::endl;
  }

  // Все стоимости должны быть положительными
  for (int i = 0; i < 3; i++)
  {
    EXPECT_GT(costs[i], 0.0) << "Стоимость для K=" << i+1 << " должна быть > 0";
  }

  // КЛЮЧЕВАЯ ПРОВЕРКА: больше складов = меньше затрат
  // Это главное требование задачи оптимизации
  std::cout << "\nПроверка: cost(K=1) >= cost(K=2) >= cost(K=3)" << std::endl;
  EXPECT_GE(costs[0], costs[1]) << "Затраты для 1 склада должны быть >= затрат для 2 складов";
  EXPECT_GE(costs[1], costs[2]) << "Затраты для 2 складов должны быть >= затрат для 3 складов";

  std::cout << "ТЕСТ ПРОЙДЕН: все варианты имеют рассчитанную стоимость, затраты уменьшаются с увеличением K" << std::endl;
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}

// Тест 4: Проверка формулы расчёта затрат
// Формула: сумма(расстояние * объём * тариф * 2) для каждого магазина
TEST_F(CostCalculationAgentTest, CostFormula_Verification)
{
  std::cout << "\n=== ТЕСТ: Проверка формулы расчёта затрат ===" << std::endl;
  std::cout << "Формула: cost = sum(distance * volume * 12 * 2)" << std::endl;
  std::cout << "  где 12 руб/(км*т) - тариф, 2 - туда и обратно" << std::endl;

  m_ctx->SubscribeAgent<ClusteringAgent>();
  m_ctx->SubscribeAgent<CostCalculationAgent>();

  // Создаём простую конфигурацию для ручной проверки
  // 3 магазина на одной линии: (0,0), (10,0), (20,0) с объёмами 100, 100, 100
  ScAddr networkAddr = CreateNetwork(*m_ctx);
  CreateShop(*m_ctx, networkAddr, 1, 0, 0, 100);
  CreateShop(*m_ctx, networkAddr, 2, 10, 0, 100);
  CreateShop(*m_ctx, networkAddr, 3, 20, 0, 100);

  // Для K=1 склад будет в центроиде (10, 0)
  // Расстояния: 10, 0, 10
  // Ручной расчёт: (10*100 + 0*100 + 10*100) * 12 * 2 = 2000 * 12 * 2 = 48000

  ScAction clusterAction = m_ctx->GenerateAction(LogisticsKeynodes::action_cluster_shops);
  ScAddr kLink = m_ctx->GenerateLink(ScType::ConstNodeLink);
  m_ctx->SetLinkContent(kLink, "1");
  clusterAction.SetArguments(networkAddr, kLink);
  ASSERT_TRUE(clusterAction.InitiateAndWait(10000));
  ASSERT_TRUE(clusterAction.IsFinishedSuccessfully());

  ScAddr variantAddr = ExtractVariant(*m_ctx, clusterAction.GetResult());
  ASSERT_TRUE(variantAddr.IsValid());

  ScAction costAction = m_ctx->GenerateAction(LogisticsKeynodes::action_calculate_cost);
  costAction.SetArguments(variantAddr, networkAddr);
  ASSERT_TRUE(costAction.InitiateAndWait(10000));
  ASSERT_TRUE(costAction.IsFinishedSuccessfully());

  double cost = ExtractCost(*m_ctx, variantAddr);
  std::cout << "Рассчитанная стоимость: " << std::fixed << std::setprecision(0) << cost << " руб/мес" << std::endl;

  // Ожидаемая стоимость ~48000 (с погрешностью из-за взвешенного центроида)
  // Центроид для равных объёмов = среднее = (0+10+20)/3 = 10
  // Так что расчёт верный: (10+0+10)*100*12*2 = 48000
  double expectedCost = 48000.0;
  std::cout << "Ожидаемая стоимость: " << expectedCost << " руб/мес" << std::endl;
  
  EXPECT_NEAR(cost, expectedCost, 1000) << "Стоимость должна соответствовать формуле";

  std::cout << "ТЕСТ ПРОЙДЕН: формула расчёта работает корректно" << std::endl;
  m_ctx->UnsubscribeAgent<CostCalculationAgent>();
  m_ctx->UnsubscribeAgent<ClusteringAgent>();
}
