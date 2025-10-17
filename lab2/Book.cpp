#include "Book.h"
#include <iostream>
#include "TagException.h"
#include "GenreException.h"
#include "YearException.h"
#include "LanguageException.h"
#include "AuthorBirthException.h"
#include "AuthorBooksException.h"
#include "RatingException.h"
#include "PublisherException.h"
#include "PageCountException.h"
#include "BookTitleException.h"
#include "AgeRestrictionException.h"
#include "CoverFormatException.h"
using namespace std;

Tag::Tag(const string& t) : book_tag(t) {}
Tag::Tag() : book_tag("Magic") {}
string Tag::get_Tag() { return book_tag; }

void Tag::set_Tag(string tg) {
    if (tg != "Magic") {
        throw TagException("Данная книга не содержит данного тега");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    book_tag = tg;
}
 
Genre::Genre(const string& g, const Tag& tag) : genre(g), associatedTag(tag) {}
Genre::Genre() : genre("Fantasy"), associatedTag(Tag("Magic")) {}
string Genre::get_Genre() { return genre; }
string Genre::get_AssociatedTag() { return associatedTag.get_Tag(); }

void Genre::set_Genre(string gen) {
    if (gen != "Fantasy") {
        throw GenreException("Данная книга не относится к этому жанру");
    }
    else {
        cout << "Книга Harry Potter относится к жанру Фэнтези. Хорошего чтения!" << endl;
    }
}
 
YearOfManufacture::YearOfManufacture(int y) : year(y) {}
YearOfManufacture::YearOfManufacture() : year(1997) {}
int YearOfManufacture::get_Year() { return year; }
void YearOfManufacture::set_Year(int y) { year = y; }

void YearOfManufacture::set_Year(string g) {
    if (g != "90e") {
        throw YearException("Данная книга не относится к этому времени");
    }
    else {
        cout << "Данная книга 1997 года. Хорошего чтения!" << endl;
    }
}
 
Country::Country(const string& c) : country(c) {}
Country::Country() : country("United Kingdom") {}
string Country::get_country() { return country; }
 
Language::Language(const string& l) : language(l) {}
Language::Language() : language("English") {}
string Language::get_language() { return language; }

void Language::set_language(string l) {
    if (l != "English") {
        throw LanguageException("Данной книги в таком переводе нет");
    }
    else {
        cout << "Хорошего чтения!" << endl;
    }
    language = l;
}
 
Author::Author(const string& n, const string& by, int bw, const Country& country, const Language& language)
    : name(n), birth_year(by), books_written(bw), associatedCountry(country), associatedLanguage(language) {
}
Author::Author() : name("Автор : Joanne Rowling"), birth_year("1965 год"), books_written(15),
associatedCountry(Country("United Kingdom")), associatedLanguage(Language("English")) {
}
string Author::get_Author() { return name; }
string Author::get_birth() { return birth_year; }
int Author::get_books() { return books_written; }
string Author::get_AssociatedCountry() { return associatedCountry.get_country(); }
string Author::get_AssociatedLanguage() { return associatedLanguage.get_language(); }

void Author::set_birth(int by) {
    if (by != 1965) {
        throw AuthorBirthException("Не угадали, почитайте биографию");
    }
    else {
        cout << "Угадали!" << endl;
    }
}

void Author::set_books(int bw) {
    if (bw != 15) {
        throw AuthorBooksException("Не угадали, почитайте биографию");
    }
    else {
        cout << "Угадали!" << endl;
    }
    books_written = bw;
}
 
NumberOfTranslations::NumberOfTranslations(int tran, const Language& language)
    : number_translations(tran), associatedLanguage(language) {
}
NumberOfTranslations::NumberOfTranslations() : number_translations(1), associatedLanguage(Language("English")) {}
int NumberOfTranslations::get_number_translations() { return number_translations; }
string NumberOfTranslations::get_AssociatedLanguage() { return associatedLanguage.get_language(); }
 
Translator::Translator(const string& tr, const NumberOfTranslations& translations)
    : translator(tr), associatedTranslations(translations) {
}
Translator::Translator() : translator(""), associatedTranslations(NumberOfTranslations(1, Language("Russian"))) {}
string Translator::get_translator() { return translator; }
int Translator::get_AssociatedTranslations() { return associatedTranslations.get_number_translations(); }
 
Prohibited::Prohibited(bool prohibited, const Country& country)
    : is_prohibited(prohibited), associatedCountry(country) {
}
Prohibited::Prohibited() : is_prohibited(false), associatedCountry(Country("Belarus")) {}
bool Prohibited::get_is_prohibited() { return is_prohibited; }
string Prohibited::get_AssociatedCountry() { return associatedCountry.get_country(); }
 
Rating::Rating(double r) : rating(r) {}
Rating::Rating() : rating(4.8) {}
double Rating::get_rating() { return rating; }

void Rating::set_rating(double r) {
    if (r <= 4.7 || r > 5.0) {
        throw RatingException("Данная книга не подходит по желаемому рейтингу");
    }
    else {
        cout << "Хорошего чтения!" << endl;
    }
    rating = r;
}
 
Publisher::Publisher(const string& p) : publisher(p) {}
Publisher::Publisher() : publisher("Bloomsbury") {}
string Publisher::get_publisher() { return publisher; }

void Publisher::set_publisher(string p) {
    if (p != "Bloomsbury") {
        throw PublisherException("Данная книга выпущена другим издательством");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    publisher = p;
}

 
ImportCountry::ImportCountry(const string& country, const Prohibited& prohibited)
    : import_country(country), associatedProhibited(prohibited) {
}
ImportCountry::ImportCountry() : import_country("United Kingdom"), associatedProhibited(Prohibited(false, Country("Belarus"))) {}
string ImportCountry::get_import_country() { return import_country; }
bool ImportCountry::get_AssociatedProhibitedStatus() { return associatedProhibited.get_is_prohibited(); }
string ImportCountry::get_AssociatedProhibitedCountry() { return associatedProhibited.get_AssociatedCountry(); }
 
ExportCountry::ExportCountry(const string& country2, const Prohibited& prohibited)
    : export_country(country2), associatedProhibited(prohibited) {
}
ExportCountry::ExportCountry() : export_country("United Kingdom"), associatedProhibited(Prohibited(false, Country("Belarus"))) {}
string ExportCountry::get_export_country() { return export_country; }
bool ExportCountry::get_AssociatedProhibitedStatus() { return associatedProhibited.get_is_prohibited(); }
string ExportCountry::get_AssociatedProhibitedCountry() { return associatedProhibited.get_AssociatedCountry(); }
 
PageCount::PageCount(int pages) : number_pages(pages) {}
PageCount::PageCount() : number_pages(400) {}
int PageCount::get_number_pages() { return number_pages; }

void PageCount::set_number_pages(int n) {
    if (n < 362) {
        throw PageCountException("Количество страниц в данной книге больше, чем вы ожидали");
    }
    else {
        cout << "Хорошего чтения!" << endl;
    }
    number_pages = n;
}

BookFormat::BookFormat(const string& bf, const PageCount& pageCount)
    : bookformat(bf), associatedPageCount(pageCount) {
}
BookFormat::BookFormat() : bookformat("A5"), associatedPageCount(PageCount(400)) {}
string BookFormat::get_bookformat() { return bookformat; }
int BookFormat::get_AssociatedPageCount() { return associatedPageCount.get_number_pages(); }
 
BookWeight::BookWeight(double w, const BookFormat& format) : weight(w), associatedFormat(format) {}
BookWeight::BookWeight() : weight(600.0), associatedFormat(BookFormat("A5", PageCount(400))) {}
double BookWeight::get_weight() { return weight; }
string BookWeight::get_AssociatedFormat() { return associatedFormat.get_bookformat(); }
 
BookTitle::BookTitle(const string& title) : title_book(title) {}
BookTitle::BookTitle() : title_book("Harry Potter") {}
string BookTitle::get_Book() { return title_book; }

void BookTitle::set_Book(string tb) {
    if (tb != "Harry Potter") {
        throw BookTitleException("Название не соответствует введенному, заявка отклонена");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    title_book = tb;
}

Sale::Sale(double discount, const string& period)
    : discount_percentage(discount), sale_period(period) {
}
Sale::Sale() : discount_percentage(15.0), sale_period("") {}
double Sale::get_discount() { return discount_percentage; }
string Sale::get_sale_period() { return sale_period; }

Price::Price(double p, const string& curr, const Sale& sale)
    : price(p), currency(curr), associatedSale(sale) {
}
Price::Price() : price(25.99), currency("USD"), associatedSale(Sale(15.0, "")) {}
double Price::get_price() { return price; }
string Price::get_currency() { return currency; }
double Price::get_AssociatedDiscount() { return associatedSale.get_discount(); }
string Price::get_AssociatedSalePeriod() { return associatedSale.get_sale_period(); }

NumberOfBooks::NumberOfBooks(int qty) : quantity(qty) {}
NumberOfBooks::NumberOfBooks() : quantity(50) {}
int NumberOfBooks::get_quantity() { return quantity; } 

ArrivalDate::ArrivalDate(const string& d) : date(d) {}
ArrivalDate::ArrivalDate() : date("12-10-2025") {}
string ArrivalDate::get_arrival_date() { return date; }

BookCondition::BookCondition(const string& cond) : condition(cond) {}
BookCondition::BookCondition() : condition("new") {}
string BookCondition::get_condition() { return condition; }

BookSeries::BookSeries(const string& name) : series_name(name) {}
BookSeries::BookSeries() : series_name("Harry Potter"), volume_number(1) {}
string BookSeries::get_series_name() { return series_name; }

BookVolumeCount::BookVolumeCount(int volume, const BookSeries& series)
    : volume_number(volume), associatedSeries(series) {
}
BookVolumeCount::BookVolumeCount() : volume_number(7), associatedSeries(BookSeries("Harry Potter")) {}
int BookVolumeCount::get_volume_number() { return volume_number; }
string BookVolumeCount::get_AssociatedSeries() { return associatedSeries.get_series_name(); }

LimitedSeries::LimitedSeries(bool limited, const BookVolumeCount& volumeCount)
    : is_limited(limited), associatedVolumeCount(volumeCount) {
}
LimitedSeries::LimitedSeries() : is_limited(false), associatedVolumeCount(BookVolumeCount(7, BookSeries("Harry Potter"))) {}
bool LimitedSeries::is_limited_edition() { return is_limited; }
int LimitedSeries::get_AssociatedVolumeCount() { return associatedVolumeCount.get_volume_number(); }

MainCharacter::MainCharacter(const string& nc, const BookVolumeCount& volumeCount)
    : name_character(nc), associatedVolumeCount(volumeCount) {
}
MainCharacter::MainCharacter() : name_character("Harry Potter"), associatedVolumeCount(BookVolumeCount(7, BookSeries("Harry Potter"))) {}
string MainCharacter::get_character() { return name_character; }
int MainCharacter::get_AssociatedVolumeCount() { return associatedVolumeCount.get_volume_number(); }
string MainCharacter::get_AssociatedSeries() { return associatedVolumeCount.get_AssociatedSeries(); }

PositionLocation::PositionLocation(int pos) : position(pos) {}
PositionLocation::PositionLocation() : position(15) {}
int PositionLocation::get_position() { return position; }

ShelfLocation::ShelfLocation(const string& sh, const PositionLocation& position)
    : shelf(sh), associatedPosition(position) {
}
ShelfLocation::ShelfLocation() : shelf("третья"), associatedPosition(PositionLocation(15)) {}
string ShelfLocation::get_shelf() { return shelf; }
int ShelfLocation::get_AssociatedPosition() { return associatedPosition.get_position(); }

SectionLocation::SectionLocation(const string& sec, const ShelfLocation& shelf)
    : section(sec), associatedShelf(shelf) {
}
SectionLocation::SectionLocation(const string& sec)
    : section(sec), associatedShelf(ShelfLocation("третья", PositionLocation(15))) {
}
SectionLocation::SectionLocation() : section("A"), associatedShelf(ShelfLocation("третья", PositionLocation(15))) {}
string SectionLocation::get_section() { return section; }
string SectionLocation::get_AssociatedShelf() { return associatedShelf.get_shelf(); }

HollLocation::HollLocation(int h, const SectionLocation& section)
    : holl(h), associatedSection(section) {
}
HollLocation::HollLocation() : holl(1), associatedSection(SectionLocation("A", ShelfLocation("третья", PositionLocation(15)))) {}
int HollLocation::get_holl() { return holl; }
string HollLocation::get_AssociatedSection() { return associatedSection.get_section(); }

Supplier::Supplier(const string& name, const ImportCountry& importCountry, const BookCondition& bookCondition)
    : supplier_name(name), associatedImportCountry(importCountry), associatedBookCondition(bookCondition) {
}
Supplier::Supplier() : supplier_name("Bloomsbury Publishing"),
associatedImportCountry(ImportCountry("United Kingdom", Prohibited(false, Country("Belarus")))),
associatedBookCondition(BookCondition("new")) {
}
string Supplier::get_supplier() { return supplier_name; }
string Supplier::get_AssociatedImportCountry() { return associatedImportCountry.get_import_country(); }
bool Supplier::get_AssociatedImportProhibited() { return associatedImportCountry.get_AssociatedProhibitedStatus(); }
string Supplier::get_AssociatedBookCondition() { return associatedBookCondition.get_condition(); }

EducationLevel::EducationLevel(const string& lvl) : level(lvl) {}
EducationLevel::EducationLevel() : level("middle_school") {}
string EducationLevel::get_education_level() { return level; }

TargetAudience::TargetAudience(const string& type, const EducationLevel& educationLevel)
    : audience_type(type), associatedEducationLevel(educationLevel) {
}
TargetAudience::TargetAudience() : audience_type("teenagers"), associatedEducationLevel(EducationLevel("middle_school")) {}
string TargetAudience::get_audience_type() { return audience_type; }
string TargetAudience::get_AssociatedEducationLevel() { return associatedEducationLevel.get_education_level(); }


Audiobook::Audiobook(bool audio) : has_audiobook(audio) {}
Audiobook::Audiobook() : has_audiobook(true) {}
bool Audiobook::has_audiobook_version() { return has_audiobook; }


ElectronicPDF::ElectronicPDF(bool pdf, const Audiobook& audio) : has_pdf(pdf), associatedAudiobook(audio) {}
ElectronicPDF::ElectronicPDF() : has_pdf(true), associatedAudiobook(Audiobook(true)) {}
bool ElectronicPDF::has_pdf_version() { return has_pdf; }
bool ElectronicPDF::get_AssociatedAudiobook() { return associatedAudiobook.has_audiobook_version(); }

Reviews::Reviews(const string& rev) : reviews(rev) {}
Reviews::Reviews() : reviews("Отличная книга о магии и приключениях!") {}
string Reviews::get_reviews() { return reviews; }

NumberOfReviews::NumberOfReviews(int nr, const Reviews& reviews)
    : number_reviews(nr), associatedReviews(reviews) {
}
NumberOfReviews::NumberOfReviews() : number_reviews(1000), associatedReviews(Reviews("Отличная книга о магии и приключениях!")) {}
int NumberOfReviews::get_number_reviews() { return number_reviews; }
string NumberOfReviews::get_AssociatedReviews() { return associatedReviews.get_reviews(); }

User::User(const string& user_name) : name(user_name), books_bought(0) {}
User::User() : name("Гость"), books_bought(0) {}
string User::get_name() { return name; }
int User::get_books_bought() { return books_bought; }
void User::add_purchased_book() {
    books_bought++;
    cout << name << " купил книгу. Всего книг: " << books_bought << endl;
}

AgeRestriction::AgeRestriction(int age, const TargetAudience& audience, const User& user)
    : age_restriction(age), associatedAudience(audience), associatedUser(user) {
}
AgeRestriction::AgeRestriction() : age_restriction(12), associatedAudience(TargetAudience("teenagers", EducationLevel("middle_school"))), associatedUser(User("Гость")) {}
int AgeRestriction::get_age_restriction() { return age_restriction; }
string AgeRestriction::get_AssociatedAudience() { return associatedAudience.get_audience_type(); }
string AgeRestriction::get_AssociatedAudienceEducation() { return associatedAudience.get_AssociatedEducationLevel(); }
string AgeRestriction::get_AssociatedUserName() { return associatedUser.get_name(); }
int AgeRestriction::get_AssociatedUserBooks() { return associatedUser.get_books_bought(); }

void AgeRestriction::set_age_restriction(int v) {
    if (v < 12) {
        throw AgeRestrictionException("Данная книга ограничена для вашего возраста");
    }
    else {
        cout << "Хорошего чтения!" << endl;
    }
    age_restriction = v;
}

LoyaltyProgram::LoyaltyProgram(const User& user_obj) : associatedUser(user_obj), discount_percentage(0), has_user(true) {}
LoyaltyProgram::LoyaltyProgram() : discount_percentage(0), has_user(false) {}
void LoyaltyProgram::update_discount() {
    if (!has_user) {
        cout << "Ошибка: пользователь не установлен" << endl;
        return;
    }
    int books_bought = associatedUser.get_books_bought();
    if (books_bought >= 5) {
        discount_percentage = 50.0;
        cout << "Поздравляем! " << associatedUser.get_name()
            << " получает постоянную скидку 50% за покупку " << books_bought << " книг!" << endl;
    }
    else {
        discount_percentage = 0;
        cout << associatedUser.get_name() << " купил " << books_bought
            << " книг. До скидки 50% осталось: " << (5 - books_bought) << " книг" << endl;
    }
}
double LoyaltyProgram::get_discount() {
    update_discount();
    return discount_percentage;
}
double LoyaltyProgram::apply_discount(double original_price) {
    if (!has_user) {
        cout << "Ошибка: пользователь не установлен, скидка не применяется" << endl;
        return original_price;
    }
    double discounted_price = original_price * (1 - discount_percentage / 100);
    cout << "Цена: " << original_price << " USD -> Со скидкой "
        << discount_percentage << "%: " << discounted_price << " USD" << endl;
    return discounted_price;
}
string LoyaltyProgram::get_AssociatedUserName() {
    if (has_user) { return associatedUser.get_name(); }
    return "Пользователь не установлен";
}
int LoyaltyProgram::get_AssociatedUserBooks() {
    if (has_user) { return associatedUser.get_books_bought(); }
    return 0;
}
void LoyaltyProgram::set_user(const User& user_obj) {
    associatedUser = user_obj;
    has_user = true;
}
bool LoyaltyProgram::has_user_set() const { return has_user; }

NumberOfPeople::NumberOfPeople(int people, const User& user)
    : number_people(people), associatedUser(user) {
}
NumberOfPeople::NumberOfPeople() : number_people(1000), associatedUser(User("Гость")) {}
int NumberOfPeople::get_number_people() { return number_people; }
string NumberOfPeople::get_AssociatedUserName() { return associatedUser.get_name(); }
int NumberOfPeople::get_AssociatedUserBooks() { return associatedUser.get_books_bought(); }

PersonalOpinion::PersonalOpinion(const string& op, const NumberOfPeople& people)
    : opinion(op), associatedPeople(people) {
}
PersonalOpinion::PersonalOpinion() : opinion("Рекомендую к прочтению!"), associatedPeople(NumberOfPeople(1000, User("Гость"))) {}
string PersonalOpinion::get_opinion() { return opinion; }
int PersonalOpinion::get_AssociatedPeople() { return associatedPeople.get_number_people(); }

CustomerArrivalTime::CustomerArrivalTime(const string& t, const string& day, const string& dd, const User& user)
    : time(t), day_of_week(day), date_day(dd) {
}
CustomerArrivalTime::CustomerArrivalTime() : time("14:30"), day_of_week("Sunday"), date_day("12-10-2025") {}
string CustomerArrivalTime::get_time() { return time; }
string CustomerArrivalTime::get_day_w() { return day_of_week; }
string CustomerArrivalTime::get_day_d() { return date_day; }

PurchasedBook::PurchasedBook(const string& title, const string& date, double price, const string& user)
    : book_title(title), purchase_date(date), purchase_price(price), user_name(user) {
}
PurchasedBook::PurchasedBook() : book_title("Harry Potter"), purchase_date("12-10-2025"),
purchase_price(25.99), user_name("Гость") {
}
string PurchasedBook::get_book_title() { return book_title; }
string PurchasedBook::get_purchase_date() { return purchase_date; }
double PurchasedBook::get_purchase_price() { return purchase_price; }
string PurchasedBook::get_user_name() { return user_name; }
void PurchasedBook::display_purchase_info() {
    cout << "Покупка: " << book_title << " | Цена: " << purchase_price
        << " | Дата: " << purchase_date << " | Покупатель: " << user_name << endl;
}

Cover_Format::Cover_Format(const string& f, const Publisher& publisher) : format(f), associatedPublisher(publisher) {}
Cover_Format::Cover_Format() : format("Hard"), associatedPublisher(Publisher("Bloomsbury")) {}
string Cover_Format::get_format() { return format; }
string Cover_Format::get_AssociatedPublisher() { return associatedPublisher.get_publisher(); }

void Cover_Format::set_format(string f) {
    if (f != "Hard") {
        throw CoverFormatException("Данная книга есть только в Твердой обложке");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    format = f;
}

BookArrivalNotification::BookArrivalNotification(const string& title, const ArrivalDate& arrivalDate)
    : book_title(title), is_sent(false), associatedArrivalDate(arrivalDate) {
    notification_message = "Уведомление: Книга '" + book_title + "' поступила в продажу! Дата: " + associatedArrivalDate.get_arrival_date();
}
BookArrivalNotification::BookArrivalNotification() : book_title("Harry Potter"), is_sent(false), associatedArrivalDate(ArrivalDate("12-10-2025")) {
    notification_message = "Уведомление: Книга '" + book_title + "' поступила в продажу! Дата: " + associatedArrivalDate.get_arrival_date();
}
void BookArrivalNotification::send_notification() {
    if (!is_sent) {
        cout << notification_message << endl;
        is_sent = true;
    }
    else {
        cout << "Уведомление для книги '" << book_title << "' уже было отправлено" << endl;
    }
}
string BookArrivalNotification::get_book_title() { return book_title; }
bool BookArrivalNotification::is_notification_sent() { return is_sent; }
string BookArrivalNotification::get_AssociatedArrivalDate() { return associatedArrivalDate.get_arrival_date(); }
void BookArrivalNotification::reset_notification() { is_sent = false; }

WorkExperience::WorkExperience(int experience) : years_of_experience(experience) {}
WorkExperience::WorkExperience() : years_of_experience(0) {}
int WorkExperience::get_years_of_experience() const { return years_of_experience; }

AssistantName::AssistantName(const string& name, const WorkExperience& experience)
    : assistantname(name), associatedExperience(experience) {
}
AssistantName::AssistantName() : assistantname("Неизвестный"), associatedExperience(WorkExperience(0)) {}
string AssistantName::get_name() const { return assistantname; }
int AssistantName::get_AssociatedExperience() { return associatedExperience.get_years_of_experience(); }

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
