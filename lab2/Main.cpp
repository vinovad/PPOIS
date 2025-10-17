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
    User user("������ ����������");
    cout << "������ ������������: " << user.get_name() << endl;

    Book HarryPotter("Fantasy", 1997, "Harry Potter", "United Kingdom", "����� : Joanne Rowling", "1965 ���", 15, 4.8, "Hard", "Bloomsbury", "����������", "English", "A5", "������ ���������", 1, 400, "Harry Potter", 12, 25.99, "USD", 15.0, "", false, 50, 600.0, "12-10-2025", "new", "Harry Potter", 1, "A", 1, "������", 15, "Bloomsbury Publishing", "United Kingdom", "United Kingdom", "teenagers", "middle_school", false, true, true, 1000, "�������� ����� � ����� � ������������!", "���������� � ���������!", 1000, "�����", "Harry Potter", "12-10-2025", 25.99, "�����", "Harry Potter", user, "Ivan", 20);
   
    cout << "\n" << string(40, '=') << endl;
    cout << "������ ���������� � ����� 'Garry Potter'" << endl;
    cout << string(40, '=') << endl;

    cout << "\n �������� ����������:" << endl;
    cout << " ��������: " << HarryPotter.BookTitle::get_Book() << endl;
    cout << HarryPotter.Author::get_Author() << endl;
    cout << " ��� �������: " << HarryPotter.YearOfManufacture::get_Year() << endl;
    cout << " ����: " << HarryPotter.Genre::get_Genre() << endl;
    cout << " ���: " << HarryPotter.get_Tag_Genre() << endl;
    cout << " ������� �����: " << HarryPotter.MainCharacter::get_character() << endl;
    cout << " ���������� ����� � �����: " << HarryPotter.get_AssociatedCharacterVolumeCount() << endl;

    cout << "\n ���������� ��������������:" << endl;
    cout << " ������ �����: " << HarryPotter.get_AssociatedFormat() << endl;
    cout << " ���������� �������: " << HarryPotter.PageCount::get_number_pages() << endl;
    cout << " ���: " << HarryPotter.BookWeight::get_weight() << " �" << endl;
    cout << " �������: " << HarryPotter.Cover_Format::get_format() << endl;
    cout << " ���������: " << HarryPotter.BookCondition::get_condition() << endl;

    cout << "\n ������������ � �������:" << endl;
    cout << " ��������: " << HarryPotter.get_AssociatedPublisher() << endl;
    cout << " ����: " << HarryPotter.Language::get_language() << endl;
    cout << " ���������� ���������: " << HarryPotter.get_AssociatedTranslations() << endl;
    cout << " ����������: " << HarryPotter.Translator::get_translator() << endl;

    cout << "\n ���� � ������:" << endl;
    cout << " ����: " << HarryPotter.Price::get_price() << " " << HarryPotter.Price::get_currency() << endl;
    cout << " ������: " << HarryPotter.get_AssociatedDiscount() << "%" << endl;
    cout << " ���������� ���� � �������: " << HarryPotter.NumberOfBooks::get_quantity() << endl;

    cout << "\n ����������� � ���������:" << endl;
    cout << " ���������� �����������: " << HarryPotter.AgeRestriction::get_age_restriction() << "+" << endl;
    cout << " ������� ���������: " << HarryPotter.get_AssociatedAgeAudience() << endl;
    cout << " ������� �����������: " << HarryPotter.EducationLevel::get_education_level() << endl;
    cout << " ��������� � ��������: " << (HarryPotter.get_AssociatedImportProhibited() ? "��" : "���") << endl;

    cout << "\n �����:" << endl;
    cout << " �������� �����: " << HarryPotter.BookSeries::get_series_name() << endl;
    cout << " ������������ �����: " << (HarryPotter.LimitedSeries::is_limited_edition() ? "��" : "���") << endl;
    cout << " ���������� �����: " << HarryPotter.get_AssociatedLimitedVolumeCount() << endl;

    cout << "\n ����������� ������:" << endl;
    cout << " PDF ������: " << (HarryPotter.ElectronicPDF::has_pdf_version() ? "��������" : "�� ��������") << endl;
    cout << " ����������: " << (HarryPotter.get_AssociatedAudiobook() ? "��������" : "�� ��������") << endl;

    cout << "\n ������ � ��������:" << endl;
    cout << " �������: " << HarryPotter.Rating::get_rating() << "/5" << endl;
    cout << " ���������� �������: " << HarryPotter.NumberOfReviews::get_number_reviews() << endl;
    cout << " ������ ������: " << HarryPotter.get_AssociatedReviews() << endl;
    cout << " ������: " << HarryPotter.PersonalOpinion::get_opinion() << endl;
    cout << " ���������� �����: " << HarryPotter.NumberOfPeople::get_number_people() << endl;

    cout << "\n ������������ �� ������:" << endl;
    cout << " ���: " << HarryPotter.HollLocation::get_holl() << endl;
    cout << " ������: " << HarryPotter.SectionLocation::get_section() << endl;
    cout << " �����: " << HarryPotter.ShelfLocation::get_shelf() << endl;
    cout << " �������: " << HarryPotter.PositionLocation::get_position() << endl;

    cout << "\n ��������� � ���������:" << endl;
    cout << " ���������: " << HarryPotter.Supplier::get_supplier() << endl;
    cout << " ������ �������: " << HarryPotter.ImportCountry::get_import_country() << endl;
    cout << " ������ ��������: " << HarryPotter.ExportCountry::get_export_country() << endl;
    cout << " ���� �����������: " << HarryPotter.ArrivalDate::get_arrival_date() << endl;

    cout << "\n ������������ � ���������:" << endl;
    cout << " ������������: " << HarryPotter.get_AssociatedLoyaltyUserName() << endl;
    cout << " ������� ����: " << user.get_books_bought() << endl;
    cout << " ���� ����������: " << HarryPotter.get_AssociatedExperience() << " ���" << endl;
    cout << " ��� ����������: " << HarryPotter.AssistantName::get_name() << endl;

    cout << "\n" << string(40, '=') << endl;
    cout << string(40, '=') << endl;

    try {
        string genre;
        cout << "� ������ ����� ��������� ����� 'Harry Potter'? (��������: Fantasy, Detective, Romance, etc.): ";
        getline(cin, genre);
        HarryPotter.set_Genre(genre);
    }
    catch (const GenreException& ex) {
        cout << "������ �����: " << ex.what() << endl;
    }

    try {
        string naz;
        cout << "����������� ������� �����, ������ �� �������� (Harry Potter): ";
        getline(cin, naz);
        HarryPotter.set_Book(naz);
    }
    catch (const BookTitleException& ex) { 
        cout << "������ ��������: " << ex.what() << endl;
    }

    try {
        string tag;
        cout << "������� �������� ��� ��� ������ ����� (Magic): ";
        getline(cin, tag);
        HarryPotter.set_Tag(tag);
    }
    catch (const TagException& ex) { 
        cout << "������ ����: " << ex.what() << endl;
    }
    try {
        string obl;
        cout << "� ����� ������� �� �� ������ ���������� ����� (Soft/Hard)?: ";
        getline(cin, obl);
        HarryPotter.set_format(obl);
    }
    catch (const CoverFormatException& ex) {  
        cout << "������ �������: " << ex.what() << endl;
    }

    try {
        int v;
        cout << "������� �������, ����� ������, ��������� �� ��� ������ ������ �����: ";
        cin >> v;
        HarryPotter.set_age_restriction(v);
    }
    catch (const AgeRestrictionException& ex) {  
        cout << "������ ��������: " << ex.what() << endl;
    }

    try {
        double r;
        cout << "������� �������� �������: ";
        cin >> r;
        HarryPotter.set_rating(r);
    }
    catch (const RatingException& ex) { 
        cout << "������ ��������: " << ex.what() << endl;
    }

    try {
        int str;
        cout << "������� ������� �� ������ �������? ";
        cin >> str;
        HarryPotter.set_number_pages(str);
    }
    catch (const PageCountException& ex) {  
        cout << "������ �������: " << ex.what() << endl;
    }

    try {
        string izd;
        cout << "�� ������ ������������ �� �� ������ �������� ������ ����� (��������: Barbin, Gosselin, L.C. Page & Co., The Russian Messenger)? ";
        cin >> izd;
        HarryPotter.set_publisher(izd);
    }
    catch (const PublisherException& ex) { 
        cout << "������ ������������: " << ex.what() << endl;
    }

    try {
        string god;
        cout << "� ����� ��������� ���������� �� �� ������ �������� ������ ����� (��������, 80�)? ";
        cin >> god;
        HarryPotter.set_Year(god);
    }
    catch (const YearException& ex) { 
        cout << "������ ����: " << ex.what() << endl;
    }

    try {
        string lg;
        cout << "� ����� �������� �� �� ������ �������� ������ �����? ";
        cin >> lg;
        HarryPotter.set_language(lg);
    }
    catch (const LanguageException& ex) {
        cout << "������ �����: " << ex.what() << endl;
    }

    try {
        int t1;
        cout << "��� �� �������, ������� ���� �������� ����� �������? : ";
        cin >> t1;
        HarryPotter.set_books(t1);
    }
    catch (const AuthorBooksException& ex) {  
        cout << "������ ������: " << ex.what() << endl;
    }

    try {
        int t2;
        cout << "��� �� �������, � ����� ���� �������� ����� �������?: ";
        cin >> t2;
        HarryPotter.set_birth(t2);
    }
    catch (const AuthorBirthException& ex) { 
        cout << "������ ������: " << ex.what() << endl;
    }

    return 0;
}