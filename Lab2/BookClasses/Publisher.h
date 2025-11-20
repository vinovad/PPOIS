#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
using namespace std;
class Publisher {
private:
    string publisher;       
    string founder;  
    int foundation_year;     
    string headquarters;   

public:
    Publisher(const string& p);
    Publisher();
    string get_publisher();
    void set_publisher(string p);
};


#endif
