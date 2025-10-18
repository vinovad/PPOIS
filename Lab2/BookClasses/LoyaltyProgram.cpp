#include "Book.h"
#include <iostream>
using namespace std;

LoyaltyProgram::LoyaltyProgram(const User& user_obj) : associatedUser(user_obj), discount_percentage(0), has_user(true) {}
LoyaltyProgram::LoyaltyProgram() : discount_percentage(0), has_user(false) {}
void LoyaltyProgram::update_discount() {
    if (!has_user) {
        cout << "Ошибка: пользователь не установлен" << endl;
        return;
    }
    int books_bought = associatedUser.get_books_bought();
    if (books_bought >= 5) {
        discount_percentage = 50.0;
        cout << "Поздравляем! " << associatedUser.get_name()
            << " получает постоянную скидку 50% за покупку " << books_bought << " книг!" << endl;
    }
    else {
        discount_percentage = 0;
        cout << associatedUser.get_name() << " купил " << books_bought
            << " книг. До скидки 50% осталось: " << (5 - books_bought) << " книг" << endl;
    }
}
double LoyaltyProgram::get_discount() {
    update_discount();
    return discount_percentage;
}
double LoyaltyProgram::apply_discount(double original_price) {
    if (!has_user) {
        cout << "Ошибка: пользователь не установлен, скидка не применяется" << endl;
        return original_price;
    }
    double discounted_price = original_price * (1 - discount_percentage / 100);
    cout << "Цена: " << original_price << " USD -> Со скидкой "
        << discount_percentage << "%: " << discounted_price << " USD" << endl;
    return discounted_price;
}
string LoyaltyProgram::get_AssociatedUserName() {
    if (has_user) { return associatedUser.get_name(); }
    return "Пользователь не установлен";
}
int LoyaltyProgram::get_AssociatedUserBooks() {
    if (has_user) { return associatedUser.get_books_bought(); }
    return 0;
}
void LoyaltyProgram::set_user(const User& user_obj) {
    associatedUser = user_obj;
    has_user = true;
}
bool LoyaltyProgram::has_user_set() const { return has_user; }