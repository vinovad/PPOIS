#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Port.h"

class PortTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(PortTest, ConstructorTest) {
    Port port("NYC", "Port of New York", "New York", "USA", 12, true, true);
    EXPECT_EQ(port.name, "Port of New York");
    EXPECT_EQ(port.city, "New York");
    EXPECT_EQ(port.numberOfDocks, 12);
    EXPECT_TRUE(port.isCruisePort);
    EXPECT_TRUE(port.isCargoPort);
}

TEST_F(PortTest, GetPortCode) {
    Port port("LAX", "Port of LA", "Los Angeles", "USA", 20, false, true);
    EXPECT_EQ(port.getPortCode(), "LAX");
}

TEST_F(PortTest, AddService) {
    Port port("MIA", "Port of Miami", "Miami", "USA", 8, true, false);
    port.addService("Customs");
    port.addService("Refueling");
    EXPECT_EQ(port.getServiceCount(), 2);
}

TEST_F(PortTest, RemoveService) {
    Port port("SEA", "Port of Seattle", "Seattle", "USA", 15, true, true);
    port.addService("Immigration");
    port.addService("Maintenance");
    port.removeService("Immigration");
    EXPECT_EQ(port.getServiceCount(), 1);
}

TEST_F(PortTest, SupportsCruises) {
    Port port("SYD", "Sydney Harbor", "Sydney", "Australia", 10, true, false);
    EXPECT_TRUE(port.supportsCruises());
}

TEST_F(PortTest, SupportsCargo) {
    Port port("HOU", "Port of Houston", "Houston", "USA", 25, false, true);
    EXPECT_TRUE(port.supportsCargo());
}

TEST_F(PortTest, SetCoordinates) {
    Port port("TOK", "Port of Tokyo", "Tokyo", "Japan", 18, true, true);
    port.setCoordinates(35.6528, 139.7594);
    EXPECT_DOUBLE_EQ(port.latitude, 35.6528);
    EXPECT_DOUBLE_EQ(port.longitude, 139.7594);
}

TEST_F(PortTest, NoServices) {
    Port port("NSV", "Basic Port", "Town", "Country", 4, false, false);
    EXPECT_FALSE(port.isCruisePort);
    EXPECT_FALSE(port.isCargoPort);
}

TEST_F(PortTest, RemoveNonExistentService) {
    Port port("REM", "Test Port", "TestCity", "TestNation", 10, true, false);
    port.addService("WiFi");
    EXPECT_NO_THROW(port.removeService("NonExistent"));
}

TEST_F(PortTest, GetCountry) {
    Port port("CNT", "National Port", "Capital", "TestCountry", 12, true, true);
    EXPECT_EQ(port.country, "TestCountry");
}

TEST_F(PortTest, ExpandDocks) {
    Port port("HKG", "Hong Kong Port", "Hong Kong", "China", 18, true, true);
    port.expandDocks(5);
    EXPECT_EQ(port.numberOfDocks, 23);
}

TEST_F(PortTest, GetFullName) {
    Port port("SIN", "Singapore Port", "Singapore", "Singapore", 30, true, true);
    EXPECT_EQ(port.getFullName(), "Singapore Port (SIN)");
}
