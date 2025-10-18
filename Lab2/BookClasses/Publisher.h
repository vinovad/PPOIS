/**
 * @file Publisher.h
 * @brief Класс для работы с издателем книги
 */

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
using namespace std;

/**
 * @class Publisher
 * @brief Представляет издателя книги с дополнительной информацией
 */
class Publisher {
private:
    string publisher;           ///< Название издательства
    string founder;             ///< Основатель
    int foundation_year;        ///< Год основания
    string headquarters;        ///< Местоположение штаб-квартиры

public:
    /**
     * @brief Конструктор с параметром
     * @param p Название издательства
     */
    Publisher(const string& p);

    /**
     * @brief Конструктор по умолчанию
     */
    Publisher();

    /**
     * @brief Получить название издательства
     * @return Название издательства
     */
    string get_publisher();

    /**
     * @brief Установить название издательства
     * @param p Новое название издательства
     */
    void set_publisher(string p);
};

#endif