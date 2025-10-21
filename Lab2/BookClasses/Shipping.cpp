#include "Book.h"
#include <iostream>
using namespace std;

Shipping::Shipping(bool shipping, const User& user)
    : has_shipping(shipping), associatedUser(user) {
}

Shipping::Shipping()
    : has_shipping(true),
    associatedUser(User("Гость")),
    shipping_type("standard"),
    shipping_cost(5.99) {
}

bool Shipping::has_shipping_available() {
    return has_shipping;
}

string Shipping::get_AssociatedUserName() {
    return associatedUser.get_name();
}

string Shipping::get_shipping_type() {
    return shipping_type;
}

double Shipping::get_shipping_cost() {
    return shipping_cost;
}

void Shipping::set_shipping_status(bool shipping) {
    has_shipping = shipping;
    if (has_shipping) {
        cout << "Доставка активирована для пользователя: " << associatedUser.get_name() << endl;
    }
    else {
        cout << "Доставка отключена для пользователя: " << associatedUser.get_name() << endl;
    }
}