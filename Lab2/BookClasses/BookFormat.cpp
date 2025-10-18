#include "Book.h"
using namespace std;

BookFormat::BookFormat(const string& bf, const PageCount& pageCount)
    : bookformat(bf), associatedPageCount(pageCount) {
}
BookFormat::BookFormat() : bookformat("A5"), associatedPageCount(PageCount(400)) {}
string BookFormat::get_bookformat() { return bookformat; }
int BookFormat::get_AssociatedPageCount() { return associatedPageCount.get_number_pages(); }