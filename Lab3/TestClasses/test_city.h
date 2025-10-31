#pragma once
#include <gtest/gtest.h>
#include "D:\Уник\ППОИС\3LABA\Lab3\Lab3\City.h"

class CityTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(CityTest, ConstructorTest) {
    City city("New York");
    EXPECT_EQ(city.city, "New York");
}

TEST_F(CityTest, GetName) {
    City city("London");
    EXPECT_EQ(city.getName(), "London");
}

TEST_F(CityTest, GetPopulation) {
    City city("Tokyo");
    EXPECT_GE(city.getPopulation(), 0);
}
