#pragma once 
#include "Room.h"
#include "ContactInfo.h"

class Hotel : public Room, public ContactInfo {
private:
    int starRating;
public:
    std::string name;
    Hotel(std::string name, int price, std::string email, std::string phone);
    Hotel(std::string name, int price, std::string email, std::string phone, Coordinates* coordinates);
    int getStarRating();       
    bool hasPool();            
};