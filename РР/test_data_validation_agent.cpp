/*
 * Тесты для DataValidationAgent
 * Агент проверяет корректность входных данных торговой сети
 */

#include <sc-memory/test/sc_test.hpp>
#include <sc-memory/sc_memory.hpp>
#include <iostream>

#include "agents/DataValidationAgent.hpp"
#include "keynodes/LogisticsKeynodes.hpp"

using DataValidationAgentTest = ScMemoryTest;

// Вспомогательная функция для создания магазина
static ScAddr CreateShop(ScAgentContext & ctx, ScAddr networkAddr, int id, double x, double y, double volume)
{
  ScAddr shopAddr = ctx.GenerateNode(ScType::ConstNode);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::concept_shop, shopAddr);
  ctx.GenerateConnector(ScType::ConstPermPosArc, networkAddr, shopAddr);

  // ID
  ScAddr idLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(idLink, std::to_string(id));
  ScAddr idArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, idLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_id, idArc);

  // X
  ScAddr xLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(xLink, std::to_string(x));
  ScAddr xArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, xLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_x, xArc);

  // Y
  ScAddr yLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(yLink, std::to_string(y));
  ScAddr yArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, yLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_y, yArc);

  // Volume
  ScAddr volLink = ctx.GenerateLink(ScType::ConstNodeLink);
  ctx.SetLinkContent(volLink, std::to_string(volume));
  ScAddr volArc = ctx.GenerateConnector(ScType::ConstCommonArc, shopAddr, volLink);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_delivery_volume, volArc);

  return shopAddr;
}

// Создание торговой сети
static ScAddr CreateNetwork(ScAgentContext & ctx, std::string const & name)
{
  ScAddr networkAddr = ctx.GenerateNode(ScType::ConstNode);
  ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::concept_trading_network, networkAddr);
  return networkAddr;
}

// Тест 1: Валидация корректных данных (5 магазинов)
TEST_F(DataValidationAgentTest, ValidData_5Shops)
{
  std::cout << "\n=== ТЕСТ: DataValidationAgent - валидация корректных данных ===" << std::endl;
  std::cout << "Входные данные: торговая сеть с 5 магазинами" << std::endl;
  std::cout << "  Магазин 1: x=10, y=15, volume=200" << std::endl;
  std::cout << "  Магазин 2: x=25, y=30, volume=350" << std::endl;
  std::cout << "  Магазин 3: x=45, y=20, volume=180" << std::endl;
  std::cout << "  Магазин 4: x=35, y=45, volume=280" << std::endl;
  std::cout << "  Магазин 5: x=55, y=35, volume=320" << std::endl;

  m_ctx->SubscribeAgent<DataValidationAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx, "TestNetwork");
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);
  CreateShop(*m_ctx, networkAddr, 3, 45, 20, 180);
  CreateShop(*m_ctx, networkAddr, 4, 35, 45, 280);
  CreateShop(*m_ctx, networkAddr, 5, 55, 35, 320);

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_validate_data);
  action.SetArguments(networkAddr);

  std::cout << "Запуск агента валидации..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  ASSERT_TRUE(action.IsFinishedSuccessfully());

  // Проверяем результат
  ScStructure result = action.GetResult();
  EXPECT_FALSE(result.IsEmpty());

  // Извлекаем количество магазинов из результата
  ScIterator3Ptr iter = m_ctx->CreateIterator3(result, ScType::ConstPermPosArc, ScType::ConstNode);
  while (iter->Next())
  {
    ScAddr nodeAddr = iter->Get(2);
    ScIterator5Ptr countIter = m_ctx->CreateIterator5(
        nodeAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
        ScType::ConstPermPosArc, LogisticsKeynodes::nrel_shop_count);
    if (countIter->Next())
    {
      std::string countStr;
      m_ctx->GetLinkContent(countIter->Get(2), countStr);
      std::cout << "Результат: найдено магазинов = " << countStr << std::endl;
      EXPECT_EQ(countStr, "5");
    }
  }

  std::cout << "ТЕСТ ПРОЙДЕН: данные корректны" << std::endl;
  m_ctx->UnsubscribeAgent<DataValidationAgent>();
}

// Тест 2: Ошибка - недостаточно магазинов (меньше 3)
TEST_F(DataValidationAgentTest, InvalidData_TooFewShops)
{
  std::cout << "\n=== ТЕСТ: DataValidationAgent - недостаточно магазинов ===" << std::endl;
  std::cout << "Входные данные: торговая сеть с 2 магазинами (минимум 3)" << std::endl;

  m_ctx->SubscribeAgent<DataValidationAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx, "TestNetwork_TooFew");
  CreateShop(*m_ctx, networkAddr, 1, 10, 15, 200);
  CreateShop(*m_ctx, networkAddr, 2, 25, 30, 350);

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_validate_data);
  action.SetArguments(networkAddr);

  std::cout << "Запуск агента валидации..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  
  std::cout << "Результат: агент вернул ошибку (ожидаемо)" << std::endl;
  EXPECT_TRUE(action.IsFinishedWithError());

  std::cout << "ТЕСТ ПРОЙДЕН: корректно обработана ошибка" << std::endl;
  m_ctx->UnsubscribeAgent<DataValidationAgent>();
}

// Тест 3: Валидация большого набора данных (15 магазинов)
TEST_F(DataValidationAgentTest, ValidData_15Shops)
{
  std::cout << "\n=== ТЕСТ: DataValidationAgent - большой набор данных ===" << std::endl;
  std::cout << "Входные данные: торговая сеть с 15 магазинами" << std::endl;

  m_ctx->SubscribeAgent<DataValidationAgent>();

  ScAddr networkAddr = CreateNetwork(*m_ctx, "TestNetwork_Full");
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

  ScAction action = m_ctx->GenerateAction(LogisticsKeynodes::action_validate_data);
  action.SetArguments(networkAddr);

  std::cout << "Запуск агента валидации..." << std::endl;
  ASSERT_TRUE(action.InitiateAndWait(10000));
  ASSERT_TRUE(action.IsFinishedSuccessfully());

  ScStructure result = action.GetResult();
  ScIterator3Ptr iter = m_ctx->CreateIterator3(result, ScType::ConstPermPosArc, ScType::ConstNode);
  while (iter->Next())
  {
    ScAddr nodeAddr = iter->Get(2);
    ScIterator5Ptr countIter = m_ctx->CreateIterator5(
        nodeAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
        ScType::ConstPermPosArc, LogisticsKeynodes::nrel_shop_count);
    if (countIter->Next())
    {
      std::string countStr;
      m_ctx->GetLinkContent(countIter->Get(2), countStr);
      std::cout << "Результат: найдено магазинов = " << countStr << std::endl;
      EXPECT_EQ(countStr, "15");
    }
  }

  std::cout << "ТЕСТ ПРОЙДЕН" << std::endl;
  m_ctx->UnsubscribeAgent<DataValidationAgent>();
}
