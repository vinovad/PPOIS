#include "Coupon.h"

Coupon::Coupon(std::string code, double discount) : code(code), discount(discount) {}

bool Coupon::isValid() {
    if (!used) {
        return 1;
    }
    else {
        throw CouponException();
    }
}

double Coupon::getDiscountValue(double sum) {
    return (sum * discount) / 100;
}