#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Visa.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Passport.h"

class VisaTest : public ::testing::Test {
protected:
    Passport* passport;

    void SetUp() override {
        passport = new Passport("P123456", "John", "Doe", "USA", "1990-01-01", "NYC", "M");
    }

    void TearDown() override {
        delete passport;
    }
};

TEST_F(VisaTest, ConstructorTest) {
    Visa visa("V001", "France", "Tourist", 30, false, "Tourism", passport);
    EXPECT_EQ(visa.country, "France");
    EXPECT_EQ(visa.duration, 30);
    EXPECT_FALSE(visa.isMultipleEntry);
}

TEST_F(VisaTest, ValidVisa) {
    Visa visa("V002", "Germany", "Business", 90, true, "Business", passport);
    EXPECT_TRUE(visa.isValid());
}

TEST_F(VisaTest, InvalidVisaEmptyNumber) {
    Visa visa("", "Italy", "Tourist", 60, false, "Tourism", passport);
    EXPECT_FALSE(visa.isValid());
}

TEST_F(VisaTest, GetVisaNumber) {
    Visa visa("V003", "Spain", "Student", 180, false, "Study", passport);
    EXPECT_EQ(visa.getVisaNumber(), "V003");
}

TEST_F(VisaTest, ExtendVisa) {
    Visa visa("V004", "UK", "Work", 365, true, "Work", passport);
    visa.extendVisa(90);
    EXPECT_EQ(visa.getRemainingDays(), 455);
}

TEST_F(VisaTest, RequiresPassport) {
    Visa visa("V005", "Japan", "Tourist", 30, false, "Tourism", passport);
    EXPECT_TRUE(visa.requiresPassport());
}

TEST_F(VisaTest, NoPassport) {
    Visa visa("V006", "Canada", "Tourist", 30, false, "Tourism", nullptr);
    EXPECT_FALSE(visa.requiresPassport());
}

TEST_F(VisaTest, GetCountry) {
    Visa visa("V014", "Switzerland", "Tourist", 90, false, "Tourism", passport);
    EXPECT_EQ(visa.country, "Switzerland");
}

TEST_F(VisaTest, GetPurpose) {
    Visa visa("V015", "Norway", "Business", 60, true, "Business", passport);
    EXPECT_EQ(visa.purpose, "Business");
}
