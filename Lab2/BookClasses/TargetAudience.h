#ifndef TARGETAUDIENCE_H
#define TARGETAUDIENCE_H

#include "EducationLevel.h"
#include <string>
using namespace std;
class TargetAudience {
private:
    string audience_type;     
    EducationLevel associatedEducationLevel; 

public:
    TargetAudience(const string& type, const EducationLevel& educationLevel);
    TargetAudience();
    string get_audience_type();
    string get_AssociatedEducationLevel();
};


#endif
