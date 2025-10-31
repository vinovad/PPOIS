#pragma once
#include <iostream>
#include "CouponException.h" 

class Coupon {
public:
    std::string code;
    double discount;
    bool used = 0;
    Coupon(std::string code, double discount);
    bool isValid();
    double getDiscountValue(double sum);
};