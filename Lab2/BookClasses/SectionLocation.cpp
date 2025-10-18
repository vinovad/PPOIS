#include "Book.h"
using namespace std;

SectionLocation::SectionLocation(const string& sec, const ShelfLocation& shelf)
    : section(sec), associatedShelf(shelf) {
}
SectionLocation::SectionLocation(const string& sec)
    : section(sec), associatedShelf(ShelfLocation("������", PositionLocation(15))) {
}
SectionLocation::SectionLocation() : section("A"), associatedShelf(ShelfLocation("������", PositionLocation(15))) {}
string SectionLocation::get_section() { return section; }
string SectionLocation::get_AssociatedShelf() { return associatedShelf.get_shelf(); }