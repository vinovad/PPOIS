#include "Book.h"
using namespace std;

BookWeight::BookWeight(double w, const BookFormat& format) : weight(w), associatedFormat(format) {}
BookWeight::BookWeight() : weight(600.0), associatedFormat(BookFormat("A5", PageCount(400))) {}
double BookWeight::get_weight() { return weight; }
string BookWeight::get_AssociatedFormat() { return associatedFormat.get_bookformat(); }