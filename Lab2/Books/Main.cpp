```cpp
#include "Book.h"

int main() {
    setlocale(0, "rus");

    book_Name_of_Rose book4;
    try {
        string naz;
        cout << "Подтвердите покупку книги , указав ее название (The Name of the Rose): ";
        getline(cin, naz);
        book4.set_Book(naz);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_NorwegianWood book3;
    try {
        string tag;
        cout << "Введите желаемый тэг для данной книги(Nostalgia, murders, rebirth, etc.): ";
        getline(cin, tag);
        book3.set_Tag(tag);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_Institute book2;
    try {
        string obl;
        cout << "В какой обложке вы бы хотели приобрести книгу(Soft/Hard)?: ";
        getline(cin, obl);
        book2.set_format(obl);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_HarryPotter book1;
    try {
        string genre;
        cout << "К какому жанру относится книга 'Гарри Поттер'? (например: Fantasy, Detective, Romance, etc.): ";
        getline(cin, genre);
        book1.set_Genre(genre);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_Notre_Dame book10;
    try {
        int v;
        cout << "Введите возраст, чтобы узнать, разрешено ли вам читать данную книгу: ";
        cin >> v;
        book10.set_age_restriction(v);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_War_and_Peace book9;
    try {
        double r;
        cout << "Введите желаемый рейтинг:";
        cin >> r;
        book9.set_rating(r);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_Three_Body_Problem book8;
    try {
        int str;
        cout << " Сколько страниц вы можете осилить? ";
        cin >> str;
        book8.set_number_pages(str);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_Cinderella book7;
    try {
        string izd;
        cout << "От какого издательства вы бы хотели прочесть данную книгу(например:Barbin, Gosselin,L.C. Page & Co., The Russian Messenger)? ";
        cin >> izd;
        book7.set_publisher(izd);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_The_Witcher book6;
    try {
        string god;
        cout << "В каком временном промежутке вы бы хотели прочесть данную книгу(например, 80е)? ";
        cin >> god;
        book6.set_Year(god);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    book_Anne_Green_Gables book5;
    try {
        string lg;
        cout << "В каком переводе вы бы хотели прочесть данную книгу? ";
        cin >> lg;
        book5.set_language(lg);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    Author3 author_test1;
    try {
        int t1;
        cout << "Вы заинтерисовались автором Haruki Murakami, как вы думаете, сколько книг он написал?: ";
        cin >> t1;
        author_test1.set_books(t1);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    Author2 author_test2;
    try {
        int t2;
        cout << "Как вы думаете, в каком году родился Стивен Кинг?: ";
        cin >> t2;
        author_test2.set_birth(t2);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    return 0;
}
```
