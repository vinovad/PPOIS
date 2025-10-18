/**
 * @file BookWeight.h
 * @brief Класс для работы с весом книги
 */

#ifndef BOOKWEIGHT_H
#define BOOKWEIGHT_H

#include "BookFormat.h"

 /**
  * @class BookWeight
  * @brief Представляет вес книги и связанную информацию
  */
class BookWeight {
private:
    double weight;              ///< Вес книги
    double shipping_weight;     ///< Вес для доставки
    string weight_category;     ///< Категория веса
    BookFormat associatedFormat; ///< Ассоциированный формат

public:
    /**
     * @brief Конструктор с параметрами
     * @param w Вес книги
     * @param format Ассоциированный формат
     */
    BookWeight(double w, const BookFormat& format);

    /**
     * @brief Конструктор по умолчанию
     */
    BookWeight();

    /**
     * @brief Получить вес книги
     * @return Вес книги
     */
    double get_weight();

    /**
     * @brief Получить ассоциированный формат
     * @return Формат книги
     */
    string get_AssociatedFormat();
};

#endif