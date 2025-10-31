
#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Destination.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Coordinates.h"

class DestinationTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};
TEST_F(DestinationTest, ConstructorTest) {
    Destination dest("D001", "Paris", "France", "Temperate", 9);
    EXPECT_EQ(dest.name, "Paris");
    EXPECT_EQ(dest.country, "France");
    EXPECT_EQ(dest.climate, "Temperate");
    EXPECT_EQ(dest.popularityRating, 9);
}

TEST_F(DestinationTest, AddAttraction) {
    Destination dest("D002", "Rome", "Italy", "Mediterranean", 8);
    dest.addAttraction("Colosseum");
    dest.addAttraction("Vatican");
    EXPECT_EQ(dest.getAttractionCount(), 2);
}

TEST_F(DestinationTest, RemoveAttraction) {
    Destination dest("D003", "London", "UK", "Oceanic", 9);
    dest.addAttraction("Big Ben");
    dest.addAttraction("Tower Bridge");
    dest.removeAttraction(0);
    EXPECT_EQ(dest.getAttractionCount(), 1);
}

TEST_F(DestinationTest, GetDestinationId) {
    Destination dest("D004", "Tokyo", "Japan", "Humid Subtropical", 10);
    EXPECT_EQ(dest.getDestinationId(), "D004");
}

TEST_F(DestinationTest, IsVisaRequired) {
    Destination dest("D005", "New York", "USA", "Continental", 10);
    EXPECT_FALSE(dest.isVisaRequired());
    dest.requiresVisa = true;
    EXPECT_TRUE(dest.isVisaRequired());
}

TEST_F(DestinationTest, UpdateRating) {
    Destination dest("D006", "Barcelona", "Spain", "Mediterranean", 7);
    dest.updateRating(9);
    EXPECT_EQ(dest.popularityRating, 9);
}

TEST_F(DestinationTest, UpdateVisaRequirement) {
    Destination dest("D017", "Berlin", "Germany", "Temperate", 8);
    dest.requiresVisa = false;
    EXPECT_FALSE(dest.isVisaRequired());
    dest.requiresVisa = true;
    EXPECT_TRUE(dest.isVisaRequired());
}

TEST_F(DestinationTest, SetLocation) {
    Destination dest("D008", "Sydney", "Australia", "Subtropical", 9);
    Coordinates* coords = new Coordinates(33.8688, 151.2093);
    dest.setLocation(coords);
    delete coords;
}