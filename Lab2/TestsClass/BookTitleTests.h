#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/BookTitleException.h"

TEST(BookTitleTests, BookTitle_Complete) {
    BookTitle title;
    EXPECT_EQ(title.get_Book(), "Harry Potter");

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(title.set_Book("Harry Potter"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(title.set_Book("Other Book"), BookTitleException);
    EXPECT_THROW(title.set_Book("Harry"), BookTitleException);
    EXPECT_THROW(title.set_Book(""), BookTitleException);
}