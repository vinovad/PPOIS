#include "Book.h"
#include "TagException.h"
#include <iostream>
using namespace std;

Tag::Tag(const string& t) : book_tag(t) {}
Tag::Tag() : book_tag("Magic") {}
string Tag::get_Tag() { return book_tag; }

void Tag::set_Tag(string tg) {
    if (tg != "Magic") {
        throw TagException("Данная книга не содержит данного тега");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    book_tag = tg;
}