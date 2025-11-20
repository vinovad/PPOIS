#ifndef CUSTOMERARRIVALTIME_H
#define CUSTOMERARRIVALTIME_H
#include "User.h"
#include <string>
using namespace std;
class CustomerArrivalTime {
private:
    string time;      
    string day_of_week;   
    string date_day;    
    string visit_purpose;
    int visit_duration;  

public:
    CustomerArrivalTime(const string& t, const string& day, const string& dd, const User& user);
    CustomerArrivalTime();
    string get_time();
    string get_day_w();
    string get_day_d();
};


#endif
