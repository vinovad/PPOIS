#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\TransportOption.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Car.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Bus.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Flight.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CarAgent.h"

class TransportTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};


TEST_F(TransportTest, TransportOptionConstructor) {
    TransportOption transport("Test", 100.0, 2.0);
    EXPECT_EQ(transport.calculateCost(), 200.0);
}

TEST_F(TransportTest, CarConstructor) {
    CarAgent* agent = new CarAgent("Test Agent", "agent@test.com", "555-1234");
    Car car(150.0, 2.0, agent);
    EXPECT_EQ(car.calculateCost(), 300.0);
    delete agent;
}

TEST_F(TransportTest, BusConstructor) {
    Bus bus(50.0, 3.0);
    EXPECT_EQ(bus.calculateCost(), 150.0);
}

TEST_F(TransportTest, FlightConstructor) {
    Flight flight(500.0, 1.5);
    EXPECT_EQ(flight.calculateCost(), 750.0);
}

TEST_F(TransportTest, IsAvailable) {
    TransportOption transport("Test", 100.0, 1.0);
    transport.makeAvailable();
    EXPECT_TRUE(transport.isAvailable());
}

TEST_F(TransportTest, MakeBusy) {
    TransportOption transport("Test", 100.0, 1.0);
    transport.makeBusy();
    EXPECT_FALSE(transport.isAvailable());
}

TEST_F(TransportTest, CarWithNullAgent) {
    Car car(100.0, 2.0, nullptr);
    EXPECT_EQ(car.calculateCost(), 200.0);
}

TEST_F(TransportTest, BusLongDuration) {
    Bus bus(40.0, 10.0);
    EXPECT_EQ(bus.calculateCost(), 400.0);
}

TEST_F(TransportTest, FlightShortDuration) {
    Flight flight(300.0, 0.5);
    EXPECT_EQ(flight.calculateCost(), 150.0);
}

TEST_F(TransportTest, CompareTransportCosts) {
    Bus bus(50.0, 3.0);
    Flight flight(200.0, 1.0);
    EXPECT_LT(bus.calculateCost(), flight.calculateCost());
}

TEST_F(TransportTest, InitialStateBusy) {
    TransportOption transport("Test", 100.0, 1.0);
    EXPECT_FALSE(transport.isAvailable());
}

TEST_F(TransportTest, TypeField) {
    TransportOption transport("TestType", 100.0, 1.0);
    EXPECT_EQ(transport.type, "TestType");
}

TEST_F(TransportTest, PriceField) {
    TransportOption transport("Test", 123.45, 1.0);
    EXPECT_DOUBLE_EQ(transport.price, 123.45);
}

TEST_F(TransportTest, DurationField) {
    TransportOption transport("Test", 100.0, 2.5);
    EXPECT_DOUBLE_EQ(transport.duration, 2.5);
}