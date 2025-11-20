#ifndef ARRIVALDATE_H
#define ARRIVALDATE_H

#include <string>
using namespace std;
class ArrivalDate {
private:
    string date;            
    string expected_date;  
    string restock_date;    

public:
ArrivalDate(const string& d);
    ArrivalDate();
    string get_arrival_date();
};


#endif
