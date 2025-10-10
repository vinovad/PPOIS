'''cpp
/**
 * @file NumberOfReviews.h
 * @brief Класс для работы с количеством отзывов
 */

#ifndef NUMBEROFREVIEWS_H
#define NUMBEROFREVIEWS_H

#include "Reviews.h"

/**
 * @class NumberOfReviews
 * @brief Представляет статистику отзывов о книге
 */
class NumberOfReviews {
private:
    int number_reviews;         ///< Количество отзывов
    Reviews associatedReviews;  ///< Ассоциированный отзыв
    int positive_reviews;       ///< Количество положительных отзывов
    int negative_reviews;       ///< Количество отрицательных отзывов

public:
    /**
     * @brief Конструктор с параметрами
     * @param nr Количество отзывов
     * @param reviews Ассоциированный отзыв
     */
    NumberOfReviews(int nr, const Reviews& reviews);
    
    /**
     * @brief Конструктор по умолчанию
     */
    NumberOfReviews();
    
    /**
     * @brief Получить количество отзывов
     * @return Количество отзывов
     */
    int get_number_reviews();
    
    /**
     * @brief Получить ассоциированный отзыв
     * @return Текст отзыва
     */
    string get_AssociatedReviews();
};

#endif
'''
