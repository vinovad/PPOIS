#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Hotel.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Room.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Coordinates.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\RoomException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\RoomError.h"

class HotelTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
};

TEST_F(HotelTest, CostCalculation) {
    Hotel hotel1("Grand Hotel", 100, "grand@hotel.com", "+375291111111");
    Hotel hotel2("Free Stay", 0, "free@hotel.com", "+375292222222");
    Hotel hotel3("Luxury Resort", 1000, "luxury@resort.com", "+375293333333");
    Hotel hotel4("Budget Inn", 50, "budget@inn.com", "+375294444444");
    Hotel hotel5("Extended Stay", 75, "extend@stay.com", "+375295555555");
    Hotel hotel6("Error Hotel", -50, "error@hotel.com", "+375296666666");

    EXPECT_EQ(hotel1.calculateCost(3), 300);
    EXPECT_EQ(hotel2.calculateCost(5), 0);
    EXPECT_EQ(hotel3.calculateCost(7), 7000);
    EXPECT_EQ(hotel4.calculateCost(1), 50);
    EXPECT_EQ(hotel5.calculateCost(30), 2250);
    EXPECT_EQ(hotel6.calculateCost(2), -100);
}

TEST_F(HotelTest, InheritanceAndBasicFeatures) {
    Hotel hotel("Test Hotel", 100, "test@hotel.com", "+375297777777");

    EXPECT_GT(hotel.calculateCost(5), 0);

    EXPECT_EQ(hotel.email, "test@hotel.com");

    EXPECT_EQ(hotel.getStarRating(), 4);
    EXPECT_TRUE(hotel.hasPool());
}

TEST_F(HotelTest, AvailabilityAndCoordinates) {
    Hotel hotel1("Hotel Without Coords", 150, "hotel1@test.com", "+375298888888");
    Coordinates coords(34.0522, -118.2437);
    Hotel hotel2("Hotel With Coords", 200, "hotel2@test.com", "+375299999999", &coords);

    EXPECT_NO_THROW(hotel1.isAvailable());
    EXPECT_NO_THROW(hotel1.makeBusy());
    EXPECT_NO_THROW(hotel1.makeAvailable());

    EXPECT_NO_THROW(hotel1.getCoordinate());
    EXPECT_NO_THROW(hotel2.getCoordinate());
    EXPECT_FALSE(hotel2.getCoordinate().empty());
}
