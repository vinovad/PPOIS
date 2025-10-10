'''cpp
/**
 * @file ShelfLocation.h
 * @brief Класс для работы с расположением на полке
 */

#ifndef SHELFLOCATION_H
#define SHELFLOCATION_H

#include "PositionLocation.h"
#include <string>
using namespace std;

/**
 * @class ShelfLocation
 * @brief Представляет расположение книги на полке
 */
class ShelfLocation {
private:
    string shelf;                   ///< Название полки
    PositionLocation associatedPosition; ///< Ассоциированная позиция

public:
    /**
     * @brief Конструктор с параметрами
     * @param sh Название полки
     * @param position Ассоциированная позиция
     */
    ShelfLocation(const string& sh, const PositionLocation& position);
    
    /**
     * @brief Конструктор по умолчанию
     */
    ShelfLocation();
    
    /**
     * @brief Получить название полки
     * @return Название полки
     */
    string get_shelf();
    
    /**
     * @brief Получить ассоциированную позицию
     * @return Позиция на полке
     */
    int get_AssociatedPosition();
};

#endif
'''
