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

#include <string>
using namespace std;

int main() {
    setlocale(0, "rus");
    User user("Лучший покупатель");
    cout << "Создан пользователь: " << user.get_name() << endl;

    Book HarryPotter("Fantasy", 1997, "Harry Potter", "United Kingdom", "Автор : Joanne Rowling", "1965 год", 15, 4.8, "Hard", "Bloomsbury", "Волшебство", "English", "A5", "Марина Литвинова", 1, 400, "Harry Potter", 12, 25.99, "USD", 15.0, "", false, 50, 600.0, "12-10-2025", "new", "Harry Potter", 1, "A", 1, "третья", 15, "Bloomsbury Publishing", "United Kingdom", "United Kingdom", "teenagers", "middle_school", false, true, true, 1000, "Отличная книга о магии и приключениях!", "Рекомендую к прочтению!", 1000, "Гость", "Harry Potter", "12-10-2025", 25.99, "Гость", "Harry Potter", user, "Ivan", 20);
   
    cout << "\n" << string(40, '=') << endl;
    cout << "Полная информация о книге 'Garry Potter'" << endl;
    cout << string(40, '=') << endl;

    cout << "\n Основная информация:" << endl;
    cout << " Название: " << HarryPotter.BookTitle::get_Book() << endl;
    cout << HarryPotter.Author::get_Author() << endl;
    cout << " Год выпуска: " << HarryPotter.YearOfManufacture::get_Year() << endl;
    cout << " Жанр: " << HarryPotter.Genre::get_Genre() << endl;
    cout << " Тег: " << HarryPotter.get_Tag_Genre() << endl;
    cout << " Главный герой: " << HarryPotter.MainCharacter::get_character() << endl;
    cout << " Количество томов в серии: " << HarryPotter.get_AssociatedCharacterVolumeCount() << endl;

    cout << "\n Физические характеристики:" << endl;
    cout << " Формат книги: " << HarryPotter.get_AssociatedFormat() << endl;
    cout << " Количество страниц: " << HarryPotter.PageCount::get_number_pages() << endl;
    cout << " Вес: " << HarryPotter.BookWeight::get_weight() << " г" << endl;
    cout << " Обложка: " << HarryPotter.Cover_Format::get_format() << endl;
    cout << " Состояние: " << HarryPotter.BookCondition::get_condition() << endl;

    cout << "\n Издательство и перевод:" << endl;
    cout << " Издатель: " << HarryPotter.get_AssociatedPublisher() << endl;
    cout << " Язык: " << HarryPotter.Language::get_language() << endl;
    cout << " Количество переводов: " << HarryPotter.get_AssociatedTranslations() << endl;
    cout << " Переводчик: " << HarryPotter.Translator::get_translator() << endl;

    cout << "\n Цена и скидки:" << endl;
    cout << " Цена: " << HarryPotter.Price::get_price() << " " << HarryPotter.Price::get_currency() << endl;
    cout << " Скидка: " << HarryPotter.get_AssociatedDiscount() << "%" << endl;
    cout << " Количество книг в наличии: " << HarryPotter.NumberOfBooks::get_quantity() << endl;

    cout << "\n Ограничения и аудитория:" << endl;
    cout << " Возрастное ограничение: " << HarryPotter.AgeRestriction::get_age_restriction() << "+" << endl;
    cout << " Целевая аудитория: " << HarryPotter.get_AssociatedAgeAudience() << endl;
    cout << " Уровень образования: " << HarryPotter.EducationLevel::get_education_level() << endl;
    cout << " Запрещена в Беларуси: " << (HarryPotter.get_AssociatedImportProhibited() ? "Да" : "Нет") << endl;

    cout << "\n Серия:" << endl;
    cout << " Название серии: " << HarryPotter.BookSeries::get_series_name() << endl;
    cout << " Ограниченная серия: " << (HarryPotter.LimitedSeries::is_limited_edition() ? "Да" : "Нет") << endl;
    cout << " Количество томов: " << HarryPotter.get_AssociatedLimitedVolumeCount() << endl;

    cout << "\n Электронные версии:" << endl;
    cout << " PDF версия: " << (HarryPotter.ElectronicPDF::has_pdf_version() ? "Доступна" : "Не доступна") << endl;
    cout << " Аудиокнига: " << (HarryPotter.get_AssociatedAudiobook() ? "Доступна" : "Не доступна") << endl;

    cout << "\n Отзывы и рейтинги:" << endl;
    cout << " Рейтинг: " << HarryPotter.Rating::get_rating() << "/5" << endl;
    cout << " Количество отзывов: " << HarryPotter.NumberOfReviews::get_number_reviews() << endl;
    cout << " Пример отзыва: " << HarryPotter.get_AssociatedReviews() << endl;
    cout << " Мнение: " << HarryPotter.PersonalOpinion::get_opinion() << endl;
    cout << " Количество людей: " << HarryPotter.NumberOfPeople::get_number_people() << endl;

    cout << "\n Расположение на складе:" << endl;
    cout << " Зал: " << HarryPotter.HollLocation::get_holl() << endl;
    cout << " Секция: " << HarryPotter.SectionLocation::get_section() << endl;
    cout << " Полка: " << HarryPotter.ShelfLocation::get_shelf() << endl;
    cout << " Позиция: " << HarryPotter.PositionLocation::get_position() << endl;

    cout << "\n Поставщик и логистика:" << endl;
    cout << " Поставщик: " << HarryPotter.Supplier::get_supplier() << endl;
    cout << " Страна импорта: " << HarryPotter.ImportCountry::get_import_country() << endl;
    cout << " Страна экспорта: " << HarryPotter.ExportCountry::get_export_country() << endl;
    cout << " Дата поступления: " << HarryPotter.ArrivalDate::get_arrival_date() << endl;

    cout << "\n Пользователь и Ассистент:" << endl;
    cout << " Пользователь: " << HarryPotter.get_AssociatedLoyaltyUserName() << endl;
    cout << " Куплено книг: " << user.get_books_bought() << endl;
    cout << " Опыт ассистента: " << HarryPotter.get_AssociatedExperience() << " лет" << endl;
    cout << " Имя ассистента: " << HarryPotter.AssistantName::get_name() << endl;

    cout << "\n" << string(40, '=') << endl;
    cout << string(40, '=') << endl;

    try {
        string genre;
        cout << "К какому жанру относится книга 'Harry Potter'? (например: Fantasy, Detective, Romance, etc.): ";
        getline(cin, genre);
        HarryPotter.set_Genre(genre);
    }
    catch (const GenreException& ex) {
        cout << "Ошибка жанра: " << ex.what() << endl;
    }

    try {
        string naz;
        cout << "Подтвердите покупку книги, указав ее название (Harry Potter): ";
        getline(cin, naz);
        HarryPotter.set_Book(naz);
    }
    catch (const BookTitleException& ex) { 
        cout << "Ошибка названия: " << ex.what() << endl;
    }

    try {
        string tag;
        cout << "Введите желаемый тэг для данной книги (Magic): ";
        getline(cin, tag);
        HarryPotter.set_Tag(tag);
    }
    catch (const TagException& ex) { 
        cout << "Ошибка тега: " << ex.what() << endl;
    }
    try {
        string obl;
        cout << "В какой обложке вы бы хотели приобрести книгу (Soft/Hard)?: ";
        getline(cin, obl);
        HarryPotter.set_format(obl);
    }
    catch (const CoverFormatException& ex) {  
        cout << "Ошибка формата: " << ex.what() << endl;
    }

    try {
        int v;
        cout << "Введите возраст, чтобы узнать, разрешено ли вам читать данную книгу: ";
        cin >> v;
        HarryPotter.set_age_restriction(v);
    }
    catch (const AgeRestrictionException& ex) {  
        cout << "Ошибка возраста: " << ex.what() << endl;
    }

    try {
        double r;
        cout << "Введите желаемый рейтинг: ";
        cin >> r;
        HarryPotter.set_rating(r);
    }
    catch (const RatingException& ex) { 
        cout << "Ошибка рейтинга: " << ex.what() << endl;
    }

    try {
        int str;
        cout << "Сколько страниц вы можете осилить? ";
        cin >> str;
        HarryPotter.set_number_pages(str);
    }
    catch (const PageCountException& ex) {  
        cout << "Ошибка страниц: " << ex.what() << endl;
    }

    try {
        string izd;
        cout << "От какого издательства вы бы хотели прочесть данную книгу (например: Barbin, Gosselin, L.C. Page & Co., The Russian Messenger)? ";
        cin >> izd;
        HarryPotter.set_publisher(izd);
    }
    catch (const PublisherException& ex) { 
        cout << "Ошибка издательства: " << ex.what() << endl;
    }

    try {
        string god;
        cout << "В каком временном промежутке вы бы хотели прочесть данную книгу (например, 80е)? ";
        cin >> god;
        HarryPotter.set_Year(god);
    }
    catch (const YearException& ex) { 
        cout << "Ошибка года: " << ex.what() << endl;
    }

    try {
        string lg;
        cout << "В каком переводе вы бы хотели прочесть данную книгу? ";
        cin >> lg;
        HarryPotter.set_language(lg);
    }
    catch (const LanguageException& ex) {
        cout << "Ошибка языка: " << ex.what() << endl;
    }

    try {
        int t1;
        cout << "Как вы думаете, сколько книг написала Джоан Роулинг? : ";
        cin >> t1;
        HarryPotter.set_books(t1);
    }
    catch (const AuthorBooksException& ex) {  
        cout << "Ошибка автора: " << ex.what() << endl;
    }

    try {
        int t2;
        cout << "Как вы думаете, в каком году родилась Джоан Роулинг?: ";
        cin >> t2;
        HarryPotter.set_birth(t2);
    }
    catch (const AuthorBirthException& ex) { 
        cout << "Ошибка автора: " << ex.what() << endl;
    }
    return 0;}
