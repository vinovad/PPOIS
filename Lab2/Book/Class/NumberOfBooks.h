'''cpp
/**
 * @file NumberOfBooks.h
 * @brief Класс для работы с количеством книг
 */

#ifndef NUMBEROFBOOKS_H
#define NUMBEROFBOOKS_H

/**
 * @class NumberOfBooks
 * @brief Представляет количество доступных книг
 */
class NumberOfBooks {
private:
    int quantity; ///< Количество книг

public:
    /**
     * @brief Конструктор с параметром
     * @param qty Количество книг
     */
    NumberOfBooks(int qty);
    
    /**
     * @brief Конструктор по умолчанию
     */
    NumberOfBooks();
    
    /**
     * @brief Получить количество книг
     * @return Количество книг
     */
    int get_quantity();
};

#endif
'''
