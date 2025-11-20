#ifndef ASSISTANTNAME_H
#define ASSISTANTNAME_H

#include "WorkExperience.h"
#include <string>
using namespace std;
class AssistantName {
private:
    string assistantname;          
    WorkExperience associatedExperience; 
    string department;      
    string shift_schedule;    
public:
    AssistantName(const string& name, const WorkExperience& experience);
    AssistantName();
    string get_name() const;
    int get_AssociatedExperience();
};


#endif
