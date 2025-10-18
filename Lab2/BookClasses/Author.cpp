#include "Book.h"
#include "AuthorBirthException.h"
#include "AuthorBooksException.h"
#include <iostream>
using namespace std;

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