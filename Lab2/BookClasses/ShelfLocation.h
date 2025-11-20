#ifndef SHELFLOCATION_H
#define SHELFLOCATION_H

#include "PositionLocation.h"
#include <string>
using namespace std;
class ShelfLocation {
private:
    string shelf;             
    PositionLocation associatedPosition; 

public:
    ShelfLocation(const string& sh, const PositionLocation& position);
    ShelfLocation();
    string get_shelf();
    int get_AssociatedPosition();
};


#endif
