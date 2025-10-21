#pragma once
#include "pch.h"
#include "D:/����/�����/2LABA/Books/Books/Book.h"
#include "D:/����/�����/2LABA/Books/Books/GenreException.h"
#include "D:/����/�����/2LABA/Books/Books/TagException.h"
#include "D:/����/�����/2LABA/Books/Books/PublisherException.h"
#include "D:/����/�����/2LABA/Books/Books/YearException.h"
#include "D:/����/�����/2LABA/Books/Books/LanguageException.h"
#include "D:/����/�����/2LABA/Books/Books/PageCountException.h"
#include "D:/����/�����/2LABA/Books/Books/RatingException.h" 
#include "D:/����/�����/2LABA/Books/Books/AgeRestrictionException.h" 
#include "D:/����/�����/2LABA/Books/Books/BookTitleException.h" 
#include "D:/����/�����/2LABA/Books/Books/CoverFormatException.h" 
#include "D:/����/�����/2LABA/Books/Books/AuthorBooksException.h" 
#include "D:/����/�����/2LABA/Books/Books/AuthorBirthException.h" 

TEST(BookTests, Book_ExceptionHandling) {
    User user("�������� ������������");
    Book book("Fantasy", 1997, "Harry Potter", "United Kingdom",
        "����� : Joanne Rowling", "1965 ���", 15, 4.8, "Hard",
        "Bloomsbury", "Magic", "English", "A5",
        "������ ���������", 80, 400, "Harry Potter", 12,
        25.99, "USD", 15.0, "", false, 50, 600.0, "12-10-2025",
        "new", "Harry Potter", 1, "A", 1, "������", 15,
        "Bloomsbury Publishing", "United Kingdom", "United Kingdom",
        "teenagers", "middle_school", false, true, true, 1000000,
        "�������� ����� � ����� � ������������!", "���������� � ���������!",
        1000, "�����", "Harry Potter", "12-10-2025", 25.99, "�����",
        "Harry Potter", user, "Ivan", 20, true);


    EXPECT_THROW(book.set_Genre("Detective"), GenreException);
    EXPECT_THROW(book.set_Book("Other Book"), BookTitleException);
    EXPECT_THROW(book.set_Tag("Adventure"), TagException);
    EXPECT_THROW(book.set_format("Soft"), CoverFormatException);
    EXPECT_THROW(book.set_age_restriction(10), AgeRestrictionException);
    EXPECT_THROW(book.set_rating(4.5), RatingException);
    EXPECT_THROW(book.set_number_pages(300), PageCountException);
    EXPECT_THROW(book.set_publisher("Other"), PublisherException);
    EXPECT_THROW(book.set_Year("80e"), YearException);
    EXPECT_THROW(book.set_language("Russian"), LanguageException);
    EXPECT_THROW(book.set_books(10), AuthorBooksException);
    EXPECT_THROW(book.set_birth(1950), AuthorBirthException);

}