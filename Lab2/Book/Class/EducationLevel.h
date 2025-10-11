
/**
 * @file EducationLevel.h
 * @brief Класс для работы с уровнями образования
 */

#ifndef EDUCATIONLEVEL_H
#define EDUCATIONLEVEL_H

#include <string>
using namespace std;

/**
 * @class EducationLevel
 * @brief Представляет уровень образования целевой аудитории
 */
class EducationLevel {
private:
    string level; ///< Уровень образования

public:
    /**
     * @brief Конструктор с параметром
     * @param lvl Уровень образования
     */
    EducationLevel(const string& lvl);
    
    /**
     * @brief Конструктор по умолчанию
     */
    EducationLevel();
    
    /**
     * @brief Получить уровень образования
     * @return Уровень образования
     */
    string get_education_level();
};

#endif

