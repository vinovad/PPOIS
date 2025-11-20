#ifndef NUMBEROFREVIEWS_H
#define NUMBEROFREVIEWS_H
#include "Reviews.h"
class NumberOfReviews {
private:
    int number_reviews;     
    Reviews associatedReviews; 
    int positive_reviews;  
    int negative_reviews;   

public:
    NumberOfReviews(int nr, const Reviews& reviews);
    NumberOfReviews();
    int get_number_reviews();
    string get_AssociatedReviews();
};


#endif
