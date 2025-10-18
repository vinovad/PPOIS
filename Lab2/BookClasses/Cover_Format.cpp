#include "Book.h"
#include "CoverFormatException.h"
#include <iostream>
using namespace std;

Cover_Format::Cover_Format(const string& f, const Publisher& publisher) : format(f), associatedPublisher(publisher) {}
Cover_Format::Cover_Format() : format("Hard"), associatedPublisher(Publisher("Bloomsbury")) {}
string Cover_Format::get_format() { return format; }
string Cover_Format::get_AssociatedPublisher() { return associatedPublisher.get_publisher(); }

void Cover_Format::set_format(string f) {
    if (f != "Hard") {
        throw CoverFormatException("Данная книга есть только в Твердой обложке");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    format = f;
}