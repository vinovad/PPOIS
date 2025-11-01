/**
 * @file BookArrivalNotification.h
 * @brief Класс для работы с уведомлениями о поступлении книг
 */

#ifndef BOOKARRIVALNOTIFICATION_H
#define BOOKARRIVALNOTIFICATION_H

#include "ArrivalDate.h"
#include <string>
using namespace std;

/**
 * @class BookArrivalNotification
 * @brief Представляет уведомление о поступлении книги
 */
class BookArrivalNotification {
private:
    string book_title;
    string notification_message;
    bool is_sent;
    ArrivalDate associatedArrivalDate;
    string notification_type;
    int priority_level;
    string notification_channel;
    int retry_count;
    string status;

public:
    /**
     * @brief Конструктор с параметрами
     * @param title Название книги
     * @param arrivalDate Ассоциированная дата поступления
     */
    BookArrivalNotification(const string& title, const ArrivalDate& arrivalDate);

    /**
     * @brief Конструктор по умолчанию
     */
    BookArrivalNotification();

    /**
     * @brief Отправить уведомление
     */
    void send_notification();

    /**
     * @brief Получить название книги
     * @return Название книги
     */
    string get_book_title();

    /**
     * @brief Проверить, отправлено ли уведомление
     * @return true если уведомление отправлено, false в противном случае
     */
    bool is_notification_sent();

    /**
     * @brief Получить ассоциированную дату поступления
     * @return Дата поступления
     */
    string get_AssociatedArrivalDate();

    /**
     * @brief Сбросить статус уведомления
     */
    void reset_notification();
};

#endif
