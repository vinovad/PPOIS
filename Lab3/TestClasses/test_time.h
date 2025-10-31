#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\TimeClass.h"

class TimeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};
TEST_F(TimeTest, ConstructorTest) {
    TimeClass time(3661);
    EXPECT_GE(time.hour, 0);
    EXPECT_GE(time.min, 0);
    EXPECT_GE(time.sec, 0);
}

TEST_F(TimeTest, GetHour) {
    TimeClass time(7200);
    EXPECT_EQ(time.getHour(), 2);
}

TEST_F(TimeTest, GetMin) {
    TimeClass time(3600 + 1800);
    EXPECT_EQ(time.getMin(), 30);
}

TEST_F(TimeTest, GetSec) {
    TimeClass time(3615);
    EXPECT_EQ(time.getSec(), 15);
}

TEST_F(TimeTest, GetTimeInString) {
    TimeClass time(3661);
    std::string timeStr = time.getTimeInString();
    EXPECT_FALSE(timeStr.empty());
}

TEST_F(TimeTest, CompareTime) {
    TimeClass time1(3600);
    TimeClass time2(7200);
    EXPECT_LT(time1.getHour(), time2.getHour());
}


