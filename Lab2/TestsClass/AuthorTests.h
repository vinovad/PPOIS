#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/AuthorBooksException.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/AuthorBirthException.h"

TEST(AuthorTests, Author_Complete) {
    Author author;
    EXPECT_EQ(author.get_Author(), "Автор : Joanne Rowling");
    EXPECT_EQ(author.get_birth(), "1965 год");
    EXPECT_EQ(author.get_books(), 15);
    EXPECT_EQ(author.get_AssociatedCountry(), "United Kingdom");
    EXPECT_EQ(author.get_AssociatedLanguage(), "English");

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(author.set_birth(1965));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Угадали!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(author.set_books(15));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Угадали!") != string::npos);

    EXPECT_THROW(author.set_birth(1970), AuthorBirthException);
    EXPECT_THROW(author.set_birth(1800), AuthorBirthException);
    EXPECT_THROW(author.set_books(10), AuthorBooksException);
    EXPECT_THROW(author.set_books(100), AuthorBooksException);


}
