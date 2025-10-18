#include "Book.h"
using namespace std;

ArrivalDate::ArrivalDate(const string& d) : date(d) {}
ArrivalDate::ArrivalDate() : date("12-10-2025") {}
string ArrivalDate::get_arrival_date() { return date; }