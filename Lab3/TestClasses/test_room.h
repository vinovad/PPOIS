#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Room.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Coordinates.h"

class RoomTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(RoomTest, ConstructorTest) {
    Room room(100);
    EXPECT_EQ(room.calculateCost(1), 100);
}

TEST_F(RoomTest, CalculateCost) {
    Room room(120);
    EXPECT_EQ(room.calculateCost(3), 360);
}

TEST_F(RoomTest, GetCoordinateWithCoords) {
    Coordinates* coords = new Coordinates(51.5074, -0.1278);
    Room room(180, coords);
    std::string result = room.getCoordinate();
    delete coords;
}
TEST_F(RoomTest, ZeroDays) {
    Room room(100);
    EXPECT_EQ(room.calculateCost(0), 0);
}

TEST_F(RoomTest, MultipleAvailabilityChanges) {
    Room room(150);
    room.makeBusy();
    room.makeAvailable();
    room.makeBusy();
    room.makeAvailable();
    EXPECT_NO_THROW(room.calculateCost(2));
}

TEST_F(RoomTest, DifferentRoomPrices) {
    Room room1(50);
    Room room2(100);
    Room room3(150);
    EXPECT_LT(room1.calculateCost(1), room2.calculateCost(1));
    EXPECT_LT(room2.calculateCost(1), room3.calculateCost(1));
}

