
/**
 * @file AssistantName.h
 * @brief Класс для работы с информацией об ассистентах
 */

#ifndef ASSISTANTNAME_H
#define ASSISTANTNAME_H

#include "WorkExperience.h"
#include <string>
using namespace std;

/**
 * @class AssistantName
 * @brief Представляет информацию об ассистенте с опытом работы
 */
class AssistantName {
private:
    string assistantname;           ///< Имя ассистента
    WorkExperience associatedExperience; ///< Ассоциированный опыт работы
    string department;              ///< Отдел
    string shift_schedule;          ///< График работы

public:
    /**
     * @brief Конструктор с параметрами
     * @param name Имя ассистента
     * @param experience Ассоциированный опыт работы
     */
    AssistantName(const string& name, const WorkExperience& experience);
    
    /**
     * @brief Конструктор по умолчанию
     */
    AssistantName();
    
    /**
     * @brief Получить имя ассистента
     * @return Имя ассистента
     */
    string get_name() const;
    
    /**
     * @brief Получить ассоциированный опыт работы
     * @return Количество лет опыта
     */
    int get_AssociatedExperience();
};

#endif
