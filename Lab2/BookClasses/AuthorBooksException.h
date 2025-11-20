#ifndef AUTHOR_BOOKS_EXCEPTION_H
#define AUTHOR_BOOKS_EXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class AuthorBooksException : public runtime_error {
public:
    AuthorBooksException(const string& msg) : runtime_error(msg) {}
};


#endif
