#ifndef BOOKCONDITION_H
#define BOOKCONDITION_H
#include <string>
using namespace std;
class BookCondition {
private:
    string condition;           
    int wear_level;
    string damage_description;  

public:
    BookCondition(const string& cond);
    BookCondition();
    string get_condition();
};


#endif
