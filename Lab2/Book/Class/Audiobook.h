
/**
 * @file Audiobook.h
 * @brief Класс для работы с аудиокнигами
 */

#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

/**
 * @class Audiobook
 * @brief Представляет информацию о наличии аудиоверсии книги
 */
class Audiobook {
private:
    bool has_audiobook; ///< Наличие аудиокниги

public:
    /**
     * @brief Конструктор с параметром
     * @param audio Наличие аудиокниги
     */
    Audiobook(bool audio);
    
    /**
     * @brief Конструктор по умолчанию
     */
    Audiobook();
    
    /**
     * @brief Проверить наличие аудиоверсии
     * @return true если аудиокнига доступна, false в противном случае
     */
    bool has_audiobook_version();
};

#endif

