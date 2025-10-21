#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"


TEST(BookWeightTests, BookWeight_Complete) {
    BookWeight weight;
    EXPECT_DOUBLE_EQ(weight.get_weight(), 600.0);
    EXPECT_EQ(weight.get_AssociatedFormat(), "A5");

    BookWeight customWeight(500.0, BookFormat("A4", PageCount(200)));
    EXPECT_DOUBLE_EQ(customWeight.get_weight(), 500.0);
    EXPECT_EQ(customWeight.get_AssociatedFormat(), "A4");
}