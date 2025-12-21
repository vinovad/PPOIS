/*
 * Тесты для CsvParser
 * Проверка парсинга CSV файлов с данными о магазинах
 */

#include <gtest/gtest.h>
#include <iostream>
#include <filesystem>

#include "utils/CsvParser.hpp"

using namespace logistics;

static std::string GetTestDataPath(std::string const & filename)
{
  std::filesystem::path thisFile(__FILE__);
  std::filesystem::path testDir = thisFile.parent_path();
  std::filesystem::path dataPath = testDir / "test_data" / filename;
  return dataPath.string();
}

// Тест 1: Парсинг CSV с 5 магазинами
TEST(CsvParserTest, ParseFile_5Shops)
{
  std::cout << "\n=== ТЕСТ: CsvParser - парсинг shops_5.csv ===" << std::endl;
  
  std::string filePath = GetTestDataPath("shops_5.csv");
  std::cout << "Входные данные: " << filePath << std::endl;
  
  std::vector<ShopData> shops;
  std::string error;
  
  bool result = CsvParser::ParseShopsFile(filePath, shops, error);
  
  ASSERT_TRUE(result) << "Ошибка парсинга: " << error;
  EXPECT_EQ(shops.size(), 5) << "Должно быть 5 магазинов";
  
  std::cout << "Результат: загружено " << shops.size() << " магазинов" << std::endl;
  
  // Проверяем первый магазин (все поля включая name)
  ASSERT_GE(shops.size(), 1);
  EXPECT_EQ(shops[0].id, 1);
  EXPECT_FALSE(shops[0].name.empty()) << "Поле name должно быть заполнено";
  EXPECT_NEAR(shops[0].x, 10.0, 0.01);
  EXPECT_NEAR(shops[0].y, 15.0, 0.01);
  EXPECT_NEAR(shops[0].volume, 200.0, 0.01);
  
  std::cout << "  Магазин 1: name=" << shops[0].name << ", x=" << shops[0].x 
            << ", y=" << shops[0].y << ", volume=" << shops[0].volume << std::endl;
  
  // Проверяем последний магазин
  EXPECT_EQ(shops[4].id, 5);
  EXPECT_NEAR(shops[4].x, 55.0, 0.01);
  EXPECT_NEAR(shops[4].y, 35.0, 0.01);
  EXPECT_NEAR(shops[4].volume, 320.0, 0.01);
  
  std::cout << "  Магазин 5: x=" << shops[4].x << ", y=" << shops[4].y 
            << ", volume=" << shops[4].volume << std::endl;
  
  std::cout << "ТЕСТ ПРОЙДЕН: CSV файл распарсен корректно" << std::endl;
}

// Тест 2: Парсинг CSV с 15 магазинами
TEST(CsvParserTest, ParseFile_15Shops)
{
  std::cout << "\n=== ТЕСТ: CsvParser - парсинг shops_15.csv ===" << std::endl;
  
  std::string filePath = GetTestDataPath("shops_15.csv");
  
  std::vector<ShopData> shops;
  std::string error;
  
  bool result = CsvParser::ParseShopsFile(filePath, shops, error);
  
  ASSERT_TRUE(result) << "Ошибка парсинга: " << error;
  EXPECT_EQ(shops.size(), 15) << "Должно быть 15 магазинов";
  
  std::cout << "Результат: загружено " << shops.size() << " магазинов" << std::endl;
  
  // Проверяем что все магазины имеют корректные данные
  for (size_t i = 0; i < shops.size(); i++)
  {
    EXPECT_EQ(shops[i].id, static_cast<int>(i + 1));
    EXPECT_GT(shops[i].x, 0);
    EXPECT_GT(shops[i].y, 0);
    EXPECT_GT(shops[i].volume, 0);
  }
  
  std::cout << "ТЕСТ ПРОЙДЕН" << std::endl;
}

// Тест 3: Парсинг минимального набора (3 магазина)
TEST(CsvParserTest, ParseFile_3Shops)
{
  std::cout << "\n=== ТЕСТ: CsvParser - парсинг shops_3.csv ===" << std::endl;
  
  std::string filePath = GetTestDataPath("shops_3.csv");
  
  std::vector<ShopData> shops;
  std::string error;
  
  bool result = CsvParser::ParseShopsFile(filePath, shops, error);
  
  ASSERT_TRUE(result) << "Ошибка парсинга: " << error;
  EXPECT_EQ(shops.size(), 3);
  
  // Проверяем что координаты соответствуют формуле x=10*id, y=10*id, volume=100*id
  for (size_t i = 0; i < shops.size(); i++)
  {
    int id = shops[i].id;
    EXPECT_NEAR(shops[i].x, 10.0 * id, 0.01);
    EXPECT_NEAR(shops[i].y, 10.0 * id, 0.01);
    EXPECT_NEAR(shops[i].volume, 100.0 * id, 0.01);
  }
  
  std::cout << "ТЕСТ ПРОЙДЕН" << std::endl;
}

// Тест 4: Ошибка - несуществующий файл
TEST(CsvParserTest, Error_FileNotFound)
{
  std::cout << "\n=== ТЕСТ: CsvParser - ошибка: файл не найден ===" << std::endl;
  
  std::vector<ShopData> shops;
  std::string error;
  
  bool result = CsvParser::ParseShopsFile("/tmp/nonexistent_12345.csv", shops, error);
  
  EXPECT_FALSE(result) << "Должна быть ошибка для несуществующего файла";
  EXPECT_FALSE(error.empty()) << "Сообщение об ошибке не должно быть пустым";
  
  std::cout << "Результат: получена ошибка (ожидаемо): " << error << std::endl;
  std::cout << "ТЕСТ ПРОЙДЕН" << std::endl;
}
