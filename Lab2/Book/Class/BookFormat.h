
/**
 * @file BookFormat.h
 * @brief Класс для работы с форматом книги
 */

#ifndef BOOKFORMAT_H
#define BOOKFORMAT_H

#include "PageCount.h"
#include <string>
using namespace std;

/**
 * @class BookFormat
 * @brief Представляет формат книги с информацией о страницах
 */
class BookFormat {
private:
    string bookformat;          ///< Формат книги
    PageCount associatedPageCount; ///< Ассоциированная информация о страницах

public:
    /**
     * @brief Конструктор с параметрами
     * @param bf Формат книги
     * @param pageCount Ассоциированная информация о страницах
     */
    BookFormat(const string& bf, const PageCount& pageCount);
    
    /**
     * @brief Конструктор по умолчанию
     */
    BookFormat();
    
    /**
     * @brief Получить формат книги
     * @return Формат книги
     */
    string get_bookformat();
    
    /**
     * @brief Получить количество ассоциированных страниц
     * @return Количество страниц
     */
    int get_AssociatedPageCount();
};

#endif
