#ifndef BOOKWEIGHT_H
#define BOOKWEIGHT_H
#include "BookFormat.h"
class BookWeight {
private:
    double weight;           
    double shipping_weight;    
    string weight_category;   
    BookFormat associatedFormat; 

public:
BookWeight(double w, const BookFormat& format);
    BookWeight();
    double get_weight();
    string get_AssociatedFormat();
};


#endif
