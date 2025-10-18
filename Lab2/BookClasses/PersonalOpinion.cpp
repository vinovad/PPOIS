#include "Book.h"
using namespace std;

PersonalOpinion::PersonalOpinion(const string& op, const NumberOfPeople& people)
    : opinion(op), associatedPeople(people) {
}
PersonalOpinion::PersonalOpinion() : opinion("���������� � ���������!"), associatedPeople(NumberOfPeople(1000, User("�����"))) {}
string PersonalOpinion::get_opinion() { return opinion; }
int PersonalOpinion::get_AssociatedPeople() { return associatedPeople.get_number_people(); }