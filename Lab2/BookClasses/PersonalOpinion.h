#ifndef PERSONALOPINION_H
#define PERSONALOPINION_H
#include "NumberOfPeople.h"
#include <string>
using namespace std;
class PersonalOpinion {
private:
    string opinion;           
    NumberOfPeople associatedPeople; 
    int recommendation_score;     
    string opinion_date;        

public:
    PersonalOpinion(const string& op, const NumberOfPeople& people);
    PersonalOpinion();
    string get_opinion();
    int get_AssociatedPeople();
};


#endif
