#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"

TEST(CustomerArrivalTimeTests, CustomerArrivalTime_Complete) {
    User testUser("Test User");
    CustomerArrivalTime arrivalTime;
    EXPECT_EQ(arrivalTime.get_time(), "14:30");
    EXPECT_EQ(arrivalTime.get_day_w(), "Sunday");
    EXPECT_EQ(arrivalTime.get_day_d(), "12-10-2025");

    CustomerArrivalTime customArrival("10:00", "Monday", "2024-01-01", testUser);
    EXPECT_EQ(customArrival.get_time(), "10:00");
    EXPECT_EQ(customArrival.get_day_w(), "Monday");
    EXPECT_EQ(customArrival.get_day_d(), "2024-01-01");
}