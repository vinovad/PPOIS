'''cpp
/**
 * @file NumberOfPeople.h
 * @brief Класс для работы с количеством людей
 */

#ifndef NUMBEROFPEOPLE_H
#define NUMBEROFPEOPLE_H

#include "User.h"

/**
 * @class NumberOfPeople
 * @brief Представляет количество людей с ассоциированным пользователем
 */
class NumberOfPeople {
private:
    int number_people;      ///< Количество людей
    User associatedUser;    ///< Ассоциированный пользователь

public:
    /**
     * @brief Конструктор с параметрами
     * @param people Количество людей
     * @param user Ассоциированный пользователь
     */
    NumberOfPeople(int people, const User& user);
    
    /**
     * @brief Конструктор по умолчанию
     */
    NumberOfPeople();
    
    /**
     * @brief Получить количество людей
     * @return Количество людей
     */
    int get_number_people();
    
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
};

#endif
'''
