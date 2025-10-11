
/**
 * @file Tag.h
 * @brief Класс для работы с тегами книг
 */

#ifndef TAG_H
#define TAG_H

#include <string>
using namespace std;

/**
 * @class Tag
 * @brief Представляет тег для категоризации книг
 */
class Tag {
private:
    string book_tag; ///< Название тега

public:
    /**
     * @brief Конструктор с параметром
     * @param t Название тега
     */
    Tag(const string& t);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Tag();
    
    /**
     * @brief Получить тег
     * @return Название тега
     */
    string get_Tag();
    
    /**
     * @brief Установить тег
     * @param tg Новое название тега
     */
    void set_Tag(string tg);
};

#endif

