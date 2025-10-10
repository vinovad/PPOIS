'''cpp
/**
 * @file ArrivalDate.h
 * @brief Класс для работы с датами поступления книг
 */

#ifndef ARRIVALDATE_H
#define ARRIVALDATE_H

#include <string>
using namespace std;

/**
 * @class ArrivalDate
 * @brief Представляет информацию о датах поступления и пополнения книг
 */
class ArrivalDate {
private:
    string date;            ///< Фактическая дата поступления
    string expected_date;   ///< Ожидаемая дата поступления
    string restock_date;    ///< Дата пополнения запасов

public:
    /**
     * @brief Конструктор с параметром
     * @param d Дата поступления
     */
    ArrivalDate(const string& d);
    
    /**
     * @brief Конструктор по умолчанию
     */
    ArrivalDate();
    
    /**
     * @brief Получить дату поступления
     * @return Дата поступления
     */
    string get_arrival_date();
};

#endif
'''
