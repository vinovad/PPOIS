/**
 * @file Supplier.h
 * @brief Класс для работы с поставщиками книг
 */

#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "ImportCountry.h"
#include "BookCondition.h"
#include <string>
using namespace std;

/**
 * @class Supplier
 * @brief Представляет поставщика книг с информацией о стране импорта и состоянии
 */
class Supplier {
private:
    string supplier_name;               ///< Название поставщика
    ImportCountry associatedImportCountry; ///< Ассоциированная страна импорта
    BookCondition associatedBookCondition; ///< Ассоциированное состояние книги

public:
    /**
     * @brief Конструктор с параметрами
     * @param name Название поставщика
     * @param importCountry Ассоциированная страна импорта
     * @param bookCondition Ассоциированное состояние книги
     */
    Supplier(const string& name, const ImportCountry& importCountry, const BookCondition& bookCondition);

    /**
     * @brief Конструктор по умолчанию
     */
    Supplier();

    /**
     * @brief Получить название поставщика
     * @return Название поставщика
     */
    string get_supplier();

    /**
     * @brief Получить ассоциированную страну импорта
     * @return Страна импорта
     */
    string get_AssociatedImportCountry();

    /**
     * @brief Получить статус запрета импорта
     * @return true если импорт запрещен, false в противном случае
     */
    bool get_AssociatedImportProhibited();

    /**
     * @brief Получить ассоциированное состояние книги
     * @return Состояние книги
     */
    string get_AssociatedBookCondition();
};

#endif