/**
 * @file Author.h
 * @brief Класс для работы с автором книги
 */

#ifndef AUTHOR_H
#define AUTHOR_H

#include "Country.h"
#include "Language.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @class Author
 * @brief Представляет автора книги с дополнительной информацией
 */
class Author {
private:
    string name;
    string birth_year;
    int books_written;
    Country associatedCountry;
    Language associatedLanguage;
    string pseudonym;
    string nationality;
    string awards;
    string education;
    string death_year;
    string biography;
    string website;
    string social_media;
    vector<string> genres;
public:
    /**
     * @brief Конструктор с параметрами
     * @param n Имя автора
     * @param by Год рождения
     * @param bw Количество написанных книг
     * @param country Ассоциированная страна
     * @param language Ассоциированный язык
     */
    Author(const string& n, const string& by, int bw, const Country& country, const Language& language);

    /**
     * @brief Конструктор по умолчанию
     */
    Author();

    /**
     * @brief Получить имя автора
     * @return Имя автора
     */
    string get_Author();

    /**
     * @brief Получить год рождения
     * @return Год рождения
     */
    string get_birth();

    /**
     * @brief Получить количество книг
     * @return Количество написанных книг
     */
    int get_books();

    /**
     * @brief Получить ассоциированную страну
     * @return Название страны
     */
    string get_AssociatedCountry();

    /**
     * @brief Получить ассоциированный язык
     * @return Язык
     */
    string get_AssociatedLanguage();

    /**
     * @brief Установить год рождения
     * @param by Год рождения
     */
    void set_birth(int by);

    /**
     * @brief Установить количество книг
     * @param bw Количество написанных книг
     */
    void set_books(int bw);
};


#endif
