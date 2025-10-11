
/**
 * @file Rating.h
 * @brief Класс для работы с рейтингом книги
 */

#ifndef RATING_H
#define RATING_H

/**
 * @class Rating
 * @brief Представляет рейтинг книги и статистику оценок
 */
class Rating {
private:
    double rating;          ///< Текущий рейтинг
    int number_of_votes;    ///< Количество голосов
    double average_rating;  ///< Средний рейтинг

public:
    /**
     * @brief Конструктор с параметром
     * @param r Начальный рейтинг
     */
    Rating(double r);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Rating();
    
    /**
     * @brief Получить текущий рейтинг
     * @return Текущий рейтинг
     */
    double get_rating();
    
    /**
     * @brief Установить рейтинг
     * @param r Новый рейтинг
     */
    void set_rating(double r);
};

#endif

