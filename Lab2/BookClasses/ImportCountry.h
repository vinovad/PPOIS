#ifndef IMPORTCOUNTRY_H
#define IMPORTCOUNTRY_H

#include "Prohibited.h"
#include <string>
using namespace std;
class ImportCountry {
private:
    string import_country; 
    Prohibited associatedProhibited;

public:
    ImportCountry(const string& country, const Prohibited& prohibited);
    ImportCountry();
    string get_import_country();
    bool get_AssociatedProhibitedStatus();
    string get_AssociatedProhibitedCountry();
};


#endif
