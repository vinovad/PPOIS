#pragma once
#include <iostream>
#include <string>
#include "ReviewException.h"

class Review {
public:
    int id;
    int customer;
    int rate;
    std::string comment;

    Review(int rate, std::string comment, int customer);
    void display();
};