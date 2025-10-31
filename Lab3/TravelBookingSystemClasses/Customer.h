#pragma once 
#include "User.h"
#include "Review.h"
#include <vector>
#include "ContactInfo.h"
#include "LoyalityProgramm.h" 

class Customer : public User, public ContactInfo {
public:
    LoyalityProgramm loyalty;
    std::vector<int> bookingsID;
    Customer(std::string name, std::string password, int id = 0, std::string email = "", std::string number = "");
    void addReview(int rate, std::string review, int booking_id);
};