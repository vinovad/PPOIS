
/**
 * @file BookSeries.h
 * @brief Класс для работы с сериями книг
 */

#ifndef BOOKSERIES_H
#define BOOKSERIES_H

#include <string>
using namespace std;

/**
 * @class BookSeries
 * @brief Представляет информацию о серии книг
 */
class BookSeries {
private:
    string series_name;     ///< Название серии
    int volume_number;      ///< Номер тома в серии

public:
    /**
     * @brief Конструктор с параметром
     * @param name Название серии
     */
    BookSeries(const string& name);
    
    /**
     * @brief Конструктор по умолчанию
     */
    BookSeries();
    
    /**
     * @brief Получить название серии
     * @return Название серии
     */
    string get_series_name();
};

#endif

