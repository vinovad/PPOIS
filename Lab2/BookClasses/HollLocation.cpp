#include "Book.h"
using namespace std;

HollLocation::HollLocation(int h, const SectionLocation& section)
    : holl(h), associatedSection(section) {
}
HollLocation::HollLocation() : holl(1), associatedSection(SectionLocation("A", ShelfLocation("третья", PositionLocation(15)))) {}
int HollLocation::get_holl() { return holl; }
string HollLocation::get_AssociatedSection() { return associatedSection.get_section(); }