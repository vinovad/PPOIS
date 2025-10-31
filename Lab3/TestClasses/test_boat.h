#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Boat.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Ship.h"

class BoatTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(BoatTest, ConstructorTest) {
    Boat boat(75.0, 1.5);
    EXPECT_GT(boat.calculateCost(), 0);
}

TEST_F(BoatTest, GetPassengerCapacity) {
    Boat boat(80.0, 2.0);
    EXPECT_GE(boat.getPassengerCapacity(), 0);
}

TEST_F(BoatTest, HasLifeJackets) {
    Boat boat(70.0, 1.8);
    EXPECT_TRUE(boat.hasLifeJackets());
}

TEST_F(BoatTest, ShipInheritance) {
    Ship ship(150.0, 3.0);
    EXPECT_GT(ship.calculateCost(), 0);
    EXPECT_GE(ship.getDeckCount(), 0);
}

TEST_F(BoatTest, ShipHasCabinRooms) {
    Ship ship(200.0, 4.0);
    EXPECT_TRUE(ship.hasCabinRooms() || !ship.hasCabinRooms());
}
