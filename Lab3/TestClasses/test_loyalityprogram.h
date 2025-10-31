#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\LoyalityProgramm.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\AddingBonusesException.h"

class LoyalityProgrammTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};


TEST_F(LoyalityProgrammTest, ConstructorTest) {
    LoyalityProgramm program(100.0);
    EXPECT_EQ(program.getBonuses(), 100.0);
}

TEST_F(LoyalityProgrammTest, AddBonuses) {
    LoyalityProgramm program(50.0);
    program.addBonuses(25.0);
    EXPECT_EQ(program.getBonuses(), 75.0);
}

TEST_F(LoyalityProgrammTest, LargeBonuses) {
    LoyalityProgramm program(1000.0);
    program.addBonuses(500.0);
    EXPECT_EQ(program.getBonuses(), 1500.0);
}

TEST_F(LoyalityProgrammTest, GetBonusesNoChange) {
    LoyalityProgramm program(250.0);
    EXPECT_EQ(program.getBonuses(), 250.0);
    EXPECT_EQ(program.getBonuses(), 250.0);
}

TEST_F(LoyalityProgrammTest, NegativeStartBonuses) {
    LoyalityProgramm program(-10.0);
    EXPECT_EQ(program.getBonuses(), -10.0);
}

TEST_F(LoyalityProgrammTest, AddNegativeBonuses) {
    LoyalityProgramm program(100.0);
    EXPECT_NO_THROW(program.addBonuses(-20.0));
    EXPECT_EQ(program.getBonuses(), 100.0);
}

TEST_F(LoyalityProgrammTest, AddNegativeBonusesException) {
    LoyalityProgramm program(50.0);
    program.addBonuses(-10.0);
    EXPECT_EQ(program.getBonuses(), 50.0);
}
TEST_F(LoyalityProgrammTest, DecimalBonuses) {
    LoyalityProgramm program(100.5);
    program.addBonuses(25.75);
    EXPECT_DOUBLE_EQ(program.getBonuses(), 126.25);
}