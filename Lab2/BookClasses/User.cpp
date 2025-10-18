#include "Book.h"
#include <iostream>
using namespace std;

User::User(const string& user_name) : name(user_name), books_bought(0) {}
User::User() : name("Гость"), books_bought(0) {}
string User::get_name() { return name; }
int User::get_books_bought() { return books_bought; }
void User::add_purchased_book() {
    books_bought++;
    cout << name << " купил книгу. Всего книг: " << books_bought << endl;
}