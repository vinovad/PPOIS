
/**
 * @file BookTitle.h
 * @brief Класс для работы с названием книги
 */

#ifndef BOOKTITLE_H
#define BOOKTITLE_H

#include <string>
using namespace std;

/**
 * @class BookTitle
 * @brief Представляет название книги и связанную информацию
 */
class BookTitle {
private:
    string title_book;          ///< Название книги
    string original_title;      ///< Оригинальное название
    string subtitle;            ///< Подзаголовок

public:
    /**
     * @brief Конструктор с параметром
     * @param title Название книги
     */
    BookTitle(const string& title);
    
    /**
     * @brief Конструктор по умолчанию
     */
    BookTitle();
    
    /**
     * @brief Получить название книги
     * @return Название книги
     */
    string get_Book();
    
    /**
     * @brief Установить название книги
     * @param tb Новое название книги
     */
    void set_Book(string tb);
};

#endif


