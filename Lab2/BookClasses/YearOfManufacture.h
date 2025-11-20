#ifndef YEAROFMANUFACTURE_H
#define YEAROFMANUFACTURE_H

#include <string>
using namespace std;
class YearOfManufacture {
private:
    int year;

public:
    YearOfManufacture(int y);
    YearOfManufacture();
    int get_Year();
    void set_Year(int y);
    void set_Year(string g);
};


#endif
