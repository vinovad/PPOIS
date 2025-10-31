#include "Review.h"

Review::Review(int rate, std::string comment, int customer) : rate(rate), comment(comment), customer(customer) {}

void Review::display() {
    try {
        std::cout << "Review ID :" << this->id << std::endl;
        std::cout << "Rate : " << rate << " / 5" << std::endl;
        if (!comment.empty()) {
            std::cout << " comment :" << comment << std::endl;
        }
        else {
            throw ReviewException();
        }
    }
    catch (ReviewException r) {
        std::cout << r.what();
    }
}