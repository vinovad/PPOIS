/**
 * @file ExportCountry.h
 * @brief Класс для работы со страной экспорта книги
 */

#ifndef EXPORTCOUNTRY_H
#define EXPORTCOUNTRY_H

#include "Prohibited.h"
#include <string>
using namespace std;

/**
 * @class ExportCountry
 * @brief Представляет страну экспорта книги с информацией о запретах
 */
class ExportCountry {
private:
    string export_country;      ///< Страна экспорта
    Prohibited associatedProhibited; ///< Ассоциированная информация о запрете

public:
    /**
     * @brief Конструктор с параметрами
     * @param country2 Страна экспорта
     * @param prohibited Ассоциированная информация о запрете
     */
    ExportCountry(const string& country2, const Prohibited& prohibited);

    /**
     * @brief Конструктор по умолчанию
     */
    ExportCountry();

    /**
     * @brief Получить страну экспорта
     * @return Страна экспорта
     */
    string get_export_country();

    /**
     * @brief Получить статус запрета экспорта
     * @return true если экспорт запрещен, false в противном случае
     */
    bool get_AssociatedProhibitedStatus();

    /**
     * @brief Получить страну ассоциированного запрета
     * @return Название страны запрета
     */
    string get_AssociatedProhibitedCountry();
};

#endif