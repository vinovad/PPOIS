#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"
TEST(PriceTests, Price_Complete) {
    Price price;
    EXPECT_DOUBLE_EQ(price.get_price(), 25.99);
    EXPECT_EQ(price.get_currency(), "USD");
    EXPECT_DOUBLE_EQ(price.get_AssociatedDiscount(), 15.0);
    EXPECT_EQ(price.get_AssociatedSalePeriod(), "");

    Price customPrice(19.99, "EUR", Sale(10.0, "Sale Period"));
    EXPECT_DOUBLE_EQ(customPrice.get_price(), 19.99);
    EXPECT_EQ(customPrice.get_currency(), "EUR");
    EXPECT_DOUBLE_EQ(customPrice.get_AssociatedDiscount(), 10.0);
    EXPECT_EQ(customPrice.get_AssociatedSalePeriod(), "Sale Period");
}