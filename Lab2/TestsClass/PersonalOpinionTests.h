#pragma once
#include "pch.h"
#include "D:/����/�����/2LABA/Books/Books/Book.h"

TEST(PersonalOpinionTests, PersonalOpinion_Complete) {
    PersonalOpinion opinion;
    EXPECT_EQ(opinion.get_opinion(), "���������� � ���������!");
    EXPECT_EQ(opinion.get_AssociatedPeople(), 1000);

    User testUser("Test User");
    PersonalOpinion customOpinion("�� ����������", NumberOfPeople(200, testUser));
    EXPECT_EQ(customOpinion.get_opinion(), "�� ����������");
    EXPECT_EQ(customOpinion.get_AssociatedPeople(), 200);
}