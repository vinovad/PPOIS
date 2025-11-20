#ifndef REVIEWS_H
#define REVIEWS_H

#include <string>
using namespace std;

class Reviews {
private:
    string reviews;        
    int helpful_votes;      
    string review_date;   

public:
    Reviews(const string& rev);
    Reviews();
    string get_reviews();
};


#endif
