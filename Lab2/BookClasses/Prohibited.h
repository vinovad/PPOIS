#ifndef PROHIBITED_H
#define PROHIBITED_H
#include "Country.h"
class Prohibited {
private:
    bool is_prohibited; 
    Country associatedCountry; 

public:
    Prohibited(bool prohibited, const Country& country);
    Prohibited();
    bool get_is_prohibited();
    string get_AssociatedCountry();
};


#endif
