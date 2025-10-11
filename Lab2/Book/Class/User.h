
/**
 * @file User.h
 * @brief Класс для работы с пользователями системы
 */

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

/**
 * @class User
 * @brief Представляет пользователя системы с информацией о покупках
 */
class User {
private:
    string name;                ///< Имя пользователя
    int books_bought;           ///< Количество купленных книг
    string email;               ///< Email пользователя
    string phone_number;        ///< Номер телефона
    string registration_date;   ///< Дата регистрации
    string address;             ///< Адрес
    int loyalty_points;         ///< Баллы лояльности

public:
    /**
     * @brief Конструктор с параметром
     * @param user_name Имя пользователя
     */
    User(const string& user_name);
    
    /**
     * @brief Конструктор по умолчанию
     */
    User();
    
    /**
     * @brief Получить имя пользователя
     * @return Имя пользователя
     */
    string get_name();
    
    /**
     * @brief Получить количество купленных книг
     * @return Количество купленных книг
     */
    int get_books_bought();
    
    /**
     * @brief Добавить купленную книгу
     */
    void add_purchased_book();
};

#endif

