#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
using namespace std;
class Country {
private:
    string country; 

public:
    Country(const string& c);
    Country();
    string get_country();
};


#endif
