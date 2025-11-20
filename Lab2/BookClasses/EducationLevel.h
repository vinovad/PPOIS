#ifndef EDUCATIONLEVEL_H
#define EDUCATIONLEVEL_H
#include <string>
using namespace std;
class EducationLevel {
private:
    string level; 

public:
    EducationLevel(const string& lvl);
    EducationLevel();
    string get_education_level();
};


#endif
