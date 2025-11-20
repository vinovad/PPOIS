#ifndef AUTHOR_BIRTH_EXCEPTION_H
#define AUTHOR_BIRTH_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class AuthorBirthException : public runtime_error {
public:
    AuthorBirthException(const string& msg) : runtime_error(msg) {}
};


#endif
