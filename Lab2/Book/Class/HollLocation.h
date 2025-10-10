'''cpp
/**
 * @file HollLocation.h
 * @brief Класс для работы с расположением в зале
 */

#ifndef HOLLLOCATION_H
#define HOLLLOCATION_H

#include "SectionLocation.h"

/**
 * @class HollLocation
 * @brief Представляет расположение книги в зале библиотеки
 */
class HollLocation {
private:
    int holl;                   ///< Номер зала
    SectionLocation associatedSection; ///< Ассоциированная секция

public:
    /**
     * @brief Конструктор с параметрами
     * @param h Номер зала
     * @param section Ассоциированная секция
     */
    HollLocation(int h, const SectionLocation& section);
    
    /**
     * @brief Конструктор по умолчанию
     */
    HollLocation();
    
    /**
     * @brief Получить номер зала
     * @return Номер зала
     */
    int get_holl();
    
    /**
     * @brief Получить ассоциированную секцию
     * @return Название секции
     */
    string get_AssociatedSection();
};

#endif
'''
