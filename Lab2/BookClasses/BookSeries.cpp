#include "Book.h"
using namespace std;

BookSeries::BookSeries(const string& name) : series_name(name) {}
BookSeries::BookSeries() : series_name("Harry Potter"), volume_number(1) {}
string BookSeries::get_series_name() { return series_name; }