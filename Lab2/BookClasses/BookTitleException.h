#ifndef BOOK_TITLE_EXCEPTION_H
#define BOOK_TITLE_EXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class BookTitleException : public runtime_error {
public:
    BookTitleException(const string& msg) : runtime_error(msg) {}
};


#endif
