'''cpp
#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(0, "rus");
    User user("Лучший покупатель");
    cout << "Создан пользователь: " << user.get_name() << endl;

    Book HarryPotter("Fantasy", 1997, "Harry Potter", "United Kingdom", "Автор : Joanne Rowling", "1965 год", 15, 4.8, "Hard", "Bloomsbury", "Волшебство", "English", "A5", "Марина Литвинова", 80, 400, "Harry Potter", 12, 25.99, "USD", 15.0, "", false, 50, 600.0, "12-10-2025", "new", "Harry Potter", 1, "A", 1, "третья", 15, "Bloomsbury Publishing", "United Kingdom", "United Kingdom", "teenagers", "middle_school", false, true, true, 1000000, "Отличная книга о магии и приключениях!", "Рекомендую к прочтению!", 1000, "Гость", "Harry Potter", "12-10-2025", 25.99, "Гость", "Harry Potter", user, "Ivan", 20);

    try {
        string genre;
        cout << "К какому жанру относится книга 'Harry Potter'? (например: Fantasy, Detective, Romance, etc.): ";
        getline(cin, genre);
        HarryPotter.set_Genre(genre);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        string naz;
        cout << "Подтвердите покупку книги , указав ее название (Harry Potter): ";
        getline(cin, naz);
        HarryPotter.set_Book(naz);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        string tag;
        cout << "Введите желаемый тэг для данной книги(Magic): ";
        getline(cin, tag);
        HarryPotter.set_Tag(tag);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        string obl;
        cout << "В какой обложке вы бы хотели приобрести книгу(Soft/Hard)?: ";
        getline(cin, obl);
        HarryPotter.set_format(obl);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        int v;
        cout << "Введите возраст, чтобы узнать, разрешено ли вам читать данную книгу: ";
        cin >> v;
        HarryPotter.set_age_restriction(v);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        double r;
        cout << "Введите желаемый рейтинг:";
        cin >> r;
        HarryPotter.set_rating(r);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        int str;
        cout << " Сколько страниц вы можете осилить? ";
        cin >> str;
        HarryPotter.set_number_pages(str);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        string izd;
        cout << "От какого издательства вы бы хотели прочесть данную книгу(например:Barbin, Gosselin,L.C. Page & Co., The Russian Messenger)? ";
        cin >> izd;
        HarryPotter.set_publisher(izd);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        string god;
        cout << "В каком временном промежутке вы бы хотели прочесть данную книгу(например, 80е)? ";
        cin >> god;
        HarryPotter.set_Year(god);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        string lg;
        cout << "В каком переводе вы бы хотели прочесть данную книгу? ";
        cin >> lg;
        HarryPotter.set_language(lg);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        int t1;
        cout << "Как вы думаете, сколько книг написала Джоан Роулинг ? : ";
        cin >> t1;
        HarryPotter.set_books(t1);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    try {
        int t2;
        cout << "Как вы думаете, в каком году родилась  Джоан Роулинг?: ";
        cin >> t2;
        HarryPotter.set_birth(t2);
    }
    catch (const Exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    return 0;
}
'''
