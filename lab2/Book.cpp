#include "Book.h"

Book::Book(string genre, int year, string character, string country, string author_name,
    string author_birth, int author_books, double rating_val, string cover,
    string publisher_name, string tag_name, string language_name, string book_format,
    string translator_name, int translations_count, int page_count, string book_title,
    int age_restrict, double price_val, string currency, double discount, string sale_period,
    bool prohibited_status, int books_quantity, double weight_val, string arrival_date,
    string condition, string series_name, int volume_count, string section, int holl,
    string shelf, int position, string supplier_name, string import_country,
    string export_country, string audience, string education_lvl, bool limited_status,
    bool has_pdf, bool has_audio, int reviews_count, string review_text, string opinion,
    int people_count, string user_name, string purchased_title, string purchase_date,
    double purchase_price, string purchased_user, string notification_title, const User loyalty_user, string assistantname, int experience) :
    Genre(genre, Tag(tag_name)),
    YearOfManufacture(year),
    MainCharacter(character, BookVolumeCount(volume_count, BookSeries(series_name))),
    Country(country),
    Author(author_name, author_birth, author_books, Country(country), Language(language_name)),
    Rating(rating_val),
    Cover_Format(cover, Publisher(publisher_name)),
    Publisher(publisher_name),
    Tag(tag_name),
    Language(language_name),
    BookFormat(book_format, PageCount(page_count)),
    Translator(translator_name, NumberOfTranslations(translations_count, Language(language_name))),
    NumberOfTranslations(translations_count, Language(language_name)),
    PageCount(page_count),
    BookTitle(book_title),
    AgeRestriction(age_restrict, TargetAudience(audience, EducationLevel(education_lvl)), User(user_name)),
    Price(price_val, currency, Sale(discount, sale_period)),
    Sale(discount, sale_period),
    Prohibited(prohibited_status, Country("Belarus")),
    NumberOfBooks(books_quantity),
    BookWeight(weight_val, BookFormat(book_format, PageCount(page_count))),
    ArrivalDate(arrival_date),
    BookCondition(condition),
    BookSeries(series_name),
    BookVolumeCount(volume_count, BookSeries(series_name)),
    SectionLocation(section, ShelfLocation(shelf, PositionLocation(position))),
    HollLocation(holl, SectionLocation(section, ShelfLocation(shelf, PositionLocation(position)))),
    ShelfLocation(shelf, PositionLocation(position)),
    PositionLocation(position),
    Supplier(supplier_name, ImportCountry(import_country, Prohibited(prohibited_status, Country("Belarus"))), BookCondition(condition)),
    ImportCountry(import_country, Prohibited(prohibited_status, Country("Belarus"))),
    ExportCountry(export_country, Prohibited(prohibited_status, Country("Belarus"))),
    TargetAudience(audience, EducationLevel(education_lvl)),
    EducationLevel(education_lvl),
    LimitedSeries(limited_status, BookVolumeCount(volume_count, BookSeries(series_name))),
    ElectronicPDF(has_pdf, Audiobook(has_audio)),
    Audiobook(has_audio),
    NumberOfReviews(reviews_count, Reviews(review_text)),
    Reviews(review_text),
    PersonalOpinion(opinion, NumberOfPeople(people_count, User(user_name))),
    NumberOfPeople(people_count, User(user_name)),
    User(user_name),
    CustomerArrivalTime("14:30", "Sunday", "12-10-2025", User(user_name)),
    PurchasedBook(purchased_title, purchase_date, purchase_price, purchased_user),
    BookArrivalNotification(notification_title, ArrivalDate(arrival_date)),
    LoyaltyProgram(loyalty_user),
    WorkExperience(experience),
    AssistantName(assistantname, WorkExperience(experience))
{
}

string Book::get_Tag_Genre() { return Genre::get_AssociatedTag(); }
string Book::get_AssociatedPublisher() { return Cover_Format::get_AssociatedPublisher(); }
bool Book::get_AssociatedAudiobook() { return ElectronicPDF::get_AssociatedAudiobook(); }
string Book::get_AssociatedReviews() { return NumberOfReviews::get_AssociatedReviews(); }
int Book::get_AssociatedTranslations() { return Translator::get_AssociatedTranslations(); }
string Book::get_AssociatedFormat() { return BookWeight::get_AssociatedFormat(); }
double Book::get_AssociatedDiscount() { return Price::get_AssociatedDiscount(); }
int Book::get_AssociatedLimitedVolumeCount() { return LimitedSeries::get_AssociatedVolumeCount(); }
string Book::get_AssociatedLoyaltyUserName() { return LoyaltyProgram::get_AssociatedUserName(); }
bool Book::get_AssociatedImportProhibited() { return ImportCountry::get_AssociatedProhibitedStatus(); }
string Book::get_AssociatedAgeAudience() { return AgeRestriction::get_AssociatedAudience(); }
int Book::get_AssociatedCharacterVolumeCount() { return MainCharacter::get_AssociatedVolumeCount(); }
string Book::get_AssociatedSupplierBookCondition() { return Supplier::get_AssociatedBookCondition(); }
string Book::get_AssociatedNotificationArrivalDate() { return BookArrivalNotification::get_AssociatedArrivalDate(); }
int Book::get_AssociatedExperience() { return AssistantName::get_AssociatedExperience(); }
