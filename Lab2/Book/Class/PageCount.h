
/**
 * @file PageCount.h
 * @brief Класс для работы с информацией о страницах книги
 */

#ifndef PAGECOUNT_H
#define PAGECOUNT_H

/**
 * @class PageCount
 * @brief Представляет информацию о количестве страниц и структуре книги
 */
class PageCount {
private:
    int number_pages;           ///< Количество страниц
    int illustrations_count;    ///< Количество иллюстраций
    int chapters_count;         ///< Количество глав

public:
    /**
     * @brief Конструктор с параметром
     * @param pages Количество страниц
     */
    PageCount(int pages);
    
    /**
     * @brief Конструктор по умолчанию
     */
    PageCount();
    
    /**
     * @brief Получить количество страниц
     * @return Количество страниц
     */
    int get_number_pages();
    
    /**
     * @brief Установить количество страниц
     * @param n Новое количество страниц
     */
    void set_number_pages(int n);
};

#endif
