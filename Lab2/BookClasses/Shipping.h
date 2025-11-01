/**
 * @file Shipping.h
 * @brief Класс для работы с информацией о доставке книг
 */

#ifndef SHIPPING_H
#define SHIPPING_H

#include "User.h"
#include <string>
using namespace std;

/**
 * @class Shipping
 * @brief Представляет информацию о доступности доставки для пользователя
 */
class Shipping {
private:
    bool has_shipping;
    User associatedUser;
    string shipping_type;
    double shipping_cost;
    string tracking_number;
    string carrier;
    string estimated_delivery_date;
    string shipping_status;

public:
    /**
     * @brief Конструктор с параметрами
     * @param shipping Статус доставки
     * @param user Ассоциированный пользователь
     */
    Shipping(bool shipping, const User& user);

    /**
     * @brief Конструктор по умолчанию
     */
    Shipping();

    /**
     * @brief Проверить наличие доставки
     * @return true если доставка доступна, false в противном случае
     */
    bool has_shipping_available();

    /**
     * @brief Получить имя ассоциированного пользователя
     * @return Имя пользователя
     */
    string get_AssociatedUserName();

    /**
     * @brief Получить тип доставки
     * @return Тип доставки
     */
    string get_shipping_type();

    /**
     * @brief Получить стоимость доставки
     * @return Стоимость доставки
     */
    double get_shipping_cost();

    /**
     * @brief Установить статус доставки
     * @param shipping Новый статус доставки
     */
    void set_shipping_status(bool shipping);
};


#endif
