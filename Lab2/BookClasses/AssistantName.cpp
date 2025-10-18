#include "Book.h"
using namespace std;

AssistantName::AssistantName(const string& name, const WorkExperience& experience)
    : assistantname(name), associatedExperience(experience) {
}
AssistantName::AssistantName() : assistantname("Неизвестный"), associatedExperience(WorkExperience(0)) {}
string AssistantName::get_name() const { return assistantname; }
int AssistantName::get_AssociatedExperience() { return associatedExperience.get_years_of_experience(); }