
  /**
 * @file Genre.h
 * @brief Класс для работы с жанрами книг
 */

#ifndef GENRE_H
#define GENRE_H

#include "Tag.h"
#include <string>
using namespace std;

/**
 * @class Genre
 * @brief Представляет жанр книги с ассоциированным тегом
 */
class Genre {
private:
    string genre;           ///< Название жанра
    Tag associatedTag;      ///< Ассоциированный тег

public:
    /**
     * @brief Конструктор с параметрами
     * @param g Название жанра
     * @param tag Ассоциированный тег
     */
    Genre(const string& g, const Tag& tag);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Genre();
    
    /**
     * @brief Получить жанр
     * @return Название жанра
     */
    string get_Genre();
    
    /**
     * @brief Получить ассоциированный тег
     * @return Название тега
     */
    string get_AssociatedTag();
    
    /**
     * @brief Установить жанр
     * @param gen Новое название жанра
     */
    void set_Genre(string gen);
};

#endif
  
