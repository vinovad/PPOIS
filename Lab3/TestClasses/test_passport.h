#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Passport.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Date.h"

class PassportTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};
TEST_F(PassportTest, ConstructorTest) {
    Passport passport("P123456", "John", "Doe", "USA", "1990-01-01", "New York", "M");
    EXPECT_EQ(passport.firstName, "John");
    EXPECT_EQ(passport.lastName, "Doe");
    EXPECT_EQ(passport.getPassportNumber(), "P123456");
}

TEST_F(PassportTest, ValidPassport) {
    Passport passport("P123456", "Alice", "Smith", "UK", "1985-05-15", "London", "F");
    EXPECT_TRUE(passport.isValid());
}

TEST_F(PassportTest, InvalidPassportEmptyNumber) {
    Passport passport("", "Bob", "Jones", "Canada", "1995-03-20", "Toronto", "M");
    EXPECT_FALSE(passport.isValid());
}

TEST_F(PassportTest, InvalidPassportEmptyName) {
    Passport passport("P789012", "", "", "Australia", "1992-07-10", "Sydney", "F");
    EXPECT_FALSE(passport.isValid());
}

TEST_F(PassportTest, GetFullName) {
    Passport passport("P345678", "Carol", "White", "Germany", "1988-11-25", "Berlin", "F");
    EXPECT_EQ(passport.getFullName(), "Carol White");
}

TEST_F(PassportTest, GetNationality) {
    Passport passport("P901234", "Dave", "Brown", "France", "1993-02-14", "Paris", "M");
    EXPECT_EQ(passport.getNationality(), "France");
}

TEST_F(PassportTest, UpdateExpiryDate) {
    Passport passport("P567890", "Eve", "Green", "Italy", "1991-09-05", "Rome", "F");
    Date* newExpiry = new Date(2030, 12, 31);
    passport.updateExpiryDate(newExpiry);
    EXPECT_TRUE(passport.isExpired());
    delete newExpiry;
}

TEST_F(PassportTest, GetBirthDate) {
    Passport passport("P111222", "Frank", "Blue", "Spain", "1987-04-18", "Madrid", "M");
    EXPECT_EQ(passport.dateOfBirth, "1987-04-18");
}

TEST_F(PassportTest, GetGender) {
    Passport passport("P333444", "Grace", "Yellow", "Portugal", "1994-06-22", "Lisbon", "F");
    EXPECT_EQ(passport.gender, "F");
}

TEST_F(PassportTest, GetPlaceOfBirth) {
    Passport passport("P555666", "Henry", "Red", "Netherlands", "1989-08-30", "Amsterdam", "M");
    EXPECT_EQ(passport.placeOfBirth, "Amsterdam");
}

