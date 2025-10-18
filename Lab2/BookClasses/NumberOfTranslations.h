/**
 * @file NumberOfTranslations.h
 * @brief Класс для работы с количеством переводов книги
 */

#ifndef NUMBEROFTRANSLATIONS_H
#define NUMBEROFTRANSLATIONS_H

#include "Language.h"

 /**
  * @class NumberOfTranslations
  * @brief Представляет количество переводов книги на разные языки
  */
class NumberOfTranslations {
private:
    int number_translations;    ///< Количество переводов
    Language associatedLanguage; ///< Ассоциированный язык

public:
    /**
     * @brief Конструктор с параметрами
     * @param tran Количество переводов
     * @param language Ассоциированный язык
     */
    NumberOfTranslations(int tran, const Language& language);

    /**
     * @brief Конструктор по умолчанию
     */
    NumberOfTranslations();

    /**
     * @brief Получить количество переводов
     * @return Количество переводов
     */
    int get_number_translations();

    /**
     * @brief Получить ассоциированный язык
     * @return Язык
     */
    string get_AssociatedLanguage();
};

#endif