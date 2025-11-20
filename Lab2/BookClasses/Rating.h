
#ifndef RATING_H
#define RATING_H
class Rating {
private:
    double rating;        
    int number_of_votes;    
    double average_rating; 

public:
    Rating(double r);
    Rating();
    double get_rating();
    void set_rating(double r);
};


#endif
