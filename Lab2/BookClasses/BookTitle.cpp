#include "Book.h"
#include "BookTitleException.h"
#include <iostream>
using namespace std;

BookTitle::BookTitle(const string& title) : title_book(title) {}
BookTitle::BookTitle() : title_book("Harry Potter") {}
string BookTitle::get_Book() { return title_book; }

void BookTitle::set_Book(string tb) {
    if (tb != "Harry Potter") {
        throw BookTitleException("Название не соответствует введенному, заявка отклонена");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    title_book = tb;
}