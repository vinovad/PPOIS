#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

TEST(AssistantNameTests, AssistantName_Complete) {
    AssistantName assistant;
    EXPECT_EQ(assistant.get_name(), "Неизвестный");
    EXPECT_EQ(assistant.get_AssociatedExperience(), 0);

    AssistantName customAssistant("John", WorkExperience(10));
    EXPECT_EQ(customAssistant.get_name(), "John");
    EXPECT_EQ(customAssistant.get_AssociatedExperience(), 10);
}