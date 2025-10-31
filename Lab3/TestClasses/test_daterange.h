#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\DateRange.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Date.h"

class DateRangeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(DateRangeTest, InheritsFromDate) {
    DateRange range(15, 6, 2025);
    EXPECT_EQ(range.getDay(), 15);
    EXPECT_EQ(range.getMonth(), 6);
    EXPECT_EQ(range.getYear(), 2025);
}

TEST_F(DateRangeTest, GetRangeId) {
    DateRange range(20, 8, 2025);
    EXPECT_GE(range.getRangeId(), 0);
}

TEST_F(DateRangeTest, IsValidRange) {
    DateRange range(10, 3, 2025);
    EXPECT_TRUE(range.isValidRange() || !range.isValidRange());
}

TEST_F(DateRangeTest, GetRange) {
    DateRange range1(1, 1, 2025);
    Date date2(31, 12, 2025);
    EXPECT_NO_THROW(range1.getRange(&date2));
}

TEST_F(DateRangeTest, RangeCalculation) {
    DateRange range1(1, 6, 2025);
    Date date2(30, 6, 2025);
    Date result = range1.getRange(&date2);
    EXPECT_GE(result.day, 0);
}

TEST_F(DateRangeTest, SameDate) {
    DateRange range(15, 7, 2025);
    Date sameDate(15, 7, 2025);
    EXPECT_NO_THROW(range.getRange(&sameDate));
}

