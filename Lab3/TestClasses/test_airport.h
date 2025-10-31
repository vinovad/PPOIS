#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Airport.h"

class AirportTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};
TEST_F(AirportTest, ConstructorTest) {
    Airport airport("JFK", "JFK International", "New York", "USA", 6, true);
    EXPECT_EQ(airport.name, "JFK International");
    EXPECT_EQ(airport.city, "New York");
    EXPECT_EQ(airport.numberOfTerminals, 6);
    EXPECT_TRUE(airport.isInternational);
}

TEST_F(AirportTest, GetAirportCode) {
    Airport airport("LAX", "Los Angeles International", "LA", "USA", 9, true);
    EXPECT_EQ(airport.getAirportCode(), "LAX");
}

TEST_F(AirportTest, AddAirline) {
    Airport airport("ORD", "O'Hare", "Chicago", "USA", 4, true);
    airport.addAirline("United");
    airport.addAirline("American");
    EXPECT_EQ(airport.getAirlineCount(), 2);
}

TEST_F(AirportTest, RemoveAirline) {
    Airport airport("DFW", "Dallas Fort Worth", "Dallas", "USA", 5, true);
    airport.addAirline("Delta");
    airport.addAirline("Southwest");
    airport.removeAirline("Delta");
    EXPECT_EQ(airport.getAirlineCount(), 1);
}

TEST_F(AirportTest, HasInternationalFlights) {
    Airport airport("ATL", "Hartsfield-Jackson", "Atlanta", "USA", 7, true);
    EXPECT_TRUE(airport.hasInternationalFlights());
}

TEST_F(AirportTest, SetCoordinates) {
    Airport airport("LHR", "Heathrow", "London", "UK", 5, true);
    airport.setCoordinates(51.4700, -0.4543);
    EXPECT_EQ(airport.latitude, 51.4700);
    EXPECT_EQ(airport.longitude, -0.4543);
}

TEST_F(AirportTest, GetFullName) {
    Airport airport("CDG", "Charles de Gaulle", "Paris", "France", 3, true);
    EXPECT_EQ(airport.getFullName(), "Charles de Gaulle (CDG)");
}

TEST_F(AirportTest, UpgradeTerminals) {
    Airport airport("SFO", "San Francisco Int", "SF", "USA", 4, true);
    airport.upgradeTerminals(2);
    EXPECT_EQ(airport.numberOfTerminals, 6);
}

TEST_F(AirportTest, GetCountry) {
    Airport airport("NRT", "Narita", "Tokyo", "Japan", 3, true);
    EXPECT_EQ(airport.country, "Japan");
}
