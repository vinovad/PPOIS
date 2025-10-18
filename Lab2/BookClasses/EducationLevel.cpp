#include "Book.h"
using namespace std;

EducationLevel::EducationLevel(const string& lvl) : level(lvl) {}
EducationLevel::EducationLevel() : level("middle_school") {}
string EducationLevel::get_education_level() { return level; }