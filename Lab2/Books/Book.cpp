```cpp
#include "Book.h"

string Genre_Fantasy::get_Genre() { return genre; }
string Genre_Triller::get_Genre() { return genre; }
string Genre_Horrors::get_Genre() { return genre; }
string Genre_Detective::get_Genre() { return genre; }
string Genre_Romance_novel::get_Genre() { return genre; }
string Genre_Classic::get_Genre() { return genre; }
string Genre_Fairy_tale::get_Genre() { return genre; }
string Genre_Romance::get_Genre() { return genre; }
string Genre_Adventure::get_Genre() { return genre; }
string Genre_Science_Fiction::get_Genre() { return genre; }

string Author1::get_Author() { return name; }
string Author1::get_birth() { return birth_year; }
int Author1::get_books() { return books_written; }

string Author2::get_Author() { return name; }
void Author2::set_birth(int by) {
    if (by != 1947) {
        throw Exception("Не угадали, почитайте биографию");
    }
    else {
        cout << "Угадали!" << endl;
    }
}
int Author2::get_books() { return books_written; }

string Author3::get_Author() { return name; }
string Author3::get_birth() { return birth_year; }
void Author3::set_books(int bw) {
    if (bw != 14) {
        throw Exception("Не угадали, почитайте биографию");
    }
    else {
        cout << "Угадали!" << endl;
    }
    books_written = bw;
}

string Author4::get_Author() { return name; }
string Author4::get_birth() { return birth_year; }
int Author4::get_books() { return books_written; }

string Author5::get_Author() { return name; }
string Author5::get_birth() { return birth_year; }
int Author5::get_books() { return books_written; }

string Author6::get_Author() { return name; }
string Author6::get_birth() { return birth_year; }
int Author6::get_books() { return books_written; }

string Author7::get_Author() { return name; }
string Author7::get_birth() { return birth_year; }
int Author7::get_books() { return books_written; }

string Author8::get_Author() { return name; }
string Author8::get_birth() { return birth_year; }
int Author8::get_books() { return books_written; }

string Author9::get_Author() { return name; }
string Author9::get_birth() { return birth_year; }
int Author9::get_books() { return books_written; }

string Author10::get_Author() { return name; }
string Author10::get_birth() { return birth_year; }
int Author10::get_books() { return books_written; }

int Year_of_manufacture1::get_Year() { return year; }
int Year_of_manufacture2::get_Year() { return year; }
int Year_of_manufacture3::get_Year() { return year; }
int Year_of_manufacture4::get_Year() { return year; }
int Year_of_manufacture5::get_Year() { return year; }
int Year_of_manufacture6::get_Year() { return year; }
void Year_of_manufacture6::set_Year(int y) { year = y; }
int Year_of_manufacture7::get_Year() { return year; }
int Year_of_manufacture8::get_Year() { return year; }
int Year_of_manufacture9::get_Year() { return year; }
int Year_of_manufacture10::get_Year() { return year; }


string Main_character1::get_character() { return name_character; }
string Main_character2::get_character() { return name_character; }
string Main_character3::get_character() { return name_character; }
string Main_character4::get_character() { return name_character; }
string Main_character5::get_character() { return name_character; }
string Main_character6::get_character() { return name_character; }
string Main_character7::get_character() { return name_character; }
string Main_character8::get_character() { return name_character; }
string Main_character9::get_character() { return name_character; }
string Main_character10::get_character() { return name_character; }


string Country_of_origin1::get_country() { return country; }
string Country_of_origin2::get_country() { return country; }
string Country_of_origin3::get_country() { return country; }
string Country_of_origin4::get_country() { return country; }
string Country_of_origin5::get_country() { return country; }
string Country_of_origin6::get_country() { return country; }
string Country_of_origin7::get_country() { return country; }
string Country_of_origin8::get_country() { return country; }
string Country_of_origin9::get_country() { return country; }
string Country_of_origin10::get_country() { return country; }


int book_HarryPotter::get_number_pages() { return number_pages1; }
string book_HarryPotter::get_Book() { return title_book; }
void book_HarryPotter::set_Genre(string gen) {
    if (gen != "Fantasy") {
        throw Exception("Данная книга не относится к этому жанру");
    }
    else {
        cout << "Книга Гарри Поттер относится к жанру Фэнтези. Хорошего чтения!" << endl;
    }
}
string book_HarryPotter::get_Author() { return Author.get_Author(); }
int book_HarryPotter::get_Year() { return Year_of_manufacture.get_Year(); }
string book_HarryPotter::get_character() { return Main_character.get_character(); }
string book_HarryPotter::get_Tag() { return book_tag1; }
string book_HarryPotter::get_publisher() { return publisher; }
string book_HarryPotter::get_language() { return language; }
double book_HarryPotter::get_rating() { return rating; }
string book_HarryPotter::get_format() { return format; }
int book_HarryPotter::get_age_restriction() { return age_restriction; }

int book_Institute::get_number_pages() { return number_pages2; }
string book_Institute::get_Book() { return title_book; }
string book_Institute::get_Genre() { return Genre_Horrors::get_Genre(); }
string book_Institute::get_Author() { return Author.get_Author(); }
int book_Institute::get_Year() { return Year_of_manufacture.get_Year(); }
string book_Institute::get_character() { return Main_character.get_character(); }
string book_Institute::get_Tag() { return book_tag2; }
string book_Institute::get_publisher() { return publisher; }
string book_Institute::get_language() { return language; }
double book_Institute::get_rating() { return rating; }
void book_Institute::set_format(string f) {
    if (f != "Soft") {
        throw Exception("Данная книга есть только в Мягкой обложке");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    format = f;
}
int book_Institute::get_age_restriction() { return age_restriction; }

int book_NorwegianWood::get_number_pages() { return number_pages3; }
string book_NorwegianWood::get_Book() { return title_book; }
string book_NorwegianWood::get_Genre() { return Genre_Triller::get_Genre(); }
string book_NorwegianWood::get_Author() { return Author.get_Author(); }
int book_NorwegianWood::get_Year() { return Year_of_manufacture.get_Year(); }
string book_NorwegianWood::get_character() { return Main_character.get_character(); }
void book_NorwegianWood::set_Tag(string tg) {
    if (tg != "Nostalgia") {
        throw Exception("Данная книга не содержит данного тега");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    book_tag3 = tg;
}
string book_NorwegianWood::get_publisher() { return publisher; }
string book_NorwegianWood::get_language() { return language; }
double book_NorwegianWood::get_rating() { return rating; }
string book_NorwegianWood::get_format() { return format; }
int book_NorwegianWood::get_age_restriction() { return age_restriction; }

int book_Name_of_Rose::get_number_pages() { return number_pages4; }
void book_Name_of_Rose::set_Book(string tb) {
    if (tb != "The Name of the Rose") {
        throw Exception("Название не соответствует введенному, заявка отклонена");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    title_book = tb;
}
string book_Name_of_Rose::get_Genre() { return Genre_Detective::get_Genre(); }
string book_Name_of_Rose::get_Author() { return Author.get_Author(); }
int book_Name_of_Rose::get_Year() { return Year_of_manufacture.get_Year(); }
string book_Name_of_Rose::get_character() { return Main_character.get_character(); }
string book_Name_of_Rose::get_Tag() { return book_tag4; }
string book_Name_of_Rose::get_publisher() { return publisher; }
string book_Name_of_Rose::get_language() { return language; }
double book_Name_of_Rose::get_rating() { return rating; }
string book_Name_of_Rose::get_format() { return format; }
int book_Name_of_Rose::get_age_restriction() { return age_restriction; }

int book_Anne_Green_Gables::get_number_pages() { return number_pages5; }
string book_Anne_Green_Gables::get_Book() { return title_book; }
string book_Anne_Green_Gables::get_Genre() { return Genre_Romance_novel::get_Genre(); }
string book_Anne_Green_Gables::get_Author() { return Author.get_Author(); }
int book_Anne_Green_Gables::get_Year() { return Year_of_manufacture.get_Year(); }
string book_Anne_Green_Gables::get_character() { return Main_character.get_character(); }
string book_Anne_Green_Gables::get_Tag() { return book_tag5; }
string book_Anne_Green_Gables::get_publisher() { return publisher; }
void book_Anne_Green_Gables::set_language(string l) {
    if (l != "English") {
        throw Exception("Данной книги в таком переводе нет");
    }
    else { cout << "Хорошего чтения!" << endl; }
    language = l;
}
double book_Anne_Green_Gables::get_rating() { return rating; }
string book_Anne_Green_Gables::get_format() { return format; }
int book_Anne_Green_Gables::get_age_restriction() { return age_restriction; }

int book_The_Witcher::get_number_pages() { return number_pages6; }
string book_The_Witcher::get_Book() { return title_book; }
string book_The_Witcher::get_Genre() { return Genre_Adventure::get_Genre(); }
string book_The_Witcher::get_Author() { return Author.get_Author(); }
void book_The_Witcher::set_Year(string g) {
    if (g != "90e") {
        throw Exception("Данная книга не относится к этому времени");
    }
    else {
        cout << "Данная книга 1990 года. Хорошего чтения!" << endl;
    }
}
string book_The_Witcher::get_character() { return Main_character.get_character(); }
string book_The_Witcher::get_Tag() { return book_tag6; }
string book_The_Witcher::get_publisher() { return publisher; }
string book_The_Witcher::get_language() { return language; }
double book_The_Witcher::get_rating() { return rating; }
string book_The_Witcher::get_format() { return format; }
int book_The_Witcher::get_age_restriction() { return age_restriction; }

int book_Cinderella::get_number_pages() { return number_pages7; }
string book_Cinderella::get_Book() { return title_book; }
string book_Cinderella::get_Genre() { return Genre_Fairy_tale::get_Genre(); }
string book_Cinderella::get_Author() { return Author.get_Author(); }
int book_Cinderella::get_Year() { return Year_of_manufacture.get_Year(); }
string book_Cinderella::get_character() { return Main_character.get_character(); }
string book_Cinderella::get_Tag() { return book_tag7; }
void book_Cinderella::set_publisher(string p) {
    if (p != "Barbin") {
        throw Exception("Данная книга выпущена другим издательством");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    publisher = p;
}
string book_Cinderella::get_language() { return language; }
double book_Cinderella::get_rating() { return rating; }
string book_Cinderella::get_format() { return format; }
int book_Cinderella::get_age_restriction() { return age_restriction; }

void book_Three_Body_Problem::set_number_pages(int n) {
    if (n < 362) {
        throw Exception("Количество страниц в в данной книге больше , чем вы ожидали ");
    }
    else { cout << "Хорошего чтения!" << endl; }
    number_pages8 = n;
}
string book_Three_Body_Problem::get_Book() { return title_book; }
string book_Three_Body_Problem::get_Genre() { return Genre_Science_Fiction::get_Genre(); }
string book_Three_Body_Problem::get_Author() { return Author.get_Author(); }
int book_Three_Body_Problem::get_Year() { return Year_of_manufacture.get_Year(); }
string book_Three_Body_Problem::get_character() { return Main_character.get_character(); }
string book_Three_Body_Problem::get_Tag() { return book_tag8; }
string book_Three_Body_Problem::get_publisher() { return publisher; }
string book_Three_Body_Problem::get_language() { return language; }
double book_Three_Body_Problem::get_rating() { return rating; }
string book_Three_Body_Problem::get_format() { return format; }
int book_Three_Body_Problem::get_age_restriction() { return age_restriction; }

int book_War_and_Peace::get_number_pages() { return number_pages9; }
string book_War_and_Peace::get_Book() { return title_book; }
string book_War_and_Peace::get_Genre() { return Genre_Classic::get_Genre(); }
string book_War_and_Peace::get_Author() { return Author.get_Author(); }
int book_War_and_Peace::get_Year() { return Year_of_manufacture.get_Year(); }
string book_War_and_Peace::get_character() { return Main_character.get_character(); }
string book_War_and_Peace::get_Tag() { return book_tag9; }
string book_War_and_Peace::get_publisher() { return publisher; }
string book_War_and_Peace::get_language() { return language; }
void book_War_and_Peace::set_rating(double r) {
    if (r <= 4.7 || r > 5.0) {
        throw Exception("Данна книга не подходит по желаемому рейтингу");
    }
    else { cout << "Хорошего чтения!" << endl; }
    rating = r;
}
string book_War_and_Peace::get_format() { return format; }
int book_War_and_Peace::get_age_restriction() { return age_restriction; }

int book_Notre_Dame::get_number_pages() { return number_pages10; }
string book_Notre_Dame::get_Book() { return title_book; }
string book_Notre_Dame::get_Genre() { return Genre_Romance::get_Genre(); }
string book_Notre_Dame::get_Author() { return Author.get_Author(); }
int book_Notre_Dame::get_Year() { return Year_of_manufacture.get_Year(); }
string book_Notre_Dame::get_character() { return Main_character.get_character(); }
string book_Notre_Dame::get_Tag() { return book_tag10; }
string book_Notre_Dame::get_publisher() { return publisher; }
string book_Notre_Dame::get_language() { return language; }
double book_Notre_Dame::get_rating() { return rating; }
string book_Notre_Dame::get_format() { return format; }
void book_Notre_Dame::set_age_restriction(int v) {
    if (v < 12) {
        throw Exception("Данная книга ограничена для вашего возраста");
    }
    else { cout << "Хорошего чтения!" << endl; }
    age_restriction = v;
}
```
