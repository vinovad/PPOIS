#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

using namespace std;

TEST(SetterTests, AllSetters_ValidValues) {
    User user("Test User");
    Book book("Fantasy", 1997, "Harry Potter", "United Kingdom",
        "Автор : Joanne Rowling", "1965 год", 15, 4.8, "Hard",
        "Bloomsbury", "Magic", "English", "A5",
        "Марина Литвинова", 80, 400, "Harry Potter", 12,
        25.99, "USD", 15.0, "", false, 50, 600.0, "12-10-2025",
        "new", "Harry Potter", 1, "A", 1, "третья", 15,
        "Bloomsbury Publishing", "United Kingdom", "United Kingdom",
        "teenagers", "middle_school", false, true, true, 1000000,
        "Отличная книга о магии и приключениях!", "Рекомендую к прочтению!",
        1000, "Гость", "Harry Potter", "12-10-2025", 25.99, "Гость",
        "Harry Potter", user, "Ivan", 20, true);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Genre("Fantasy"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Book("Harry Potter"));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Tag("Magic"));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_format("Hard"));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_age_restriction(15));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_rating(4.9));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_number_pages(400));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_publisher("Bloomsbury"));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Year("90e"));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_language("English"));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_books(15));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Угадали!") != string::npos);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_birth(1965));
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Угадали!") != string::npos);
}