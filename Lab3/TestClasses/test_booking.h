#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Booking.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Trip.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Hotel.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Date.h"

class BookingTest : public ::testing::Test {
protected:
    Hotel* hotel;
    Trip* trip;
    Date* date;

    void SetUp() override {
        hotel = new Hotel("Test Hotel", 100, "hotel@test.com", "555-1000");
        trip = new Trip(1, hotel, 3);
        date = new Date(2024, 1, 1);
    }

    void TearDown() override {
        delete hotel;
        delete trip;
        delete date;
    }
};

TEST_F(BookingTest, ConstructorTest) {
    Booking booking(1, trip, date, 100);
    EXPECT_EQ(booking.customer_id, 1);
    EXPECT_EQ(booking.id, 100);
    EXPECT_EQ(booking.getStatus(), 0);
}

TEST_F(BookingTest, ConfirmBooking) {
    Booking booking(1, trip, date);
    EXPECT_TRUE(booking.confirm());
    EXPECT_EQ(booking.getStatus(), 1);
}

TEST_F(BookingTest, ConfirmAlreadyConfirmed) {
    Booking booking(1, trip, date);
    booking.confirm();
    EXPECT_FALSE(booking.confirm());
}

TEST_F(BookingTest, CancelBooking) {
    Booking booking(1, trip, date);
    EXPECT_TRUE(booking.cancel());
}


TEST_F(BookingTest, DoubleConfirmReturnsFalse) {
    Booking booking(1, trip, date);
    EXPECT_TRUE(booking.confirm());
    EXPECT_FALSE(booking.confirm());
    EXPECT_EQ(booking.getStatus(), 1);  
}

TEST_F(BookingTest, StatusAfterMultipleCancels) {
    Booking booking(1, trip, date);
    booking.cancel();
    booking.status = 2;
    EXPECT_FALSE(booking.cancel()); 
}

