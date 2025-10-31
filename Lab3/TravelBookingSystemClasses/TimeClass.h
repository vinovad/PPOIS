#pragma once
#include <iostream>

class TimeClass {
public:
    int hour, min, sec;
    TimeClass(int seconds);
    int getMin();
    int getHour();
    int getSec();
    std::string getTimeInString();
};