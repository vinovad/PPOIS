#include "Book.h"
#include <iostream>
using namespace std;

BookArrivalNotification::BookArrivalNotification(const string& title, const ArrivalDate& arrivalDate)
    : book_title(title), is_sent(false), associatedArrivalDate(arrivalDate) {
    notification_message = "Уведомление: Книга '" + book_title + "' поступила в продажу! Дата: " + associatedArrivalDate.get_arrival_date();
}
BookArrivalNotification::BookArrivalNotification() : book_title("Harry Potter"), is_sent(false), associatedArrivalDate(ArrivalDate("12-10-2025")) {
    notification_message = "Уведомление: Книга '" + book_title + "' поступила в продажу! Дата: " + associatedArrivalDate.get_arrival_date();
}
void BookArrivalNotification::send_notification() {
    if (!is_sent) {
        cout << notification_message << endl;
        is_sent = true;
    }
    else {
        cout << "Уведомление для книги '" << book_title << "' уже было отправлено" << endl;
    }
}
string BookArrivalNotification::get_book_title() { return book_title; }
bool BookArrivalNotification::is_notification_sent() { return is_sent; }
string BookArrivalNotification::get_AssociatedArrivalDate() { return associatedArrivalDate.get_arrival_date(); }
void BookArrivalNotification::reset_notification() { is_sent = false; }