#ifndef PRICE_H
#define PRICE_H
#include "Sale.h"
#include <string>
using namespace std;
class Price {
private:
    double price;     
    string currency;   
    Sale associatedSale; 
    double tax_amount;    
    double shipping_cost;  

public:
    Price(double p, const string& curr, const Sale& sale);
    Price();
    double get_price();
    string get_currency();
    double get_AssociatedDiscount();
    string get_AssociatedSalePeriod();
};


#endif
