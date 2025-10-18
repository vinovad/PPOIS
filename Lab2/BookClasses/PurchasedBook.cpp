#include "Book.h"
#include <iostream>
using namespace std;

PurchasedBook::PurchasedBook(const string& title, const string& date, double price, const string& user)
    : book_title(title), purchase_date(date), purchase_price(price), user_name(user) {
}
PurchasedBook::PurchasedBook() : book_title("Harry Potter"), purchase_date("12-10-2025"),
purchase_price(25.99), user_name("Гость") {
}
string PurchasedBook::get_book_title() { return book_title; }
string PurchasedBook::get_purchase_date() { return purchase_date; }
double PurchasedBook::get_purchase_price() { return purchase_price; }
string PurchasedBook::get_user_name() { return user_name; }
void PurchasedBook::display_purchase_info() {
    cout << "Покупка: " << book_title << " | Цена: " << purchase_price
        << " | Дата: " << purchase_date << " | Покупатель: " << user_name << endl;
}