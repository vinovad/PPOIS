/**
 * @file YearOfManufacture.h
 * @brief Класс для работы с годом издания книги
 */

#ifndef YEAROFMANUFACTURE_H
#define YEAROFMANUFACTURE_H

#include <string>
using namespace std;

/**
 * @class YearOfManufacture
 * @brief Представляет год издания книги
 */
class YearOfManufacture {
private:
    int year; ///< Год издания

public:
    /**
     * @brief Конструктор с параметром
     * @param y Год издания
     */
    YearOfManufacture(int y);

    /**
     * @brief Конструктор по умолчанию
     */
    YearOfManufacture();

    /**
     * @brief Получить год издания
     * @return Год издания
     */
    int get_Year();

    /**
     * @brief Установить год издания (целое число)
     * @param y Новый год издания
     */
    void set_Year(int y);

    /**
     * @brief Установить год издания (строка)
     * @param g Год издания в виде строки
     */
    void set_Year(string g);
};

#endif