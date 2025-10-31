#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Insurance.h"

class InsuranceTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(InsuranceTest, ConstructorTest) {
    Insurance insurance("POL001", "InsureCo", "Travel", 10000.0, 50.0, 1);
    EXPECT_EQ(insurance.coverageType, "Travel");
    EXPECT_EQ(insurance.coverageAmount, 10000.0);
    EXPECT_EQ(insurance.premium, 50.0);
    EXPECT_TRUE(insurance.isActive);
}

TEST_F(InsuranceTest, ValidPolicy) {
    Insurance insurance("POL002", "SafeTravel", "Medical", 50000.0, 100.0, 2);
    EXPECT_TRUE(insurance.isValidPolicy());
}

TEST_F(InsuranceTest, CalculatePremium) {
    Insurance insurance("POL003", "TravelSafe", "Comprehensive", 20000.0, 75.0, 3);
    EXPECT_EQ(insurance.calculatePremium(10), 750.0);
}

TEST_F(InsuranceTest, FileValidClaim) {
    Insurance insurance("POL004", "GlobalInsure", "Travel", 15000.0, 60.0, 4);
    EXPECT_TRUE(insurance.fileClaim(5000.0));
}

TEST_F(InsuranceTest, FileClaimExceedingCoverage) {
    Insurance insurance("POL005", "InsureAll", "Basic", 10000.0, 40.0, 5);
    EXPECT_FALSE(insurance.fileClaim(15000.0));
}

TEST_F(InsuranceTest, CancelPolicy) {
    Insurance insurance("POL006", "QuickInsure", "Standard", 8000.0, 45.0, 6);
    insurance.cancelPolicy();
    EXPECT_FALSE(insurance.isActive);
    EXPECT_FALSE(insurance.isValidPolicy());
}

TEST_F(InsuranceTest, RenewPolicy) {
    Insurance insurance("POL007", "EasyInsure", "Premium", 25000.0, 90.0, 7);
    insurance.cancelPolicy();
    insurance.renewPolicy();
    EXPECT_TRUE(insurance.isActive);
}

TEST_F(InsuranceTest, GetPolicyNumber) {
    Insurance insurance("POL008", "BestInsure", "Full", 30000.0, 120.0, 8);
    EXPECT_EQ(insurance.getPolicyNumber(), "POL008");
}
