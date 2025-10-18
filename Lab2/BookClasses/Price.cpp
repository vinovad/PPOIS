#include "Book.h"
using namespace std;

Price::Price(double p, const string& curr, const Sale& sale)
    : price(p), currency(curr), associatedSale(sale) {
}

Price::Price() : price(25.99), currency("USD"), associatedSale(Sale(15.0, "")) {
}

double Price::get_price() {
    return price;
}

string Price::get_currency() {
    return currency;
}

double Price::get_AssociatedDiscount() {
    return associatedSale.get_discount();
}

string Price::get_AssociatedSalePeriod() {
    return associatedSale.get_sale_period();
}