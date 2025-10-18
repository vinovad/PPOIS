#include "Book.h"
using namespace std;
Sale::Sale(double discount, const string& period)
    : discount_percentage(discount), sale_period(period) {
}
Sale::Sale() : discount_percentage(15.0), sale_period("") {
}
double Sale::get_discount() {
    return discount_percentage;
}
string Sale::get_sale_period() {
    return sale_period;
}