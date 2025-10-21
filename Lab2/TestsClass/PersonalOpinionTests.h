#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

TEST(PersonalOpinionTests, PersonalOpinion_Complete) {
    PersonalOpinion opinion;
    EXPECT_EQ(opinion.get_opinion(), "Рекомендую к прочтению!");
    EXPECT_EQ(opinion.get_AssociatedPeople(), 1000);

    User testUser("Test User");
    PersonalOpinion customOpinion("Не рекомендую", NumberOfPeople(200, testUser));
    EXPECT_EQ(customOpinion.get_opinion(), "Не рекомендую");
    EXPECT_EQ(customOpinion.get_AssociatedPeople(), 200);
}