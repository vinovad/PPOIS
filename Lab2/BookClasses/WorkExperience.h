#ifndef WORKEXPERIENCE_H
#define WORKEXPERIENCE_H

#include <string>
using namespace std;
class WorkExperience {
private:
    int years_of_experience;    
    string previous_companies;
    string specialization;    

public:
    WorkExperience(int experience);=
    WorkExperience();
    int get_years_of_experience() const;
};


#endif
