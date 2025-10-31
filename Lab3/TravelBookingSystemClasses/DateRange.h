#pragma once 
#include "Date.h"

class DateRange : public Date {
private:
    int rangeId;
public:
    DateRange(int day, int month, int year);
    Date getRange(Date* b);
    int getRangeId();          
    bool isValidRange();       
};