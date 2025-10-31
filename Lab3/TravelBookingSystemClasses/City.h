#pragma once
#include <iostream>
#include <string>

class City {
public:
    std::string city;
    City(std::string city);
    std::string getName();           
    int getPopulation();            
};