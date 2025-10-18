/**
 * @file ElectronicPDF.h
 * @brief Класс для работы с электронными версиями книг
 */

#ifndef ELECTRONICPDF_H
#define ELECTRONICPDF_H

#include "Audiobook.h"

 /**
  * @class ElectronicPDF
  * @brief Представляет информацию о наличии электронной и аудиоверсий книги
  */
class ElectronicPDF {
private:
    bool has_pdf;               ///< Наличие PDF версии
    Audiobook associatedAudiobook; ///< Ассоциированная аудиокнига

public:
    /**
     * @brief Конструктор с параметрами
     * @param pdf Наличие PDF версии
     * @param audio Ассоциированная аудиокнига
     */
    ElectronicPDF(bool pdf, const Audiobook& audio);

    /**
     * @brief Конструктор по умолчанию
     */
    ElectronicPDF();

    /**
     * @brief Проверить наличие PDF версии
     * @return true если PDF версия доступна, false в противном случае
     */
    bool has_pdf_version();

    /**
     * @brief Получить статус ассоциированной аудиокниги
     * @return true если аудиокнига доступна, false в противном случае
     */
    bool get_AssociatedAudiobook();
};

#endif