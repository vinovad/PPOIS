
/**
 * @file AgeRestriction.h
 * @brief Класс для работы с возрастными ограничениями
 */

#ifndef AGERESTRICTION_H
#define AGERESTRICTION_H

#include "TargetAudience.h"
#include "User.h"

/**
 * @class AgeRestriction
 * @brief Представляет возрастные ограничения для книги с информацией о целевой аудитории и пользователе
 */
class AgeRestriction {
private:
    int age_restriction;            ///< Возрастное ограничение
    TargetAudience associatedAudience; ///< Ассоциированная целевая аудитория
    User associatedUser;            ///< Ассоциированный пользователь

public:
    /**
     * @brief Конструктор с параметрами
     * @param age Возрастное ограничение
     * @param audience Ассоциированная целевая аудитория
     * @param user Ассоциированный пользователь
     */
    AgeRestriction(int age, const TargetAudience& audience, const User& user);
    
    /**
     * @brief Конструктор по умолчанию
     */
    AgeRestriction();
    
    /**
     * @brief Получить возрастное ограничение
     * @return Возрастное ограничение
     */
    int get_age_restriction();
    
    /**
     * @brief Получить ассоциированную целевую аудиторию
     * @return Тип аудитории
     */
    string get_AssociatedAudience();
    
    /**
     * @brief Получить уровень образования ассоциированной аудитории
     * @return Уровень образования
     */
    string get_AssociatedAudienceEducation();
    
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
     * @brief Установить возрастное ограничение
     * @param v Новое возрастное ограничение
     */
    void set_age_restriction(int v);
};

#endif
