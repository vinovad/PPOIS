#include "Book.h"
using namespace std;

Reviews::Reviews(const string& rev) : reviews(rev) {}
Reviews::Reviews() : reviews("Отличная книга о магии и приключениях!") {}
string Reviews::get_reviews() { return reviews; }