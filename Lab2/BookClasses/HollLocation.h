#ifndef HOLLLOCATION_H
#define HOLLLOCATION_H
#include "SectionLocation.h"
class HollLocation {
private:
    int holl;   
    SectionLocation associatedSection; 

public:
    HollLocation(int h, const SectionLocation& section);
    HollLocation();
    int get_holl();
    string get_AssociatedSection();
};


#endif
