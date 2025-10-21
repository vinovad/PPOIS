#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"

TEST(BookConditionTests, BookCondition_Complete) {
    BookCondition condition;
    EXPECT_EQ(condition.get_condition(), "new");

    BookCondition customCondition("used");
    EXPECT_EQ(customCondition.get_condition(), "used");
}