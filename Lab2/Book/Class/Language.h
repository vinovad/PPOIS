
/**
 * @file Language.h
 * @brief Класс для работы с языком книги
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>
using namespace std;

/**
 * @class Language
 * @brief Представляет язык книги
 */
class Language {
private:
    string language; ///< Язык книги

public:
    /**
     * @brief Конструктор с параметром
     * @param l Язык книги
     */
    Language(const string& l);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Language();
    
    /**
     * @brief Получить язык книги
     * @return Язык книги
     */
    string get_language();
    
    /**
     * @brief Установить язык книги
     * @param l Новый язык книги
     */
    void set_language(string l);
};

#endif

