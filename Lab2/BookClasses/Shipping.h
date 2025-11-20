#ifndef SHIPPING_H
#define SHIPPING_H

#include "User.h"
#include <string>
using namespace std;
class Shipping {
private:
    bool has_shipping;
    User associatedUser;
    string shipping_type;
    double shipping_cost;
    string tracking_number;
    string carrier;
    string estimated_delivery_date;
    string shipping_status;

public:
    Shipping(bool shipping, const User& user);
    Shipping();
    bool has_shipping_available();
    string get_AssociatedUserName();
    string get_shipping_type();
    double get_shipping_cost();
    void set_shipping_status(bool shipping);
};


#endif

