#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/AgeRestrictionException.h"


TEST(AgeRestrictionTests, AgeRestriction_Complete) {
    AgeRestriction age;
    EXPECT_EQ(age.get_age_restriction(), 12);
    EXPECT_EQ(age.get_AssociatedAudience(), "teenagers");
    EXPECT_EQ(age.get_AssociatedAudienceEducation(), "middle_school");
    EXPECT_EQ(age.get_AssociatedUserName(), "Гость");
    EXPECT_EQ(age.get_AssociatedUserBooks(), 0);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(age.set_age_restriction(12));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_NO_THROW(age.set_age_restriction(18));
    EXPECT_NO_THROW(age.set_age_restriction(100));

    EXPECT_THROW(age.set_age_restriction(11), AgeRestrictionException);
    EXPECT_THROW(age.set_age_restriction(10), AgeRestrictionException);
    EXPECT_THROW(age.set_age_restriction(0), AgeRestrictionException);
}