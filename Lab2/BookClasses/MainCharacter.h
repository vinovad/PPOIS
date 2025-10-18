/**
 * @file MainCharacter.h
 * @brief Класс для работы с главными персонажами книг
 */

#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "BookVolumeCount.h"
#include <string>
using namespace std;

/**
 * @class MainCharacter
 * @brief Представляет главного персонажа книги
 */
class MainCharacter {
private:
    string name_character;          ///< Имя персонажа
    BookVolumeCount associatedVolumeCount; ///< Ассоциированное количество томов

public:
    /**
     * @brief Конструктор с параметрами
     * @param nc Имя персонажа
     * @param volumeCount Ассоциированное количество томов
     */
    MainCharacter(const string& nc, const BookVolumeCount& volumeCount);

    /**
     * @brief Конструктор по умолчанию
     */
    MainCharacter();

    /**
     * @brief Получить имя персонажа
     * @return Имя персонажа
     */
    string get_character();

    /**
     * @brief Получить ассоциированное количество томов
     * @return Количество томов
     */
    int get_AssociatedVolumeCount();

    /**
     * @brief Получить ассоциированную серию
     * @return Название серии
     */
    string get_AssociatedSeries();
};

#endif