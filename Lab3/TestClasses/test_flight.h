#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\EconomyClassFlight.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\BisnessClassFlight.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\HelicopterTransfer.h"

class FlightTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
};

TEST(FlightTest, AllTransportConstructors) {
    EconomyClassFlight economy(300.0, 2.0);
    BisnessClassFlight business(800.0, 2.0);
    HelicopterTransfer helicopter(500.0, 0.5);

    EXPECT_GT(economy.calculateCost(), 0);
    EXPECT_GT(business.calculateCost(), 0);
    EXPECT_GT(helicopter.calculateCost(), 0);
}

TEST(FlightTest, CostCalculation) {
    EconomyClassFlight economy(200.0, 3.0);
    BisnessClassFlight business(1000.0, 4.0);
    HelicopterTransfer helicopter(600.0, 1.0);

    EXPECT_EQ(economy.calculateCost(), 600.0);
    EXPECT_EQ(business.calculateCost(), 4000.0);
    EXPECT_EQ(helicopter.calculateCost(), 600.0);
}

TEST(FlightTest, ZeroCostCases) {
    EconomyClassFlight zeroDuration(300.0, 0.0);
    EconomyClassFlight zeroPrice(0.0, 2.0);
    HelicopterTransfer shortFlight(800.0, 0.25);

    EXPECT_EQ(zeroDuration.calculateCost(), 0.0);
    EXPECT_EQ(zeroPrice.calculateCost(), 0.0);
    EXPECT_EQ(shortFlight.calculateCost(), 200.0);
}

TEST(FlightTest, LongAndExpensiveFlights) {
    EconomyClassFlight longFlight(250.0, 10.0);
    BisnessClassFlight expensiveFlight(2000.0, 8.0);

    EXPECT_EQ(longFlight.calculateCost(), 2500.0);
    EXPECT_EQ(expensiveFlight.calculateCost(), 16000.0);
}

TEST(FlightTest, EconomyClassSpecificMethods) {
    EconomyClassFlight flight(300.0, 2.0);
    EXPECT_NO_THROW(flight.hasMealIncluded());
    EXPECT_NO_THROW(flight.getBaggageLimit());
}

TEST(FlightTest, BusinessClassSpecificMethods) {
    BisnessClassFlight flight(800.0, 2.0);
    EXPECT_NO_THROW(flight.hasLoungeAccess());
    EXPECT_NO_THROW(flight.getExtraBaggageAllowance());
}

TEST(FlightTest, HelicopterSpecificMethods) {
    HelicopterTransfer helicopter(500.0, 0.5);
    EXPECT_NO_THROW(helicopter.getMaxPassengers());
    EXPECT_NO_THROW(helicopter.isScenicFlight());
}

TEST(FlightTest, TransportComparison) {
    EconomyClassFlight economy(300.0, 2.0);
    BisnessClassFlight business(300.0, 2.0);

    EXPECT_EQ(economy.calculateCost(), business.calculateCost());
}


TEST(FlightTest, AllTransportAvailability) {
    EconomyClassFlight economy(300.0, 2.0);
    BisnessClassFlight business(800.0, 2.0);
    HelicopterTransfer helicopter(500.0, 0.5);

    auto testAvailability = [](auto& transport) {
        EXPECT_NO_THROW(transport.isAvailable());
        EXPECT_NO_THROW(transport.makeAvailable());
        EXPECT_NO_THROW(transport.makeBusy());
        EXPECT_NO_THROW(transport.makeAvailable());
        };

    testAvailability(economy);
    testAvailability(business);
    testAvailability(helicopter);
}

