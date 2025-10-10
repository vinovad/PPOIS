'''cpp
/**
 * @file LoyaltyProgram.h
 * @brief Класс для работы с программой лояльности
 */

#ifndef LOYALTYPROGRAM_H
#define LOYALTYPROGRAM_H

#include "User.h"

/**
 * @class LoyaltyProgram
 * @brief Представляет программу лояльности для пользователей
 */
class LoyaltyProgram {
private:
    User associatedUser;        ///< Ассоциированный пользователь
    double discount_percentage; ///< Процент скидки
    bool has_user;              ///< Наличие установленного пользователя

public:
    /**
     * @brief Конструктор с параметром
     * @param user_obj Ассоциированный пользователь
     */
    LoyaltyProgram(const User& user_obj);
    
    /**
     * @brief Конструктор по умолчанию
     */
    LoyaltyProgram();
    
    /**
     * @brief Обновить скидку на основе активности пользователя
     */
    void update_discount();
    
    /**
     * @brief Получить текущую скидку
     * @return Процент скидки
     */
    double get_discount();
    
    /**
     * @brief Применить скидку к цене
     * @param original_price Исходная цена
     * @return Цена со скидкой
     */
    double apply_discount(double original_price);
    
    /**
     * @brief Получить имя ассоциированного пользователя
     * @return Имя пользователя
     */
    string get_AssociatedUserName();
    
    /**
     * @brief Получить количество книг ассоциированного пользователя
     * @return Количество книг
     */
    int get_AssociatedUserBooks();
    
    /**
     * @brief Установить пользователя
     * @param user_obj Пользователь
     */
    void set_user(const User& user_obj);
    
    /**
     * @brief Проверить, установлен ли пользователь
     * @return true если пользователь установлен, false в противном случае
     */
    bool has_user_set() const;
};

#endif
'''
