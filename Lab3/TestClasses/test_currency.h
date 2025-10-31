#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Currency.h"

class CurrencyTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(CurrencyTest, ConstructorTest) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    EXPECT_EQ(usd.name, "US Dollar");
    EXPECT_EQ(usd.symbol, "$");
    EXPECT_TRUE(usd.isActive);
}

TEST_F(CurrencyTest, SetExchangeRate) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.setExchangeRate("EUR", 0.85);
    EXPECT_EQ(usd.getExchangeRate("EUR"), 0.85);
}

TEST_F(CurrencyTest, Convert) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.setExchangeRate("EUR", 0.85);
    EXPECT_EQ(usd.convert(100, "EUR"), 85.0);
}

TEST_F(CurrencyTest, ConvertUnknownCurrency) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    EXPECT_EQ(usd.convert(100, "GBP"), 100.0);
}

TEST_F(CurrencyTest, IsSupported) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.setExchangeRate("EUR", 0.85);
    EXPECT_TRUE(usd.isSupported("EUR"));
    EXPECT_FALSE(usd.isSupported("JPY"));
}

TEST_F(CurrencyTest, Format) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    std::string formatted = usd.format(123.45);
    EXPECT_NE(formatted.find("$"), std::string::npos);
}

TEST_F(CurrencyTest, UpdateBaseRate) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.updateBaseRate(1.05);
    EXPECT_EQ(usd.baseRate, 1.05);
}

TEST_F(CurrencyTest, ZeroConversion) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.setExchangeRate("EUR", 0.85);
    EXPECT_EQ(usd.convert(0, "EUR"), 0.0);
}

TEST_F(CurrencyTest, NegativeConversion) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.setExchangeRate("EUR", 0.85);
    EXPECT_EQ(usd.convert(-100, "EUR"), -85.0);
}

TEST_F(CurrencyTest, LargeConversion) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.setExchangeRate("EUR", 0.85);
    EXPECT_EQ(usd.convert(1000000, "EUR"), 850000.0);
}

TEST_F(CurrencyTest, GetRateCount) {
    Currency usd("USD", "US Dollar", "$", "USA", 1.0);
    usd.setExchangeRate("EUR", 0.85);
    usd.setExchangeRate("GBP", 0.73);
    EXPECT_EQ(usd.getRateCount(), 2);
}