'''cpp
/**
 * @file PersonalOpinion.h
 * @brief Класс для работы с личными мнениями о книгах
 */

#ifndef PERSONALOPINION_H
#define PERSONALOPINION_H

#include "NumberOfPeople.h"
#include <string>
using namespace std;

/**
 * @class PersonalOpinion
 * @brief Представляет личное мнение о книге с информацией о количестве людей
 */
class PersonalOpinion {
private:
    string opinion;                 ///< Текст мнения
    NumberOfPeople associatedPeople; ///< Ассоциированное количество людей
    int recommendation_score;       ///< Оценка рекомендации
    string opinion_date;            ///< Дата мнения

public:
    /**
     * @brief Конструктор с параметрами
     * @param op Текст мнения
     * @param people Ассоциированное количество людей
     */
    PersonalOpinion(const string& op, const NumberOfPeople& people);
    
    /**
     * @brief Конструктор по умолчанию
     */
    PersonalOpinion();
    
    /**
     * @brief Получить текст мнения
     * @return Текст мнения
     */
    string get_opinion();
    
    /**
     * @brief Получить ассоциированное количество людей
     * @return Количество людей
     */
    int get_AssociatedPeople();
};

#endif
'''
