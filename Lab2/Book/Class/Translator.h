'''cpp
/**
 * @file Translator.h
 * @brief Класс для работы с переводчиком книги
 */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "NumberOfTranslations.h"
#include <string>
using namespace std;

/**
 * @class Translator
 * @brief Представляет переводчика книги
 */
class Translator {
private:
    string translator;                      ///< Имя переводчика
    NumberOfTranslations associatedTranslations; ///< Ассоциированные переводы

public:
    /**
     * @brief Конструктор с параметрами
     * @param tr Имя переводчика
     * @param translations Ассоциированные переводы
     */
    Translator(const string& tr, const NumberOfTranslations& translations);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Translator();
    
    /**
     * @brief Получить имя переводчика
     * @return Имя переводчика
     */
    string get_translator();
    
    /**
     * @brief Получить количество ассоциированных переводов
     * @return Количество переводов
     */
    int get_AssociatedTranslations();
};

#endif
'''
