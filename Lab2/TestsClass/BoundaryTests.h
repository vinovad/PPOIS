#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/RatingException.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/PageCountException.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/AgeRestrictionException.h"


TEST(BoundaryTests, BoundaryValues_Complete) {
    Rating rating;
    EXPECT_NO_THROW(rating.set_rating(4.8));
    EXPECT_NO_THROW(rating.set_rating(5.0));
    EXPECT_THROW(rating.set_rating(4.7), RatingException);
    EXPECT_THROW(rating.set_rating(5.1), RatingException);

    PageCount pages;
    EXPECT_NO_THROW(pages.set_number_pages(362));
    EXPECT_THROW(pages.set_number_pages(361), PageCountException);
    EXPECT_NO_THROW(pages.set_number_pages(1000));

    AgeRestriction age;
    EXPECT_NO_THROW(age.set_age_restriction(12));
    EXPECT_THROW(age.set_age_restriction(11), AgeRestrictionException);
    EXPECT_NO_THROW(age.set_age_restriction(100));
}