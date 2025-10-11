
/**
 * @file Price.h
 * @brief Класс для работы с ценой книги
 */

#ifndef PRICE_H
#define PRICE_H

#include "Sale.h"
#include <string>
using namespace std;

/**
 * @class Price
 * @brief Представляет цену книги с информацией о валюте, налогах и доставке
 */
class Price {
private:
    double price;           ///< Цена книги
    string currency;        ///< Валюта
    Sale associatedSale;    ///< Ассоциированная информация о продаже
    double tax_amount;      ///< Сумма налога
    double shipping_cost;   ///< Стоимость доставки

public:
    /**
     * @brief Конструктор с параметрами
     * @param p Цена книги
     * @param curr Валюта
     * @param sale Ассоциированная информация о продаже
     */
    Price(double p, const string& curr, const Sale& sale);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Price();
    
    /**
     * @brief Получить цену книги
     * @return Цена книги
     */
    double get_price();
    
    /**
     * @brief Получить валюту
     * @return Валюта
     */
    string get_currency();
    
    /**
     * @brief Получить ассоциированную скидку
     * @return Процент скидки
     */
    double get_AssociatedDiscount();
    
    /**
     * @brief Получить период ассоциированной продажи
     * @return Период продажи
     */
    string get_AssociatedSalePeriod();
};

#endif
