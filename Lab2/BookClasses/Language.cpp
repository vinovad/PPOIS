#include "Book.h"
#include "LanguageException.h"
#include <iostream>
using namespace std;

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