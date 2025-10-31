#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Station.h"

class StationTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(StationTest, ConstructorTest) {
    Station station("GCT", "Grand Central", "New York", "Train", 44);
    EXPECT_EQ(station.name, "Grand Central");
    EXPECT_EQ(station.city, "New York");
    EXPECT_EQ(station.numberOfPlatforms, 44);
    EXPECT_TRUE(station.hasWaitingRoom);
}

TEST_F(StationTest, GetStationCode) {
    Station station("PEN", "Penn Station", "New York", "Train", 21);
    EXPECT_EQ(station.getStationCode(), "PEN");
}

TEST_F(StationTest, AddFacility) {
    Station station("KGX", "Kings Cross", "London", "Train", 12);
    station.addFacility("WiFi");
    station.addFacility("Restaurant");
    EXPECT_EQ(station.getFacilityCount(), 2);
}

TEST_F(StationTest, RemoveFacility) {
    Station station("VIC", "Victoria", "London", "Train", 19);
    station.addFacility("ATM");
    station.addFacility("Shop");
    station.removeFacility("ATM");
    EXPECT_EQ(station.getFacilityCount(), 1);
}

TEST_F(StationTest, IsParkingAvailable) {
    Station station("CHI", "Chicago Union", "Chicago", "Train", 24);
    EXPECT_FALSE(station.isParkingAvailable());
    station.enableParking();
    EXPECT_TRUE(station.isParkingAvailable());
}

TEST_F(StationTest, SetCoordinates) {
    Station station("BER", "Berlin Hbf", "Berlin", "Train", 14);
    station.setCoordinates(52.5250, 13.3694);
    EXPECT_EQ(station.latitude, 52.5250);
    EXPECT_EQ(station.longitude, 13.3694);
}

TEST_F(StationTest, GetStationType) {
    Station station("BUS", "Bus Terminal", "Boston", "Bus", 10);
    EXPECT_EQ(station.getStationType(), "Bus");
}
