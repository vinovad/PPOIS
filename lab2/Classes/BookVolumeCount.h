/**
 * @file BookVolumeCount.h
 * @brief Класс для работы с количеством томов в серии
 */

#ifndef BOOKVOLUMECOUNT_H
#define BOOKVOLUMECOUNT_H

#include "BookSeries.h"

 /**
  * @class BookVolumeCount
  * @brief Представляет количество томов в серии книг
  */
class BookVolumeCount {
private:
    int volume_number;          ///< Номер тома
    BookSeries associatedSeries; ///< Ассоциированная серия

public:
    /**
     * @brief Конструктор с параметрами
     * @param volume Номер тома
     * @param series Ассоциированная серия
     */
    BookVolumeCount(int volume, const BookSeries& series);

    /**
     * @brief Конструктор по умолчанию
     */
    BookVolumeCount();

    /**
     * @brief Получить номер тома
     * @return Номер тома
     */
    int get_volume_number();

    /**
     * @brief Получить ассоциированную серию
     * @return Название серии
     */
    string get_AssociatedSeries();
};

#endif