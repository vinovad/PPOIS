#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "D:\Уник\ППОИС\2LABA\Books\Books\Book.cpp"
using namespace std; 

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

TEST(AgeRestrictionTests, AgeRestriction_Complete) {
    AgeRestriction age;
    EXPECT_EQ(age.get_age_restriction(), 12);
    EXPECT_EQ(age.get_AssociatedAudience(), "teenagers");
    EXPECT_EQ(age.get_AssociatedAudienceEducation(), "middle_school");
    EXPECT_EQ(age.get_AssociatedUserName(), "Гость");
    EXPECT_EQ(age.get_AssociatedUserBooks(), 0);

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(age.set_age_restriction(12));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Хорошего чтения!") != string::npos);

    EXPECT_NO_THROW(age.set_age_restriction(18));
    EXPECT_NO_THROW(age.set_age_restriction(100));

    EXPECT_THROW(age.set_age_restriction(11), AgeRestrictionException);  
    EXPECT_THROW(age.set_age_restriction(10), AgeRestrictionException);  
    EXPECT_THROW(age.set_age_restriction(0), AgeRestrictionException);
}

TEST(NotificationTests, BookArrivalNotification_Complete) {
    BookArrivalNotification notification;
    EXPECT_EQ(notification.get_book_title(), "Harry Potter");
    EXPECT_FALSE(notification.is_notification_sent());
    EXPECT_EQ(notification.get_AssociatedArrivalDate(), "12-10-2025");

    testing::internal::CaptureStdout();
    notification.send_notification();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Harry Potter") != string::npos);
    EXPECT_TRUE(output.find("12-10-2025") != string::npos);
    EXPECT_TRUE(notification.is_notification_sent());

    // Повторная отправка
    testing::internal::CaptureStdout();
    notification.send_notification();
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("уже было отправлено") != string::npos);

    notification.reset_notification();
    EXPECT_FALSE(notification.is_notification_sent());
}

TEST(PurchasedBookTests, PurchasedBook_Complete) {
    PurchasedBook purchase;
    EXPECT_EQ(purchase.get_book_title(), "Harry Potter");
    EXPECT_EQ(purchase.get_purchase_date(), "12-10-2025");
    EXPECT_DOUBLE_EQ(purchase.get_purchase_price(), 25.99);
    EXPECT_EQ(purchase.get_user_name(), "Гость");

    testing::internal::CaptureStdout();
    purchase.display_purchase_info();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Harry Potter") != string::npos);
    EXPECT_TRUE(output.find("25.99") != string::npos);
    EXPECT_TRUE(output.find("12-10-2025") != string::npos);
}

TEST(BookSeriesTests, BookSeries_Complete) {
    BookSeries series;
    EXPECT_EQ(series.get_series_name(), "Harry Potter");

    BookSeries customSeries("The Witcher");
    EXPECT_EQ(customSeries.get_series_name(), "The Witcher");
}

TEST(BookTests, Book_ExceptionHandling) {
    User user("Тестовый пользователь");
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
        "Harry Potter", user, "Ivan", 20);

  // исключения
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

TEST(LocationTests, LocationHierarchy_Complete) {
    PositionLocation position;
    EXPECT_EQ(position.get_position(), 15);

    ShelfLocation shelf;
    EXPECT_EQ(shelf.get_shelf(), "третья");
    EXPECT_EQ(shelf.get_AssociatedPosition(), 15);

    SectionLocation section;
    EXPECT_EQ(section.get_section(), "A");
    EXPECT_EQ(section.get_AssociatedShelf(), "третья");

    HollLocation holl;
    EXPECT_EQ(holl.get_holl(), 1);
    EXPECT_EQ(holl.get_AssociatedSection(), "A");
}

//  для Supplier и связанных классов
TEST(SupplierTests, Supplier_Complete) {
    Supplier supplier;
    EXPECT_EQ(supplier.get_supplier(), "Bloomsbury Publishing");
    EXPECT_EQ(supplier.get_AssociatedImportCountry(), "United Kingdom");
    EXPECT_FALSE(supplier.get_AssociatedImportProhibited());
    EXPECT_EQ(supplier.get_AssociatedBookCondition(), "new");
}

TEST(DigitalTests, DigitalFormats_Complete) {
    Audiobook audio;
    EXPECT_TRUE(audio.has_audiobook_version());

    ElectronicPDF pdf;
    EXPECT_TRUE(pdf.has_pdf_version());
    EXPECT_TRUE(pdf.get_AssociatedAudiobook());
}

TEST(ReviewsTests, Reviews_Complete) {
    Reviews reviews;
    EXPECT_EQ(reviews.get_reviews(), "Отличная книга о магии и приключениях!");

    NumberOfReviews numberReviews;
    EXPECT_EQ(numberReviews.get_number_reviews(), 1000);
    EXPECT_EQ(numberReviews.get_AssociatedReviews(), "Отличная книга о магии и приключениях!");
}

TEST(LoyaltyProgramTests, LoyaltyProgram_Complete) {
    User user("Тестовый пользователь");
    LoyaltyProgram program(user);

    EXPECT_TRUE(program.has_user_set());
    EXPECT_EQ(program.get_AssociatedUserName(), "Тестовый пользователь");
    EXPECT_EQ(program.get_AssociatedUserBooks(), 0);

    testing::internal::CaptureStdout();
    double price1 = program.apply_discount(100.0);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_DOUBLE_EQ(price1, 100.0);
    EXPECT_TRUE(output.find("0%") != string::npos || output.find("0 %") != string::npos);

   
    User userWithDiscount("Пользователь со скидкой");
    LoyaltyProgram discountProgram(userWithDiscount);
    testing::internal::CaptureStdout();
    discountProgram.apply_discount(100.0);
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("0%") != string::npos || output.find("0 %") != string::npos);

    LoyaltyProgram emptyProgram;
    EXPECT_FALSE(emptyProgram.has_user_set());
    EXPECT_EQ(emptyProgram.get_AssociatedUserName(), "Пользователь не установлен");
}

TEST(ImportExportTests, ImportExportCountry_Complete) {
    ImportCountry importCountry;
    EXPECT_EQ(importCountry.get_import_country(), "United Kingdom");
    EXPECT_FALSE(importCountry.get_AssociatedProhibitedStatus());
    EXPECT_EQ(importCountry.get_AssociatedProhibitedCountry(), "Belarus");

    ExportCountry exportCountry;
    EXPECT_EQ(exportCountry.get_export_country(), "United Kingdom");
    EXPECT_FALSE(exportCountry.get_AssociatedProhibitedStatus());
    EXPECT_EQ(exportCountry.get_AssociatedProhibitedCountry(), "Belarus");
}

TEST(BookFormatTests, BookFormat_Complete) {
    BookFormat format;
    EXPECT_EQ(format.get_bookformat(), "A5");
    EXPECT_EQ(format.get_AssociatedPageCount(), 400);

    BookFormat customFormat("A4", PageCount(200));
    EXPECT_EQ(customFormat.get_bookformat(), "A4");
    EXPECT_EQ(customFormat.get_AssociatedPageCount(), 200);
}
TEST(BookWeightTests, BookWeight_Complete) {
    BookWeight weight;
    EXPECT_DOUBLE_EQ(weight.get_weight(), 600.0);
    EXPECT_EQ(weight.get_AssociatedFormat(), "A5");

    BookWeight customWeight(500.0, BookFormat("A4", PageCount(200)));
    EXPECT_DOUBLE_EQ(customWeight.get_weight(), 500.0);
    EXPECT_EQ(customWeight.get_AssociatedFormat(), "A4");
}


TEST(PriceTests, Price_Complete) {
    Price price;
    EXPECT_DOUBLE_EQ(price.get_price(), 25.99);
    EXPECT_EQ(price.get_currency(), "USD");
    EXPECT_DOUBLE_EQ(price.get_AssociatedDiscount(), 15.0);
    EXPECT_EQ(price.get_AssociatedSalePeriod(), "");

    Price customPrice(19.99, "EUR", Sale(10.0, "Sale Period"));
    EXPECT_DOUBLE_EQ(customPrice.get_price(), 19.99);
    EXPECT_EQ(customPrice.get_currency(), "EUR");
    EXPECT_DOUBLE_EQ(customPrice.get_AssociatedDiscount(), 10.0);
    EXPECT_EQ(customPrice.get_AssociatedSalePeriod(), "Sale Period");
}
TEST(NumberOfBooksTests, NumberOfBooks_Complete) {
    NumberOfBooks books;
    EXPECT_EQ(books.get_quantity(), 50);

    NumberOfBooks customBooks(100);
    EXPECT_EQ(customBooks.get_quantity(), 100);
}

TEST(BookConditionTests, BookCondition_Complete) {
    BookCondition condition;
    EXPECT_EQ(condition.get_condition(), "new");

    BookCondition customCondition("used");
    EXPECT_EQ(customCondition.get_condition(), "used");
}

TEST(BookVolumeCountTests, BookVolumeCount_Complete) {
    BookVolumeCount volumeCount;
    EXPECT_EQ(volumeCount.get_volume_number(), 7);
    EXPECT_EQ(volumeCount.get_AssociatedSeries(), "Harry Potter");

    BookVolumeCount customVolumeCount(3, BookSeries("The Witcher"));
    EXPECT_EQ(customVolumeCount.get_volume_number(), 3);
    EXPECT_EQ(customVolumeCount.get_AssociatedSeries(), "The Witcher");
}
TEST(NumberOfPeopleTests, NumberOfPeople_Complete) {
    NumberOfPeople people;
    EXPECT_EQ(people.get_number_people(), 1000);
    EXPECT_EQ(people.get_AssociatedUserName(), "Гость");
    EXPECT_EQ(people.get_AssociatedUserBooks(), 0);

    User testUser("Test User");
    NumberOfPeople customPeople(500, testUser);
    EXPECT_EQ(customPeople.get_number_people(), 500);
    EXPECT_EQ(customPeople.get_AssociatedUserName(), "Test User");
}

TEST(PersonalOpinionTests, PersonalOpinion_Complete) {
    PersonalOpinion opinion;
    EXPECT_EQ(opinion.get_opinion(), "Рекомендую к прочтению!");
    EXPECT_EQ(opinion.get_AssociatedPeople(), 1000);

    User testUser("Test User");
    PersonalOpinion customOpinion("Не рекомендую", NumberOfPeople(200, testUser));
    EXPECT_EQ(customOpinion.get_opinion(), "Не рекомендую");
    EXPECT_EQ(customOpinion.get_AssociatedPeople(), 200);
}

TEST(CustomerArrivalTimeTests, CustomerArrivalTime_Complete) {
    User testUser("Test User");
    CustomerArrivalTime arrivalTime;
    EXPECT_EQ(arrivalTime.get_time(), "14:30");
    EXPECT_EQ(arrivalTime.get_day_w(), "Sunday");
    EXPECT_EQ(arrivalTime.get_day_d(), "12-10-2025");

    CustomerArrivalTime customArrival("10:00", "Monday", "2024-01-01", testUser);
    EXPECT_EQ(customArrival.get_time(), "10:00");
    EXPECT_EQ(customArrival.get_day_w(), "Monday");
    EXPECT_EQ(customArrival.get_day_d(), "2024-01-01");
}

TEST(WorkExperienceTests, WorkExperience_Complete) {
    WorkExperience experience;
    EXPECT_EQ(experience.get_years_of_experience(), 0);

    WorkExperience customExperience(5);
    EXPECT_EQ(customExperience.get_years_of_experience(), 5);
}

TEST(AssistantNameTests, AssistantName_Complete) {
    AssistantName assistant;
    EXPECT_EQ(assistant.get_name(), "Неизвестный");
    EXPECT_EQ(assistant.get_AssociatedExperience(), 0);

    AssistantName customAssistant("John", WorkExperience(10));
    EXPECT_EQ(customAssistant.get_name(), "John");
    EXPECT_EQ(customAssistant.get_AssociatedExperience(), 10);
}

TEST(BoundaryTests, BoundaryValues_Complete) {
    Rating rating;
    EXPECT_NO_THROW(rating.set_rating(4.8));
    EXPECT_NO_THROW(rating.set_rating(5.0));
    EXPECT_THROW(rating.set_rating(4.7), RatingException);        
    EXPECT_THROW(rating.set_rating(5.1), RatingException);        

    PageCount pages;
    EXPECT_NO_THROW(pages.set_number_pages(362));
    EXPECT_THROW(pages.set_number_pages(361), PageCountException); 
    EXPECT_NO_THROW(pages.set_number_pages(1000));

    AgeRestriction age;
    EXPECT_NO_THROW(age.set_age_restriction(12));
    EXPECT_THROW(age.set_age_restriction(11), AgeRestrictionException); 
    EXPECT_NO_THROW(age.set_age_restriction(100));
} 

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
        "Sherlock Holmes", user, "Petr", 15);

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

    //связанные методы
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

TEST(StateChangeTests, StateModification_Complete) {
    YearOfManufacture year;
    year.set_Year(2005);
    EXPECT_EQ(year.get_Year(), 2005);

    PageCount pages;
    pages.set_number_pages(500);
    EXPECT_EQ(pages.get_number_pages(), 500);

    User user("Test User");
    user.add_purchased_book();
    user.add_purchased_book();
    EXPECT_EQ(user.get_books_bought(), 2);

    BookArrivalNotification notification;
    notification.send_notification();
    EXPECT_TRUE(notification.is_notification_sent());
    notification.reset_notification();
    EXPECT_FALSE(notification.is_notification_sent());
}

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
        "Harry Potter", user, "Ivan", 20);

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
int main(int argc, char** argv) {
    setlocale(0, "rus");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}