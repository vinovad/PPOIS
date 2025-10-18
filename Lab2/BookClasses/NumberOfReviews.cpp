#include "Book.h"
using namespace std;

NumberOfReviews::NumberOfReviews(int nr, const Reviews& reviews)
    : number_reviews(nr), associatedReviews(reviews) {
}
NumberOfReviews::NumberOfReviews() : number_reviews(1000), associatedReviews(Reviews("Отличная книга о магии и приключениях!")) {}
int NumberOfReviews::get_number_reviews() { return number_reviews; }
string NumberOfReviews::get_AssociatedReviews() { return associatedReviews.get_reviews(); }