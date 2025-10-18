#include "Book.h"
using namespace std;

TargetAudience::TargetAudience(const string& type, const EducationLevel& educationLevel)
    : audience_type(type), associatedEducationLevel(educationLevel) {
}
TargetAudience::TargetAudience() : audience_type("teenagers"), associatedEducationLevel(EducationLevel("middle_school")) {}
string TargetAudience::get_audience_type() { return audience_type; }
string TargetAudience::get_AssociatedEducationLevel() { return associatedEducationLevel.get_education_level(); }