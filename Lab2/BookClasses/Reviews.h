/**
 * @file Reviews.h
 * @brief Класс для работы с отзывами о книгах
 */

#ifndef REVIEWS_H
#define REVIEWS_H

#include <string>
using namespace std;

/**
 * @class Reviews
 * @brief Представляет отзыв о книге с дополнительной информацией
 */
class Reviews {
private:
    string reviews;         ///< Текст отзыва
    int helpful_votes;      ///< Количество полезных голосов
    string review_date;     ///< Дата отзыва

public:
    /**
     * @brief Конструктор с параметром
     * @param rev Текст отзыва
     */
    Reviews(const string& rev);

    /**
     * @brief Конструктор по умолчанию
     */
    Reviews();

    /**
     * @brief Получить текст отзыва
     * @return Текст отзыва
     */
    string get_reviews();
};

#endif