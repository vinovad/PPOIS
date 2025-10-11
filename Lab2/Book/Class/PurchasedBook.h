
/**
 * @file PurchasedBook.h
 * @brief Класс для работы с информацией о покупках книг
 */

#ifndef PURCHASEDBOOK_H
#define PURCHASEDBOOK_H

#include <string>
using namespace std;

/**
 * @class PurchasedBook
 * @brief Представляет информацию о купленной книге
 */
class PurchasedBook {
private:
    string book_title;      ///< Название книги
    string purchase_date;   ///< Дата покупки
    double purchase_price;  ///< Цена покупки
    string user_name;       ///< Имя пользователя

public:
    /**
     * @brief Конструктор с параметрами
     * @param title Название книги
     * @param date Дата покупки
     * @param price Цена покупки
     * @param user Имя пользователя
     */
    PurchasedBook(const string& title, const string& date, double price, const string& user);
    
    /**
     * @brief Конструктор по умолчанию
     */
    PurchasedBook();
    
    /**
     * @brief Получить название книги
     * @return Название книги
     */
    string get_book_title();
    
    /**
     * @brief Получить дату покупки
     * @return Дата покупки
     */
    string get_purchase_date();
    
    /**
     * @brief Получить цену покупки
     * @return Цена покупки
     */
    double get_purchase_price();
    
    /**
     * @brief Получить имя пользователя
     * @return Имя пользователя
     */
    string get_user_name();
    
    /**
     * @brief Отобразить информацию о покупке
     */
    void display_purchase_info();
};

#endif

