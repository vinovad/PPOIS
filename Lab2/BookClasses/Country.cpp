#include "Book.h"
using namespace std;

Country::Country(const string& c) : country(c) {}
Country::Country() : country("United Kingdom") {}
string Country::get_country() { return country; }