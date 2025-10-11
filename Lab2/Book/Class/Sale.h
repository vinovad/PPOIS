
/**
 * @file Sale.h
 * @brief Класс для работы с информацией о продажах и скидках
 */

#ifndef SALE_H
#define SALE_H

#include <string>
using namespace std;

/**
 * @class Sale
 * @brief Представляет информацию о продажах, скидках и акциях
 */
class Sale {
private:
    double discount_percentage; ///< Процент скидки
    string sale_period;         ///< Период продажи
    string promotion_code;      ///< Промокод
    int max_uses;               ///< Максимальное количество использований

public:
    /**
     * @brief Конструктор с параметрами
     * @param discount Процент скидки
     * @param period Период продажи
     */
    Sale(double discount, const string& period);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Sale();
    
    /**
     * @brief Получить процент скидки
     * @return Процент скидки
     */
    double get_discount();
    
    /**
     * @brief Получить период продажи
     * @return Период продажи
     */
    string get_sale_period();
};

#endif

