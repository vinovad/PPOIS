#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Payment.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CreditCard.h"

class PaymentTest : public ::testing::Test {
protected:
    CreditCard* card;

    void SetUp() override {
        card = new CreditCard("1234567890123456", "Test User", "12/25", "123");
    }

    void TearDown() override {
        delete card;
    }
};


TEST_F(PaymentTest, ConstructorTest) {
    Payment payment("TXN001", 1, 100.0, "credit_card", "USD", 1);
    EXPECT_EQ(payment.bookingId, 1);
    EXPECT_EQ(payment.amount, 100.0);
    EXPECT_EQ(payment.currency, "USD");
    EXPECT_EQ(payment.getStatus(), "pending");
}

TEST_F(PaymentTest, ProcessPaymentWithCreditCard) {
    Payment payment("TXN002", 1, 50.0, "credit_card", "USD", 1);
    payment.setCreditCard(card);
    EXPECT_TRUE(payment.processPayment());
    EXPECT_EQ(payment.getStatus(), "completed");
}

TEST_F(PaymentTest, ProcessPaymentWithoutCreditCard) {
    Payment payment("TXN003", 1, 50.0, "cash", "USD", 1);
    EXPECT_TRUE(payment.processPayment());
    EXPECT_TRUE(payment.isSuccessful());
}

TEST_F(PaymentTest, ProcessPaymentWithInvalidAmount) {
    Payment payment("TXN004", 1, -10.0, "credit_card", "USD", 1);
    EXPECT_FALSE(payment.processPayment());
    EXPECT_EQ(payment.getStatus(), "failed");
}

TEST_F(PaymentTest, RefundSuccessfulPayment) {
    Payment payment("TXN005", 1, 100.0, "cash", "USD", 1);
    payment.processPayment();
    EXPECT_TRUE(payment.refund());
    EXPECT_EQ(payment.getStatus(), "refunded");
}

TEST_F(PaymentTest, RefundPendingPayment) {
    Payment payment("TXN006", 1, 100.0, "cash", "USD", 1);
    EXPECT_FALSE(payment.refund());
}

TEST_F(PaymentTest, GenerateReceipt) {
    Payment payment("TXN007", 1, 100.0, "cash", "USD", 1);
    std::string receipt = payment.generateReceipt();
    EXPECT_EQ(receipt, "RCP_TXN007");
}

TEST_F(PaymentTest, ZeroAmountPayment) {
    Payment payment("TXN008", 1, 0.0, "cash", "USD", 1);
    EXPECT_FALSE(payment.processPayment());
}

TEST_F(PaymentTest, MultiplePaymentMethods) {
    Payment payment1("TXN009", 1, 100.0, "credit_card", "USD", 1);
    Payment payment2("TXN010", 1, 100.0, "debit_card", "USD", 1);
    Payment payment3("TXN011", 1, 100.0, "paypal", "USD", 1);
    EXPECT_NO_THROW(payment1.processPayment());
    EXPECT_NO_THROW(payment2.processPayment());
    EXPECT_NO_THROW(payment3.processPayment());
}

TEST_F(PaymentTest, GetTransactionId) {
    Payment payment("TXN016", 1, 50.0, "cash", "USD", 1);
    EXPECT_EQ(payment.getTransactionId(), "TXN016");
}

TEST_F(PaymentTest, GetBookingId) {
    Payment payment("TXN017", 999, 75.0, "cash", "USD", 1);
    EXPECT_EQ(payment.bookingId, 999);
}

