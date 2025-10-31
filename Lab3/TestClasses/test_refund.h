#pragma once

#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Refund.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Payment.h"

class RefundTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(RefundTest, ConstructorTest) {
    Refund refund("REF001", 1, 100.0, "Cancellation");
    EXPECT_EQ(refund.paymentId, 1);
    EXPECT_EQ(refund.amount, 100.0);
    EXPECT_EQ(refund.reason, "Cancellation");
    EXPECT_EQ(refund.getStatus(), "pending");
    EXPECT_FALSE(refund.isApproved);
}

TEST_F(RefundTest, ApproveRefund) {
    Refund refund("REF002", 2, 200.0, "Service issue");
    EXPECT_TRUE(refund.approve());
    EXPECT_TRUE(refund.isApproved);
    EXPECT_EQ(refund.getStatus(), "approved");
}

TEST_F(RefundTest, ApproveAlreadyApproved) {
    Refund refund("REF003", 3, 150.0, "Wrong booking");
    refund.approve();
    EXPECT_FALSE(refund.approve());
}

TEST_F(RefundTest, RejectRefund) {
    Refund refund("REF004", 4, 300.0, "Late request");
    EXPECT_TRUE(refund.reject());
    EXPECT_EQ(refund.getStatus(), "rejected");
}

TEST_F(RefundTest, ProcessApprovedRefund) {
    Refund refund("REF005", 5, 250.0, "Customer request");
    refund.approve();
    EXPECT_TRUE(refund.process());
    EXPECT_EQ(refund.getStatus(), "processed");
}

TEST_F(RefundTest, ProcessUnapprovedRefund) {
    Refund refund("REF006", 6, 180.0, "Policy change");
    EXPECT_FALSE(refund.process());
}

TEST_F(RefundTest, LargeAmount) {
    Refund refund("REF010", 10, 10000.0, "Major booking cancellation");
    EXPECT_GT(refund.amount, 5000.0);
}

TEST_F(RefundTest, EmptyReason) {
    Refund refund("REF011", 11, 100.0, "");
    EXPECT_EQ(refund.reason, "");
}

TEST_F(RefundTest, RejectAfterApprove) {
    Refund refund("REF013", 13, 200.0, "Test scenario");
    refund.approve();
    EXPECT_FALSE(refund.reject());
}

TEST_F(RefundTest, MultipleProcessAttempts) {
    Refund refund("REF014", 14, 275.0, "Double booking");
    refund.approve();
    EXPECT_TRUE(refund.process());
    EXPECT_FALSE(refund.process());
}

TEST_F(RefundTest, GetPaymentId) {
    Refund refund("REF015", 999, 125.0, "Payment error");
    EXPECT_EQ(refund.paymentId, 999);
}

TEST_F(RefundTest, IsComplete) {
    Refund refund("REF007", 7, 120.0, "Duplicate charge");
    refund.approve();
    refund.process();
    EXPECT_TRUE(refund.isComplete());
}

TEST_F(RefundTest, GetProcessingDays) {
    Refund refund("REF008", 8, 90.0, "Error");
    EXPECT_EQ(refund.getProcessingDays(), 7);
}

TEST_F(RefundTest, ExpediteProcessing) {
    Refund refund("REF009", 9, 500.0, "Urgent");
    refund.expediteProcessing();
    EXPECT_EQ(refund.getProcessingDays(), 3);
}
