#include "Book.h"
using namespace std;

NumberOfPeople::NumberOfPeople(int people, const User& user)
    : number_people(people), associatedUser(user) {
}
NumberOfPeople::NumberOfPeople() : number_people(1000), associatedUser(User("Гость")) {}
int NumberOfPeople::get_number_people() { return number_people; }
string NumberOfPeople::get_AssociatedUserName() { return associatedUser.get_name(); }
int NumberOfPeople::get_AssociatedUserBooks() { return associatedUser.get_books_bought(); }