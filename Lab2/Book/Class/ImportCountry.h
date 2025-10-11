
/**
 * @file ImportCountry.h
 * @brief Класс для работы со страной импорта книги
 */

#ifndef IMPORTCOUNTRY_H
#define IMPORTCOUNTRY_H

#include "Prohibited.h"
#include <string>
using namespace std;

/**
 * @class ImportCountry
 * @brief Представляет страну импорта книги с информацией о запретах
 */
class ImportCountry {
private:
    string import_country;      ///< Страна импорта
    Prohibited associatedProhibited; ///< Ассоциированная информация о запрете

public:
    /**
     * @brief Конструктор с параметрами
     * @param country Страна импорта
     * @param prohibited Ассоциированная информация о запрете
     */
    ImportCountry(const string& country, const Prohibited& prohibited);
    
    /**
     * @brief Конструктор по умолчанию
     */
    ImportCountry();
    
    /**
     * @brief Получить страну импорта
     * @return Страна импорта
     */
    string get_import_country();
    
    /**
     * @brief Получить статус запрета импорта
     * @return true если импорт запрещен, false в противном случае
     */
    bool get_AssociatedProhibitedStatus();
    
    /**
     * @brief Получить страну ассоциированного запрета
     * @return Название страны запрета
     */
    string get_AssociatedProhibitedCountry();
};

#endif

