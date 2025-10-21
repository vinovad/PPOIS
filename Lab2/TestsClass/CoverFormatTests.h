#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/CoverFormatException.h"


TEST(CoverFormatTests, CoverFormat_Complete) {
    Cover_Format cover;
    EXPECT_EQ(cover.get_format(), "Hard");
    EXPECT_EQ(cover.get_AssociatedPublisher(), "Bloomsbury");

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(cover.set_format("Hard"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(cover.set_format("Soft"), CoverFormatException);
    EXPECT_THROW(cover.set_format("Digital"), CoverFormatException);
    EXPECT_THROW(cover.set_format(""), CoverFormatException);
}