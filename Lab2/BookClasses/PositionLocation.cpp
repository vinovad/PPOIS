#include "Book.h"
using namespace std;

PositionLocation::PositionLocation(int pos) : position(pos) {}
PositionLocation::PositionLocation() : position(15) {}
int PositionLocation::get_position() { return position; }