#include "Book.h"
using namespace std;

Reviews::Reviews(const string& rev) : reviews(rev) {}
Reviews::Reviews() : reviews("�������� ����� � ����� � ������������!") {}
string Reviews::get_reviews() { return reviews; }