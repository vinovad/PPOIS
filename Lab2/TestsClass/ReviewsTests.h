#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

TEST(ReviewsTests, Reviews_Complete) {
    Reviews reviews;
    EXPECT_EQ(reviews.get_reviews(), "Отличная книга о магии и приключениях!");

    NumberOfReviews numberReviews;
    EXPECT_EQ(numberReviews.get_number_reviews(), 1000);
    EXPECT_EQ(numberReviews.get_AssociatedReviews(), "Отличная книга о магии и приключениях!");
}