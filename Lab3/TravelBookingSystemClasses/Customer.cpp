#include "Customer.h"

Customer::Customer(std::string name, std::string password, int id, std::string email, std::string number) :
    User(name, password, id), ContactInfo(email, number), loyalty(10) {
    whoami = "Customer";
}

void Customer::addReview(int rate, std::string review, int booking_id) {
    Review r(rate, review, this->id);
}