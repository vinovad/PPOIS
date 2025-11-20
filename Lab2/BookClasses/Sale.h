#ifndef SALE_H
#define SALE_H

#include <string>
using namespace std;
class Sale {
private:
    double discount_percentage; 
    string sale_period;        
    string promotion_code;     
    int max_uses;               

public:
    Sale(double discount, const string& period);
    Sale();
    double get_discount();
    string get_sale_period();
};


#endif
