#pragma once

#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Coordinates.h"

class CoordinatesTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(CoordinatesTest, ConstructorTest) {
    Coordinates coords(40.7128, -74.0060);
    EXPECT_EQ(coords.latitude, 40.7128);
    EXPECT_EQ(coords.longitude, -74.0060);
}

TEST_F(CoordinatesTest, ValidLatitude) {
    Coordinates coords1(45.0, 90.0);
    EXPECT_LE(coords1.latitude, 90.0);
    EXPECT_GE(coords1.latitude, -90.0);
}

TEST_F(CoordinatesTest, ValidLongitude) {
    Coordinates coords(51.5074, -0.1278);
    EXPECT_LE(coords.longitude, 180.0);
    EXPECT_GE(coords.longitude, -180.0);
}
