#include "Book.h"
using namespace std;

WorkExperience::WorkExperience(int experience) : years_of_experience(experience) {}
WorkExperience::WorkExperience() : years_of_experience(0) {}
int WorkExperience::get_years_of_experience() const { return years_of_experience; }