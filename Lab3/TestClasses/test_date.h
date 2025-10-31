#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Date.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\DataException.h"

class DateTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};


TEST_F(DateTest, ConstructorTest) {
    Date date(27, 10, 2024);
    EXPECT_EQ(date.day, 27);
    EXPECT_EQ(date.month, 10);
    EXPECT_EQ(date.year, 2024);
}

TEST_F(DateTest, GetDay) {
    Date date(15, 5, 2024);
    EXPECT_EQ(date.getDay(), 15);
}

TEST_F(DateTest, GetMonth) {
    Date date(15, 5, 2024);
    EXPECT_EQ(date.getMonth(), 5);
}

TEST_F(DateTest, GetYear) {
    Date date(15, 5, 2024);
    EXPECT_EQ(date.getYear(), 2024);
}

TEST_F(DateTest, GetDataInString) {
    Date date(15, 5, 2024);
    std::string dateStr = date.getDataInString();
    EXPECT_FALSE(dateStr.empty());
}

TEST_F(DateTest, IsValidDate) {
    Date date1(29, 2, 2024);
    EXPECT_TRUE(date1.isValid());

    Date date2(32, 1, 2023);
    EXPECT_THROW(date2.isValid(), DataException); 
}

TEST_F(DateTest, InvalidMonth) {
    Date date(1, 13, 2024);
    EXPECT_THROW(date.isValid(), DataException);
}

TEST_F(DateTest, FutureDate) {
    Date date(31, 12, 2099);
    EXPECT_NO_THROW(date.isValid());
}

TEST_F(DateTest, InvalidDay) {
    Date date(35, 4, 2024);
    EXPECT_THROW(date.isValid(), DataException); 
}

TEST_F(DateTest, NegativeYear) {
    Date date(1, 1, -1);
    EXPECT_THROW(date.isValid(), DataException); 
}