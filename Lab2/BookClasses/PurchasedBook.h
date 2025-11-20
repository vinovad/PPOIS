#ifndef PURCHASEDBOOK_H
#define PURCHASEDBOOK_H

#include <string>
using namespace std;
class PurchasedBook {
private:
    string book_title;  
    string purchase_date; 
    double purchase_price; 
    string user_name;  

public:
    PurchasedBook(const string& title, const string& date, double price, const string& user);
    PurchasedBook();
    string get_book_title();
    string get_purchase_date();
    double get_purchase_price();
    string get_user_name();
    void display_purchase_info();
};


#endif
