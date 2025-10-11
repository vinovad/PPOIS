
/**
 * @file LimitedSeries.h
 * @brief Класс для работы с ограниченными сериями книг
 */

#ifndef LIMITEDSERIES_H
#define LIMITEDSERIES_H

#include "BookVolumeCount.h"

/**
 * @class LimitedSeries
 * @brief Представляет информацию об ограниченных сериях книг
 */
class LimitedSeries {
private:
    bool is_limited;                    ///< Является ли серия ограниченной
    BookVolumeCount associatedVolumeCount; ///< Ассоциированное количество томов

public:
    /**
     * @brief Конструктор с параметрами
     * @param limited Статус ограниченной серии
     * @param volumeCount Ассоциированное количество томов
     */
    LimitedSeries(bool limited, const BookVolumeCount& volumeCount);
    
    /**
     * @brief Конструктор по умолчанию
     */
    LimitedSeries();
    
    /**
     * @brief Проверить, является ли серия ограниченной
     * @return true если серия ограниченная, false в противном случае
     */
    bool is_limited_edition();
    
    /**
     * @brief Получить ассоциированное количество томов
     * @return Количество томов
     */
    int get_AssociatedVolumeCount();
};

#endif
