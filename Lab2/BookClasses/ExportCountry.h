#ifndef EXPORTCOUNTRY_H
#define EXPORTCOUNTRY_H
#include "Prohibited.h"
#include <string>
using namespace std;
class ExportCountry {
private:
    string export_country;   
    Prohibited associatedProhibited; 

public:
    ExportCountry(const string& country2, const Prohibited& prohibited);
    ExportCountry();
    string get_export_country();
    bool get_AssociatedProhibitedStatus();
    string get_AssociatedProhibitedCountry();
};


#endif
