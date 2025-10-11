
/**
 * @file BookCondition.h
 * @brief Класс для работы с состоянием книги
 */

#ifndef BOOKCONDITION_H
#define BOOKCONDITION_H

#include <string>
using namespace std;

/**
 * @class BookCondition
 * @brief Представляет информацию о состоянии книги
 */
class BookCondition {
private:
    string condition;           ///< Состояние книги
    int wear_level;             ///< Уровень износа
    string damage_description;  ///< Описание повреждений

public:
    /**
     * @brief Конструктор с параметром
     * @param cond Состояние книги
     */
    BookCondition(const string& cond);
    
    /**
     * @brief Конструктор по умолчанию
     */
    BookCondition();
    
    /**
     * @brief Получить состояние книги
     * @return Состояние книги
     */
    string get_condition();
};

#endif

