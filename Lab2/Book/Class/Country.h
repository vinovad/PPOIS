
/**
 * @file Country.h
 * @brief Класс для работы со страной издания
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
using namespace std;

/**
 * @class Country
 * @brief Представляет страну издания книги
 */
class Country {
private:
    string country; ///< Название страны

public:
    /**
     * @brief Конструктор с параметром
     * @param c Название страны
     */
    Country(const string& c);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Country();
    
    /**
     * @brief Получить название страны
     * @return Название страны
     */
    string get_country();
};

#endif
