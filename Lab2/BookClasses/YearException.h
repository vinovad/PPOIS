
#ifndef YEAR_EXCEPTION_H
#define YEAR_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class YearException : public runtime_error {
public:
    YearException(const string& msg) : runtime_error(msg) {}
};


#endif
