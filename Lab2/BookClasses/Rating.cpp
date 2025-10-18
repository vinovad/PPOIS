#include "Book.h"
#include "RatingException.h"
#include <iostream>
using namespace std;

Rating::Rating(double r) : rating(r) {}
Rating::Rating() : rating(4.8) {}
double Rating::get_rating() { return rating; }

void Rating::set_rating(double r) {
    if (r <= 4.7 || r > 5.0) {
        throw RatingException("Данная книга не подходит по желаемому рейтингу");
    }
    else {
        cout << "Хорошего чтения!" << endl;
    }
    rating = r;
}