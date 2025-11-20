#ifndef SECTIONLOCATION_H
#define SECTIONLOCATION_H

#include "ShelfLocation.h"
#include <string>
using namespace std;
class SectionLocation {
private:
    string section;            
    ShelfLocation associatedShelf; 

public:
    SectionLocation(const string& sec, const ShelfLocation& shelf);
    SectionLocation(const string& sec);
    SectionLocation();
    string get_section();
    string get_AssociatedShelf();
};


#endif
