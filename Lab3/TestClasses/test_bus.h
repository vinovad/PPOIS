#pragma once
#include <gtest/gtest.h>
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\ExpressBus.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\LuxuryBus.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\SleeperBus.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\MiniBus.h"

class BusTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
};

TEST_F(BusTest, AllBusTypesConstructor) {
    ExpressBus express(60.0, 3.0);
    LuxuryBus luxury(100.0, 4.0);
    SleeperBus sleeper(80.0, 8.0);
    MiniBus mini(40.0, 2.0);

    EXPECT_GT(express.calculateCost(), 0);
    EXPECT_GT(luxury.calculateCost(), 0);
    EXPECT_GT(sleeper.calculateCost(), 0);
    EXPECT_GT(mini.calculateCost(), 0);
}

TEST_F(BusTest, CostCalculation) {
    ExpressBus express(50.0, 2.0);
    LuxuryBus luxury(150.0, 3.0);
    SleeperBus sleeper(70.0, 12.0);
    MiniBus mini(30.0, 1.0);

    EXPECT_EQ(express.calculateCost(), 100.0);
    EXPECT_EQ(luxury.calculateCost(), 450.0);
    EXPECT_EQ(sleeper.calculateCost(), 840.0);
    EXPECT_EQ(mini.calculateCost(), 30.0);
}

TEST_F(BusTest, ZeroCostCases) {
    MiniBus zeroPrice(0.0, 1.0);
    ExpressBus zeroDuration(50.0, 0.0);

    EXPECT_EQ(zeroPrice.calculateCost(), 0.0);
    EXPECT_EQ(zeroDuration.calculateCost(), 0.0);
}

TEST_F(BusTest, NegativeValues) {
    ExpressBus negativePrice(-50.0, 2.0);
    LuxuryBus negativeDuration(100.0, -2.0);

    EXPECT_LE(negativePrice.calculateCost(), 0);
    EXPECT_LE(negativeDuration.calculateCost(), 0);
}

TEST_F(BusTest, ExpressBusSpecificMethods) {
    ExpressBus bus(60.0, 3.0);
    EXPECT_NO_THROW(bus.getHasWiFi());
    EXPECT_NO_THROW(bus.getTravelTime());
}

TEST_F(BusTest, LuxuryBusSpecificMethods) {
    LuxuryBus bus(100.0, 4.0);
    EXPECT_NO_THROW(bus.getHasEntertainmentSystem());
    EXPECT_NO_THROW(bus.getLuxuryLevel());
}

TEST_F(BusTest, SleeperBusSpecificMethods) {
    SleeperBus bus(80.0, 8.0);
    EXPECT_NO_THROW(bus.getBedCount());
    EXPECT_NO_THROW(bus.hasToilet());
}

TEST_F(BusTest, MiniBusSpecificMethods) {
    MiniBus bus(40.0, 2.0);
    EXPECT_NO_THROW(bus.getSeatCount());
    EXPECT_NO_THROW(bus.isEcoFriendly());
}

TEST_F(BusTest, TransportOptionInheritance) {
    ExpressBus* express = new ExpressBus(60.0, 3.0);
    LuxuryBus* luxury = new LuxuryBus(100.0, 4.0);
    SleeperBus* sleeper = new SleeperBus(80.0, 8.0);
    MiniBus* mini = new MiniBus(40.0, 2.0);

    TransportOption* transports[] = { express, luxury, sleeper, mini };

    for (auto* transport : transports) {
        EXPECT_NE(transport, nullptr);
        EXPECT_NO_THROW(transport->calculateCost());
        EXPECT_NO_THROW(transport->isAvailable());
    }

    delete express;
    delete luxury;
    delete sleeper;
    delete mini;
}
