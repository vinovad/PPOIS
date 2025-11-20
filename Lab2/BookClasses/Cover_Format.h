#ifndef COVER_FORMAT_H
#define COVER_FORMAT_H
#include "Publisher.h"
#include <string>
using namespace std;
class Cover_Format {
private:
    string format;          
    Publisher associatedPublisher;

public:
    Cover_Format(const string& f, const Publisher& publisher);
    Cover_Format();
    string get_format();
    string get_AssociatedPublisher();
    void set_format(string f);
};


#endif
