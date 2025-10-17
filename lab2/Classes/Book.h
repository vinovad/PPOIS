/**
 * @file Book.h
 * @brief ������� ������������ ���� ��� ������� ���������� �������
 * @mainpage ������� ���������� c������ ����
 *
 * ������ ������� ������������� ����������� ������� ��� ���������� ����������� � ������,
 * ������� �� ��������������, �������, ���������, ����, �������� � ������ ������.
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
  * @brief �������� �����, �������������� ����� � �������
  *
  * ����� Book ��������� ���������������� �� ���� �������� ������� �������,
  * ������������ ������ ����� ������������� ��� �������� �����.
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
     * @brief ����������� ������ Book
     * @param genre ���� �����
     * @param year ��� �������
     * @param character ������� ��������
     * @param country ������ �������
     * @param author_name ��� ������
     * @param author_birth ��� �������� ������
     * @param author_books ���������� ���� ������
     * @param rating_val ������� �����
     * @param cover ������ �������
     * @param publisher_name ��������
     * @param tag_name ��� �����
     * @param language_name ���� �����
     * @param book_format ������ �����
     * @param translator_name ����������
     * @param translations_count ���������� ���������
     * @param page_count ���������� �������
     * @param book_title �������� �����
     * @param age_restrict ���������� �����������
     * @param price_val ����
     * @param currency ������
     * @param discount ������
     * @param sale_period ������ �������
     * @param prohibited_status ������ �������
     * @param books_quantity ���������� ����
     * @param weight_val ��� �����
     * @param arrival_date ���� �����������
     * @param condition ��������� �����
     * @param series_name �������� �����
     * @param volume_count ���������� �����
     * @param section ������
     * @param holl ���
     * @param shelf �����
     * @param position �������
     * @param supplier_name ���������
     * @param import_country ������ �������
     * @param export_country ������ ��������
     * @param audience ������� ���������
     * @param education_lvl ������� �����������
     * @param limited_status ������������ �����
     * @param has_pdf ������� PDF
     * @param has_audio ������� ����������
     * @param reviews_count ���������� �������
     * @param review_text ����� ������
     * @param opinion ������
     * @param people_count ���������� �����
     * @param user_name ��� ������������
     * @param purchased_title �������� ��������� �����
     * @param purchase_date ���� �������
     * @param purchase_price ���� �������
     * @param purchased_user ������������ �������
     * @param notification_title ��������� �����������
     * @param loyalty_user ������������ ��������� ����������
     * @param assistantname ��� ����������
     * @param experience ���� ������
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

    /// @name ������ ������� � ��������������� ������
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