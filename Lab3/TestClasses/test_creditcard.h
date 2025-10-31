#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CreditCard.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CardError.h"

class CreditCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(CreditCardTest, ConstructorTest) {
    CreditCard card("1234567890123456", "John Doe", "12/25", "123");
    EXPECT_EQ(card.number, "1234567890123456");
    EXPECT_EQ(card.holderName, "John Doe");
    EXPECT_EQ(card.expiryDate, "12/25");
    EXPECT_EQ(card.cvv, "123");
}

TEST_F(CreditCardTest, ValidCardValidation) {
    CreditCard card("1234567890123456", "Alice", "12/25", "123");
    EXPECT_TRUE(card.validate());
}

TEST_F(CreditCardTest, InvalidCardNumber) {
    CreditCard card("123", "Bob", "12/25", "123");
    EXPECT_THROW(card.validate(), CardError);
}

TEST_F(CreditCardTest, InvalidCVV) {
    CreditCard card("1234567890123456", "Carol", "12/25", "12");
    EXPECT_THROW(card.validate(), CardError);
}

TEST_F(CreditCardTest, EmptyExpiryDate) {
    CreditCard card("1234567890123456", "Dave", "", "123");
    EXPECT_THROW(card.validate(), CardError);
}

TEST_F(CreditCardTest, ChargeValidCard) {
    CreditCard card("1234567890123456", "Eve", "12/25", "123");
    EXPECT_TRUE(card.charge(100.0));
}

TEST_F(CreditCardTest, ChargeInvalidCard) {
    CreditCard card("123", "Frank", "12/25", "123");
    EXPECT_THROW(card.charge(100.0), CardError);
}

TEST_F(CreditCardTest, ChargeLargeAmount) {
    CreditCard card("1234567890123456", "Iris", "12/25", "123");
    EXPECT_TRUE(card.charge(10000.0));
}

TEST_F(CreditCardTest, EmptyCardNumber) {
    CreditCard card("", "Jack", "12/25", "123");
    EXPECT_THROW(card.validate(), CardError);
}

TEST_F(CreditCardTest, ShortCVV) {
    CreditCard card("1234567890123456", "Leo", "12/25", "1");
    EXPECT_THROW(card.validate(), CardError);
}

TEST_F(CreditCardTest, LongCVV) {
    CreditCard card("1234567890123456", "Mary", "12/25", "12345");
    EXPECT_THROW(card.validate(), CardError);
}

TEST_F(CreditCardTest, FutureExpiryDate) {
    CreditCard card("1234567890123456", "Olivia", "12/30", "123");
    EXPECT_TRUE(card.validate());
}
