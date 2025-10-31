#include "CouponException.h"

CouponException::CouponException()
    : std::runtime_error("coupon is not avialable") {}