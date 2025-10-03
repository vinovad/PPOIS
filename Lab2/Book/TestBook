```cpp
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "D:\Уник\ППОИС\2LABA\Books\Books\Book.cpp"
using namespace std;

TEST(AuthorTests, Author2_Complete) {
    Author2 author;
    EXPECT_EQ(author.get_Author(), " Автор : Stephen King");
    EXPECT_EQ(author.get_books(), 64);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(author.set_birth(1947));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Угадали!") != string::npos);

    EXPECT_THROW(author.set_birth(1950), Exception);
    EXPECT_THROW(author.set_birth(1800), Exception);
    EXPECT_THROW(author.set_birth(2000), Exception);
}

TEST(AuthorTests, Author3_Complete) {
    Author3 author;
    EXPECT_EQ(author.get_Author(), " Автор : Haruki Murakami");
    EXPECT_EQ(author.get_birth(), "1949 год");

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(author.set_books(14));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Угадали!") != string::npos);

    EXPECT_THROW(author.set_books(10), Exception);
    EXPECT_THROW(author.set_books(0), Exception);
    EXPECT_THROW(author.set_books(100), Exception);
}

TEST(AuthorTests, Author4_Complete) {
    Author4 author;
    EXPECT_EQ(author.get_Author(), " Автор : Umberto Eco");
    EXPECT_EQ(author.get_birth(), "1932 год");
    EXPECT_EQ(author.get_books(), 7);
}

TEST(AuthorTests, Author5_Complete) {
    Author5 author;
    EXPECT_EQ(author.get_Author(), " Автор : Lucy M. Montgomery");
    EXPECT_EQ(author.get_birth(), "1847 год");
    EXPECT_EQ(author.get_books(), 20);
}

TEST(AuthorTests, Author6_Complete) {
    Author6 author;
    EXPECT_EQ(author.get_Author(), " Автор : Andrzej Sapkowski");
    EXPECT_EQ(author.get_birth(), "1948 год");
    EXPECT_EQ(author.get_books(), 10);
}

TEST(AuthorTests, Author7_Complete) {
    Author7 author;
    EXPECT_EQ(author.get_Author(), " Автор : Charles Perrault");
    EXPECT_EQ(author.get_birth(), "1628 год");
    EXPECT_EQ(author.get_books(), 8);
}

TEST(AuthorTests, Author8_Complete) {
    Author8 author;
    EXPECT_EQ(author.get_Author(), " Автор : Liu Cixin");
    EXPECT_EQ(author.get_birth(), "1963 год");
    EXPECT_EQ(author.get_books(), 5);
}

TEST(AuthorTests, Author9_Complete) {
    Author9 author;
    EXPECT_EQ(author.get_Author(), " Автор : Leo Tolstoy");
    EXPECT_EQ(author.get_birth(), "1828 год");
    EXPECT_EQ(author.get_books(), 30);
}






// Детальные тесты для каждой книги
TEST(BookTests, BookHarryPotter_AllMethods) {
    book_HarryPotter book;

    EXPECT_EQ(book.get_Book(), "HarryPotter");
    EXPECT_EQ(book.get_number_pages(), 400);
    EXPECT_EQ(book.get_Author(), " Автор : Joanne Rowling");
    EXPECT_EQ(book.get_Year(), 1997);
    EXPECT_EQ(book.get_character(), "Гарри Поттер");
    EXPECT_EQ(book.get_Tag(), "Волшебство");
    EXPECT_EQ(book.get_publisher(), "Bloomsbury");
    EXPECT_EQ(book.get_language(), "English");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.8);
    EXPECT_EQ(book.get_format(), "Hardcover");
    EXPECT_EQ(book.get_age_restriction(), 12);

    // Тестируем сеттер с разными сценариями
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Genre("Fantasy"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_Genre("Detective"), Exception);
    EXPECT_THROW(book.set_Genre("Horror"), Exception);
    EXPECT_THROW(book.set_Genre(""), Exception);
}

TEST(BookTests, BookInstitute_AllMethods) {
    book_Institute book;

    EXPECT_EQ(book.get_Book(), "Institute");
    EXPECT_EQ(book.get_number_pages(), 500);
    EXPECT_EQ(book.get_Genre(), "Жанр:Ужасы");
    EXPECT_EQ(book.get_Author(), " Автор : Stephen King");
    EXPECT_EQ(book.get_Year(), 2019);
    EXPECT_EQ(book.get_character(), "Люк Эллис");
    EXPECT_EQ(book.get_Tag(), "Похищение");
    EXPECT_EQ(book.get_publisher(), "Scribner");
    EXPECT_EQ(book.get_language(), "English");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.3);
    EXPECT_EQ(book.get_age_restriction(), 18);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_format("Soft"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_format("Hard"), Exception);
    EXPECT_THROW(book.set_format("Digital"), Exception);
}

TEST(BookTests, BookNorwegianWood_AllMethods) {
    book_NorwegianWood book;

    EXPECT_EQ(book.get_Book(), "Norwegian Wood");
    EXPECT_EQ(book.get_number_pages(), 296);
    EXPECT_EQ(book.get_Genre(), "Жанр:Триллеры");
    EXPECT_EQ(book.get_Author(), " Автор : Haruki Murakami");
    EXPECT_EQ(book.get_Year(), 1987);
    EXPECT_EQ(book.get_character(), "Тору Ватанабэг");
    EXPECT_EQ(book.get_publisher(), "Kodansha");
    EXPECT_EQ(book.get_language(), "Japanese");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.5);
    EXPECT_EQ(book.get_format(), "Paperback");
    EXPECT_EQ(book.get_age_restriction(), 16);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Tag("Nostalgia"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_Tag("Adventure"), Exception);
    EXPECT_THROW(book.set_Tag("Romance"), Exception);
}

TEST(BookTests, BookNameOfRose_AllMethods) {
    book_Name_of_Rose book;

    EXPECT_EQ(book.get_number_pages(), 328);
    EXPECT_EQ(book.get_Genre(), "Жанр:Детектив");
    EXPECT_EQ(book.get_Author(), " Автор : Umberto Eco");
    EXPECT_EQ(book.get_Year(), 1980);
    EXPECT_EQ(book.get_character(), "Вильгельм из Баскервиля");
    EXPECT_EQ(book.get_Tag(), "Монастырь");
    EXPECT_EQ(book.get_publisher(), "Bompiani");
    EXPECT_EQ(book.get_language(), "Italian");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.6);
    EXPECT_EQ(book.get_format(), "Hardcover");
    EXPECT_EQ(book.get_age_restriction(), 16);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Book("The Name of the Rose"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_Book("Name of Rose"), Exception);
    EXPECT_THROW(book.set_Book(""), Exception);
}



TEST(BookTests, BookTheWitcher_AllMethods) {
    book_The_Witcher book;

    EXPECT_EQ(book.get_Book(), "The Witcher");
    EXPECT_EQ(book.get_number_pages(), 635);
    EXPECT_EQ(book.get_Genre(), "Жанр:Приключения");
    EXPECT_EQ(book.get_Author(), " Автор : Andrzej Sapkowski");
    EXPECT_EQ(book.get_character(), "Ведьмак");
    EXPECT_EQ(book.get_Tag(), "Adventure");
    EXPECT_EQ(book.get_publisher(), "superNOWA");
    EXPECT_EQ(book.get_language(), "Polish");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.4);
    EXPECT_EQ(book.get_format(), "Paperback");
    EXPECT_EQ(book.get_age_restriction(), 16);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_Year("90e"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_Year("80e"), Exception);
    EXPECT_THROW(book.set_Year("2000"), Exception);
}

TEST(BookTests, BookCinderella_AllMethods) {
    book_Cinderella book;

    EXPECT_EQ(book.get_Book(), "Cinderella");
    EXPECT_EQ(book.get_number_pages(), 50);
    EXPECT_EQ(book.get_Genre(), "Жанр:Классическая литература");
    EXPECT_EQ(book.get_Author(), " Автор : Charles Perrault");
    EXPECT_EQ(book.get_Year(), 1697);
    EXPECT_EQ(book.get_character(), "Золушка");
    EXPECT_EQ(book.get_Tag(), "Надежда");
    EXPECT_EQ(book.get_language(), "French");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.9);
    EXPECT_EQ(book.get_format(), "Hardcover");
    EXPECT_EQ(book.get_age_restriction(), 6);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_publisher("Barbin"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_publisher("Other"), Exception);
    EXPECT_THROW(book.set_publisher(""), Exception);
}

TEST(BookTests, BookThreeBodyProblem_AllMethods) {
    book_Three_Body_Problem book;

    EXPECT_EQ(book.get_Book(), "The Three-Body Problem");
    EXPECT_EQ(book.get_Genre(), "Жанр:Научная фантастика");
    EXPECT_EQ(book.get_Author(), " Автор : Liu Cixin");
    EXPECT_EQ(book.get_Year(), 2008);
    EXPECT_EQ(book.get_character(), "Ван Мяо");
    EXPECT_EQ(book.get_Tag(), "Космос");
    EXPECT_EQ(book.get_publisher(), "Chongqing Press");
    EXPECT_EQ(book.get_language(), "Chinese");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.2);
    EXPECT_EQ(book.get_format(), "Hardcover");
    EXPECT_EQ(book.get_age_restriction(), 14);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_number_pages(362));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_number_pages(300), Exception);
    EXPECT_THROW(book.set_number_pages(361), Exception);
    EXPECT_NO_THROW(book.set_number_pages(400));
}

TEST(BookTests, BookWarAndPeace_AllMethods) {
    book_War_and_Peace book;

    EXPECT_EQ(book.get_Book(), "War and Peace");
    EXPECT_EQ(book.get_number_pages(), 1225);
    EXPECT_EQ(book.get_Genre(), "Жанр:Классическая литература");
    EXPECT_EQ(book.get_Author(), " Автор : Leo Tolstoy");
    EXPECT_EQ(book.get_Year(), 1869);
    EXPECT_EQ(book.get_character(), "Пьеро Безруков");
    EXPECT_EQ(book.get_Tag(), "История");
    EXPECT_EQ(book.get_publisher(), "The Russian Messenger");
    EXPECT_EQ(book.get_language(), "Russian");
    EXPECT_EQ(book.get_format(), "Hardcover");
    EXPECT_EQ(book.get_age_restriction(), 14);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_rating(4.8));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_rating(4.5), Exception);
    EXPECT_THROW(book.set_rating(4.7), Exception);
    EXPECT_THROW(book.set_rating(5.1), Exception);
    EXPECT_NO_THROW(book.set_rating(4.9));
}
TEST(BookTests, BookAnneGreenGables_AllMethods) {
    book_Anne_Green_Gables book;

    // Проверяем все доступные геттеры
    EXPECT_EQ(book.get_Book(), "Anne of Green Gables");
    EXPECT_EQ(book.get_number_pages(), 310);
    EXPECT_EQ(book.get_Genre(), "Жанр:Любовный роман");
    EXPECT_EQ(book.get_Author(), " Автор : Lucy M. Montgomery");
    EXPECT_EQ(book.get_Year(), 1908);
    EXPECT_EQ(book.get_character(), "Энн Ширли");
    EXPECT_EQ(book.get_Tag(), "Сирота");
    EXPECT_EQ(book.get_publisher(), "L.C. Page & Co. ");
    // get_language() отсутствует, поэтому не тестируем
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.7);
    EXPECT_EQ(book.get_format(), "Hardcover");
    EXPECT_EQ(book.get_age_restriction(), 10);

    // Тестируем сеттер языка с разными сценариями
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_language("English"));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_language("Russian"), Exception);
    EXPECT_THROW(book.set_language("French"), Exception);
    EXPECT_THROW(book.set_language(""), Exception);
}
TEST(BookTests, BookNotreDame_AllMethods) {
    book_Notre_Dame book;

    EXPECT_EQ(book.get_Book(), "Notre-Dame de Paris)");
    EXPECT_EQ(book.get_number_pages(), 100);
    EXPECT_EQ(book.get_Genre(), "Жанр:Романтика");
    EXPECT_EQ(book.get_Author(), " Автор : Victor Hugo");
    EXPECT_EQ(book.get_Year(), 1831);
    EXPECT_EQ(book.get_character(), "Квазимодо");
    EXPECT_EQ(book.get_Tag(), "Судьба");
    EXPECT_EQ(book.get_publisher(), "Gosselin");
    EXPECT_EQ(book.get_language(), "French");
    EXPECT_DOUBLE_EQ(book.get_rating(), 4.6);
    EXPECT_EQ(book.get_format(), "Hardcover");

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(book.set_age_restriction(12));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_THROW(book.set_age_restriction(10), Exception);
    EXPECT_THROW(book.set_age_restriction(11), Exception);
    EXPECT_NO_THROW(book.set_age_restriction(18));
    EXPECT_NO_THROW(book.set_age_restriction(100));
}

int main(int argc, char** argv) {
    setlocale(0, "rus");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
