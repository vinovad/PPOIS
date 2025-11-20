
#ifndef AGERESTRICTION_H
#define AGERESTRICTION_H
#include "TargetAudience.h"
#include "User.h"
class AgeRestriction {
private:
    int age_restriction;            
    TargetAudience associatedAudience; 
    User associatedUser;   

public:
    AgeRestriction(int age, const TargetAudience& audience, const User& user);
    AgeRestriction();
    int get_age_restriction();
    string get_AssociatedAudience();
    string get_AssociatedAudienceEducation();
    string get_AssociatedUserName();
    int get_AssociatedUserBooks();
    void set_age_restriction(int v);
};


#endif
