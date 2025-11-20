#ifndef AGE_RESTRICTION_EXCEPTION_H
#define AGE_RESTRICTION_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class AgeRestrictionException : public runtime_error {
public:
    AgeRestrictionException(const string& msg) : runtime_error(msg) {}
};


#endif
