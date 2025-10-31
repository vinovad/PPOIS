#pragma once
#include <string>
#include <stdexcept>

class CouponException : public std::runtime_error {
public:
    CouponException();
};