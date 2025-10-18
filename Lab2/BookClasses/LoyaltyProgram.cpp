#include "Book.h"
#include <iostream>
using namespace std;

LoyaltyProgram::LoyaltyProgram(const User& user_obj) : associatedUser(user_obj), discount_percentage(0), has_user(true) {}
LoyaltyProgram::LoyaltyProgram() : discount_percentage(0), has_user(false) {}
void LoyaltyProgram::update_discount() {
    if (!has_user) {
        cout << "������: ������������ �� ����������" << endl;
        return;
    }
    int books_bought = associatedUser.get_books_bought();
    if (books_bought >= 5) {
        discount_percentage = 50.0;
        cout << "�����������! " << associatedUser.get_name()
            << " �������� ���������� ������ 50% �� ������� " << books_bought << " ����!" << endl;
    }
    else {
        discount_percentage = 0;
        cout << associatedUser.get_name() << " ����� " << books_bought
            << " ����. �� ������ 50% ��������: " << (5 - books_bought) << " ����" << endl;
    }
}
double LoyaltyProgram::get_discount() {
    update_discount();
    return discount_percentage;
}
double LoyaltyProgram::apply_discount(double original_price) {
    if (!has_user) {
        cout << "������: ������������ �� ����������, ������ �� �����������" << endl;
        return original_price;
    }
    double discounted_price = original_price * (1 - discount_percentage / 100);
    cout << "����: " << original_price << " USD -> �� ������� "
        << discount_percentage << "%: " << discounted_price << " USD" << endl;
    return discounted_price;
}
string LoyaltyProgram::get_AssociatedUserName() {
    if (has_user) { return associatedUser.get_name(); }
    return "������������ �� ����������";
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