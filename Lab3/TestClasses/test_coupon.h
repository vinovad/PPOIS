#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Coupon.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CouponException.h"

class CouponTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(CouponTest, ConstructorTest) {
    Coupon coupon("SAVE10", 10.0);
    EXPECT_EQ(coupon.code, "SAVE10");
    EXPECT_EQ(coupon.discount, 10.0);
    EXPECT_FALSE(coupon.used);
}


TEST_F(CouponTest, GetDiscountValue) {
    Coupon coupon("WINTER25", 25.0);
    double discount = coupon.getDiscountValue(100.0);
    EXPECT_EQ(discount, 25.0);
}

TEST_F(CouponTest, GetDiscountValueZeroSum) {
    Coupon coupon("PROMO10", 10.0);
    double discount = coupon.getDiscountValue(0.0);
    EXPECT_EQ(discount, 0.0);
}

TEST_F(CouponTest, ZeroDiscount) {
    Coupon coupon("ZERO", 0.0);
    double discount = coupon.getDiscountValue(100.0);
    EXPECT_EQ(discount, 0.0);
}

TEST_F(CouponTest, LargeDiscount) {
    Coupon coupon("MEGA50", 50.0);
    double discount = coupon.getDiscountValue(200.0);
    EXPECT_EQ(discount, 100.0);
}

TEST_F(CouponTest, UsedCouponThrowsException) {
    Coupon coupon("USED", 10.0);
    coupon.used = true;
    EXPECT_THROW(coupon.isValid(), CouponException);
}

TEST_F(CouponTest, UsedCouponExceptionMessage) {
    Coupon coupon("EXPIRED", 15.0);
    coupon.used = true;
    try {
        coupon.isValid();
        FAIL() << "Expected CouponException to be thrown";
    }
    catch (const CouponException& e) {
        EXPECT_EQ(std::string(e.what()), "coupon is not avialable");
    }
}

TEST_F(CouponTest, HighPercentageDiscount) {
    Coupon coupon("SUPER90", 90.0);
    double discount = coupon.getDiscountValue(1000.0);
    EXPECT_DOUBLE_EQ(discount, 900.0);
}

TEST_F(CouponTest, DecimalDiscount) {
    Coupon coupon("PRECISE", 12.5);
    double discount = coupon.getDiscountValue(80.0);
    EXPECT_DOUBLE_EQ(discount, 10.0);
}
