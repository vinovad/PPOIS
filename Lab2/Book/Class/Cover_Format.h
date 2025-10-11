
/**
 * @file Cover_Format.h
 * @brief Класс для работы с форматом обложки книги
 */

#ifndef COVER_FORMAT_H
#define COVER_FORMAT_H

#include "Publisher.h"
#include <string>
using namespace std;

/**
 * @class Cover_Format
 * @brief Представляет формат обложки книги с информацией об издателе
 */
class Cover_Format {
private:
    string format;              ///< Формат обложки
    Publisher associatedPublisher; ///< Ассоциированный издатель

public:
    /**
     * @brief Конструктор с параметрами
     * @param f Формат обложки
     * @param publisher Ассоциированный издатель
     */
    Cover_Format(const string& f, const Publisher& publisher);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Cover_Format();
    
    /**
     * @brief Получить формат обложки
     * @return Формат обложки
     */
    string get_format();
    
    /**
     * @brief Получить ассоциированного издателя
     * @return Название издателя
     */
    string get_AssociatedPublisher();
    
    /**
     * @brief Установить формат обложки
     * @param f Новый формат обложки
     */
    void set_format(string f);
};

#endif
