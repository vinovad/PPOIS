/**
 * @file Book.h
 * @brief Главный заголовочный файл для системы управления книгами
 * @mainpage Система управления cкладом книг
 *
 * Данная система предоставляет комплексное решение для управления информацией о книгах,
 * включая их характеристики, авторов, издателей, цены, рейтинги и многое другое.
 */

#ifndef BOOK_H
#define BOOK_H
#include "Tag.h"
#include "Genre.h"
#include "YearOfManufacture.h"
#include "Country.h"
#include "Language.h"
#include "Author.h"
#include "NumberOfTranslations.h"
#include "Translator.h"
#include "Prohibited.h"
#include "Rating.h"
#include "Publisher.h"
#include "ImportCountry.h"
#include "ExportCountry.h"
#include "PageCount.h"
#include "BookFormat.h"
#include "BookWeight.h"
#include "BookTitle.h"
#include "Sale.h"
#include "Price.h"
#include "NumberOfBooks.h"
#include "ArrivalDate.h"
#include "BookCondition.h"
#include "BookSeries.h"
#include "BookVolumeCount.h"
#include "LimitedSeries.h"
#include "MainCharacter.h"
#include "PositionLocation.h"
#include "ShelfLocation.h"
#include "SectionLocation.h"
#include "HollLocation.h"
#include "Supplier.h"
#include "EducationLevel.h"
#include "TargetAudience.h"
#include "Audiobook.h"
#include "ElectronicPDF.h"
#include "Reviews.h"
#include "NumberOfReviews.h"
#include "User.h"
#include "AgeRestriction.h"
#include "LoyaltyProgram.h"
#include "NumberOfPeople.h"
#include "PersonalOpinion.h"
#include "CustomerArrivalTime.h"
#include "PurchasedBook.h"
#include "Cover_Format.h"
#include "BookArrivalNotification.h"
#include "WorkExperience.h"
#include "AssistantName.h"

 /**
  * @class Book
  * @brief Основной класс, представляющий книгу в системе
  *
  * Класс Book наследует функциональность от всех основных классов системы,
  * предоставляя полный набор характеристик для описания книги.
  */
class Book : public Genre, public YearOfManufacture, public MainCharacter, public Country,
    public Author, public Rating, public Cover_Format, public Publisher, public Tag,
    public Language, public BookFormat, public Translator, public NumberOfTranslations,
    public PageCount, public BookTitle, public AgeRestriction, public Price, public Sale,
    public Prohibited, public NumberOfBooks, public BookWeight, public ArrivalDate,
    public BookCondition, public BookSeries, public BookVolumeCount, public SectionLocation,
    public HollLocation, public ShelfLocation, public PositionLocation, public Supplier,
    public ImportCountry, public ExportCountry, public TargetAudience, public EducationLevel,
    public LimitedSeries, public ElectronicPDF, public Audiobook, public NumberOfReviews,
    public Reviews, public PersonalOpinion, public NumberOfPeople, public User, public CustomerArrivalTime,
    public PurchasedBook, public BookArrivalNotification, public LoyaltyProgram, public WorkExperience, public AssistantName {
public:
    /**
     * @brief Конструктор класса Book
     * @param genre Жанр книги
     * @param year Год издания
     * @param character Главный персонаж
     * @param country Страна издания
     * @param author_name Имя автора
     * @param author_birth Год рождения автора
     * @param author_books Количество книг автора
     * @param rating_val Рейтинг книги
     * @param cover Формат обложки
     * @param publisher_name Издатель
     * @param tag_name Тег книги
     * @param language_name Язык книги
     * @param book_format Формат книги
     * @param translator_name Переводчик
     * @param translations_count Количество переводов
     * @param page_count Количество страниц
     * @param book_title Название книги
     * @param age_restrict Возрастное ограничение
     * @param price_val Цена
     * @param currency Валюта
     * @param discount Скидка
     * @param sale_period Период продажи
     * @param prohibited_status Статус запрета
     * @param books_quantity Количество книг
     * @param weight_val Вес книги
     * @param arrival_date Дата поступления
     * @param condition Состояние книги
     * @param series_name Название серии
     * @param volume_count Количество томов
     * @param section Секция
     * @param holl Зал
     * @param shelf Полка
     * @param position Позиция
     * @param supplier_name Поставщик
     * @param import_country Страна импорта
     * @param export_country Страна экспорта
     * @param audience Целевая аудитория
     * @param education_lvl Уровень образования
     * @param limited_status Ограниченная серия
     * @param has_pdf Наличие PDF
     * @param has_audio Наличие аудиокниги
     * @param reviews_count Количество отзывов
     * @param review_text Текст отзыва
     * @param opinion Мнение
     * @param people_count Количество людей
     * @param user_name Имя пользователя
     * @param purchased_title Название купленной книги
     * @param purchase_date Дата покупки
     * @param purchase_price Цена покупки
     * @param purchased_user Пользователь покупки
     * @param notification_title Заголовок уведомления
     * @param loyalty_user Пользователь программы лояльности
     * @param assistantname Имя ассистента
     * @param experience Опыт работы
     */
    Book(string genre, int year, string character, string country, string author_name,
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
        double purchase_price, string purchased_user, string notification_title,
        const User loyalty_user, string assistantname, int experience);

    /// @name Методы доступа к ассоциированным данным
    /// @{
    string get_Tag_Genre();
    string get_AssociatedPublisher();
    bool get_AssociatedAudiobook();
    string get_AssociatedReviews();
    int get_AssociatedTranslations();
    string get_AssociatedFormat();
    double get_AssociatedDiscount();
    int get_AssociatedLimitedVolumeCount();
    string get_AssociatedLoyaltyUserName();
    bool get_AssociatedImportProhibited();
    string get_AssociatedAgeAudience();
    int get_AssociatedCharacterVolumeCount();
    string get_AssociatedSupplierBookCondition();
    string get_AssociatedNotificationArrivalDate();
    int get_AssociatedExperience();
    /// @}
};

#endif