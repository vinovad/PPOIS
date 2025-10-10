'''cpp
/**
 * @file SectionLocation.h
 * @brief Класс для работы с расположением в секции
 */

#ifndef SECTIONLOCATION_H
#define SECTIONLOCATION_H

#include "ShelfLocation.h"
#include <string>
using namespace std;

/**
 * @class SectionLocation
 * @brief Представляет расположение книги в секции библиотеки
 */
class SectionLocation {
private:
    string section;             ///< Название секции
    ShelfLocation associatedShelf; ///< Ассоциированная полка

public:
    /**
     * @brief Конструктор с параметрами
     * @param sec Название секции
     * @param shelf Ассоциированная полка
     */
    SectionLocation(const string& sec, const ShelfLocation& shelf);
    
    /**
     * @brief Конструктор с одним параметром
     * @param sec Название секции
     */
    SectionLocation(const string& sec);
    
    /**
     * @brief Конструктор по умолчанию
     */
    SectionLocation();
    
    /**
     * @brief Получить название секции
     * @return Название секции
     */
    string get_section();
    
    /**
     * @brief Получить ассоциированную полку
     * @return Название полки
     */
    string get_AssociatedShelf();
};

#endif
'''
