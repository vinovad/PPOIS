#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"


TEST(WorkExperienceTests, WorkExperience_Complete) {
    WorkExperience experience;
    EXPECT_EQ(experience.get_years_of_experience(), 0);

    WorkExperience customExperience(5);
    EXPECT_EQ(customExperience.get_years_of_experience(), 5);
}