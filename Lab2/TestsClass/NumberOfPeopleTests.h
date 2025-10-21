#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

TEST(NumberOfPeopleTests, NumberOfPeople_Complete) {
    NumberOfPeople people;
    EXPECT_EQ(people.get_number_people(), 1000);
    EXPECT_EQ(people.get_AssociatedUserName(), "Гость");
    EXPECT_EQ(people.get_AssociatedUserBooks(), 0);

    User testUser("Test User");
    NumberOfPeople customPeople(500, testUser);
    EXPECT_EQ(customPeople.get_number_people(), 500);
    EXPECT_EQ(customPeople.get_AssociatedUserName(), "Test User");
}
