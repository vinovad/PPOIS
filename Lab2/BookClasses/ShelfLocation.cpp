#include "Book.h"
using namespace std;

ShelfLocation::ShelfLocation(const string& sh, const PositionLocation& position)
    : shelf(sh), associatedPosition(position) {
}
ShelfLocation::ShelfLocation() : shelf("третья"), associatedPosition(PositionLocation(15)) {}
string ShelfLocation::get_shelf() { return shelf; }
int ShelfLocation::get_AssociatedPosition() { return associatedPosition.get_position(); }