#pragma once
#include "pch.h"
#include "D:/����/�����/2LABA/Books/Books/Book.h"

TEST(ReviewsTests, Reviews_Complete) {
    Reviews reviews;
    EXPECT_EQ(reviews.get_reviews(), "�������� ����� � ����� � ������������!");

    NumberOfReviews numberReviews;
    EXPECT_EQ(numberReviews.get_number_reviews(), 1000);
    EXPECT_EQ(numberReviews.get_AssociatedReviews(), "�������� ����� � ����� � ������������!");
}