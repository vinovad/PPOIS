#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
class User {
private:
    string name;          
    int books_bought;           
    string email;       
    string phone_number;      
    string registration_date;  
    string address;          
    int loyalty_points;        

public:
    User(const string& user_name);
    User();
    string get_name();
    int get_books_bought();
    void add_purchased_book();
};


#endif
