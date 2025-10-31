#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Review.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\ReviewException.h"

class ReviewTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(ReviewTest, ConstructorTest) {
    Review review(5, "Excellent service!", 1);
    EXPECT_EQ(review.rate, 5);
    EXPECT_EQ(review.comment, "Excellent service!");
    EXPECT_EQ(review.customer, 1);
}

TEST_F(ReviewTest, EmptyComment) {
    Review review(4, "", 5);
    EXPECT_EQ(review.comment, "");
}

TEST_F(ReviewTest, DisplayMethod) {
    Review review(4, "Good!", 7);
    EXPECT_NO_THROW(review.display());
}

TEST_F(ReviewTest, CustomerId) {
    Review review(3, "OK", 100);
    EXPECT_EQ(review.customer, 100);
}

TEST_F(ReviewTest, NegativeCustomerId) {
    Review review(4, "Nice", -1);
    EXPECT_EQ(review.customer, -1);
}

TEST_F(ReviewTest, EmptyCommentDisplay) {
    Review review(5, "", 10);
    EXPECT_NO_THROW(review.display());
}

TEST_F(ReviewTest, NonEmptyCommentDisplay) {
    Review review(5, "Great!", 11);
    EXPECT_NO_THROW(review.display());
}

TEST_F(ReviewTest, SpecialCharactersInComment) {
    Review review(4, "Good! @#$%^&*()", 14);
    EXPECT_FALSE(review.comment.empty());
}

TEST_F(ReviewTest, MultilineComment) {
    Review review(4, "Line 1\nLine 2\nLine 3", 15);
    EXPECT_FALSE(review.comment.empty());
}

TEST_F(ReviewTest, SetAndCheckId) {
    Review review(5, "Test", 16);
    review.id = 999;
    EXPECT_EQ(review.id, 999);
}
