#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/LanguageException.h" 

TEST(LanguageTests, Language_Complete) {
    Language language;
    EXPECT_EQ(language.get_language(), "English");

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(language.set_language("English"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);
    EXPECT_THROW(language.set_language("Russian"), LanguageException);
    EXPECT_THROW(language.set_language("French"), LanguageException);
    EXPECT_THROW(language.set_language("Chinese"), LanguageException);
}
