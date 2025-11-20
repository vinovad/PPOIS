#ifndef LOYALTYPROGRAM_H
#define LOYALTYPROGRAM_H
#include "User.h"
class LoyaltyProgram { 
private:
    User associatedUser;
    double discount_percentage;
    bool has_user;
    int total_points;
    string tier;
    vector<string> benefits;

public:
    LoyaltyProgram(const User& user_obj);
    LoyaltyProgram();
    void update_discount();
    double get_discount();
    double apply_discount(double original_price);
    string get_AssociatedUserName();
    int get_AssociatedUserBooks();
    void set_user(const User& user_obj);
    bool has_user_set() const;
};

#endif

