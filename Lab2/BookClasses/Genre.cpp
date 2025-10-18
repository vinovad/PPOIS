#include "Book.h"
#include "GenreException.h"
#include <iostream>
using namespace std;

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