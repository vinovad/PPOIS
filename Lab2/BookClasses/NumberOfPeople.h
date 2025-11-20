#ifndef NUMBEROFPEOPLE_H
#define NUMBEROFPEOPLE_H
#include "User.h"
class NumberOfPeople {
private:
    int number_people;   
    User associatedUser;  

public:
    NumberOfPeople(int people, const User& user);
    NumberOfPeople();
    int get_number_people();
    string get_AssociatedUserName();
    int get_AssociatedUserBooks();
};


#endif
