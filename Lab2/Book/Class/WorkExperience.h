
/**
 * @file WorkExperience.h
 * @brief Класс для работы с опытом работы
 */

#ifndef WORKEXPERIENCE_H
#define WORKEXPERIENCE_H

#include <string>
using namespace std;

/**
 * @class WorkExperience
 * @brief Представляет опыт работы сотрудника
 */
class WorkExperience {
private:
    int years_of_experience;    ///< Количество лет опыта
    string previous_companies;  ///< Предыдущие компании
    string specialization;      ///< Специализация

public:
    /**
     * @brief Конструктор с параметром
     * @param experience Количество лет опыта
     */
    WorkExperience(int experience);
    
    /**
     * @brief Конструктор по умолчанию
     */
    WorkExperience();
    
    /**
     * @brief Получить количество лет опыта
     * @return Количество лет опыта
     */
    int get_years_of_experience() const;
};

#endif
