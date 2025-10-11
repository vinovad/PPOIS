
/**
 * @file PositionLocation.h
 * @brief Класс для работы с позицией на полке
 */

#ifndef POSITIONLOCATION_H
#define POSITIONLOCATION_H

/**
 * @class PositionLocation
 * @brief Представляет позицию книги на полке
 */
class PositionLocation {
private:
    int position; ///< Позиция на полке

public:
    /**
     * @brief Конструктор с параметром
     * @param pos Позиция на полке
     */
    PositionLocation(int pos);
    
    /**
     * @brief Конструктор по умолчанию
     */
    PositionLocation();
    
    /**
     * @brief Получить позицию на полке
     * @return Позиция на полке
     */
    int get_position();
};

#endif
