#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

using namespace std;

TEST(BookTests, Book_ComplexScenarios) {
    User user("Пользователь");

    Book complexBook("Mystery", 2020, "Sherlock Holmes", "United Kingdom",
        "Автор : Arthur Conan Doyle", "1859 год", 60, 4.9, "Hard",
        "Various", "Detective", "English", "A4",
        "Various Translators", 50, 350, "Sherlock Holmes", 16,
        19.99, "EUR", 10.0, "Winter Sale", false, 25, 550.0, "2024-03-01",
        "new", "Sherlock Holmes", 4, "B", 2, "первая", 10,
        "Various Publishers", "Germany", "France",
        "adults", "high_school", true, false, false, 500000,
        "Классика детективного жанра!", "Обязательно к прочтению!",
        500, "Reader", "Sherlock Holmes", "2024-02-15", 19.99, "Reader",
        "Sherlock Holmes", user, "Petr", 15, true);

    EXPECT_EQ(complexBook.get_Book(), "Sherlock Holmes");
    EXPECT_EQ(complexBook.get_Year(), 2020);
    EXPECT_EQ(complexBook.get_Author(), "Автор : Arthur Conan Doyle");
    EXPECT_DOUBLE_EQ(complexBook.get_rating(), 4.9);
    EXPECT_EQ(complexBook.get_character(), "Sherlock Holmes");
    EXPECT_EQ(complexBook.get_AssociatedPublisher(), "Various");
    EXPECT_EQ(complexBook.get_format(), "Hard");
    EXPECT_EQ(complexBook.get_age_restriction(), 16);
    EXPECT_EQ(complexBook.get_number_pages(), 350);
    EXPECT_EQ(complexBook.get_language(), "English");
    EXPECT_EQ(complexBook.get_Tag(), "Detective");
    EXPECT_EQ(complexBook.get_Genre(), "Mystery");

    EXPECT_EQ(complexBook.get_Tag_Genre(), "Detective");
    EXPECT_FALSE(complexBook.get_AssociatedAudiobook());
    EXPECT_EQ(complexBook.get_AssociatedReviews(), "Классика детективного жанра!");
    EXPECT_EQ(complexBook.get_AssociatedTranslations(), 50);
    EXPECT_EQ(complexBook.get_AssociatedFormat(), "A4");
    EXPECT_DOUBLE_EQ(complexBook.get_AssociatedDiscount(), 10.0);
    EXPECT_EQ(complexBook.get_AssociatedLimitedVolumeCount(), 4);
    EXPECT_FALSE(complexBook.get_AssociatedImportProhibited());
    EXPECT_EQ(complexBook.get_AssociatedAgeAudience(), "adults");
    EXPECT_EQ(complexBook.get_AssociatedCharacterVolumeCount(), 4);
    EXPECT_EQ(complexBook.get_AssociatedSupplierBookCondition(), "new");
    EXPECT_EQ(complexBook.get_AssociatedNotificationArrivalDate(), "2024-03-01");
    EXPECT_EQ(complexBook.get_AssociatedExperience(), 15);
}