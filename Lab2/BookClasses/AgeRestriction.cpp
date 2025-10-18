#include "Book.h"
#include "AgeRestrictionException.h"
#include <iostream>
using namespace std;

AgeRestriction::AgeRestriction(int age, const TargetAudience& audience, const User& user)
    : age_restriction(age), associatedAudience(audience), associatedUser(user) {
}
AgeRestriction::AgeRestriction() : age_restriction(12), associatedAudience(TargetAudience("teenagers", EducationLevel("middle_school"))), associatedUser(User("Гость")) {}
int AgeRestriction::get_age_restriction() { return age_restriction; }
string AgeRestriction::get_AssociatedAudience() { return associatedAudience.get_audience_type(); }
string AgeRestriction::get_AssociatedAudienceEducation() { return associatedAudience.get_AssociatedEducationLevel(); }
string AgeRestriction::get_AssociatedUserName() { return associatedUser.get_name(); }
int AgeRestriction::get_AssociatedUserBooks() { return associatedUser.get_books_bought(); }

void AgeRestriction::set_age_restriction(int v) {
    if (v < 12) {
        throw AgeRestrictionException("Данная книга ограничена для вашего возраста");
    }
    else {
        cout << "Хорошего чтения!" << endl;
    }
    age_restriction = v;
}