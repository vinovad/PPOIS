
/**
 * @file Prohibited.h
 * @brief Класс для работы с информацией о запрете книги
 */

#ifndef PROHIBITED_H
#define PROHIBITED_H

#include "Country.h"

/**
 * @class Prohibited
 * @brief Представляет информацию о запрете книги в определенной стране
 */
class Prohibited {
private:
    bool is_prohibited;        ///< Статус запрета
    Country associatedCountry; ///< Ассоциированная страна

public:
    /**
     * @brief Конструктор с параметрами
     * @param prohibited Статус запрета
     * @param country Ассоциированная страна
     */
    Prohibited(bool prohibited, const Country& country);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Prohibited();
    
    /**
     * @brief Получить статус запрета
     * @return true если книга запрещена, false в противном случае
     */
    bool get_is_prohibited();
    
    /**
     * @brief Получить ассоциированную страну
     * @return Название страны
     */
    string get_AssociatedCountry();
};

#endif

