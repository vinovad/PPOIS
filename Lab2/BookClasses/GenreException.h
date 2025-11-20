#ifndef GENRE_EXCEPTION_H
#define GENRE_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class GenreException : public runtime_error {
public:
    GenreException(const string& msg) : runtime_error(msg) {}
};


#endif
