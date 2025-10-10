'''cpp
/**
 * @file TargetAudience.h
 * @brief Класс для работы с целевой аудиторией
 */

#ifndef TARGETAUDIENCE_H
#define TARGETAUDIENCE_H

#include "EducationLevel.h"
#include <string>
using namespace std;

/**
 * @class TargetAudience
 * @brief Представляет целевую аудиторию книги с уровнем образования
 */
class TargetAudience {
private:
    string audience_type;           ///< Тип аудитории
    EducationLevel associatedEducationLevel; ///< Ассоциированный уровень образования

public:
    /**
     * @brief Конструктор с параметрами
     * @param type Тип аудитории
     * @param educationLevel Ассоциированный уровень образования
     */
    TargetAudience(const string& type, const EducationLevel& educationLevel);
    
    /**
     * @brief Конструктор по умолчанию
     */
    TargetAudience();
    
    /**
     * @brief Получить тип аудитории
     * @return Тип аудитории
     */
    string get_audience_type();
    
    /**
     * @brief Получить ассоциированный уровень образования
     * @return Уровень образования
     */
    string get_AssociatedEducationLevel();
};

#endif
'''
