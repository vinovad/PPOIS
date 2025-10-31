#pragma once
#include <string>
#include <stdexcept>

class ReviewException : public std::runtime_error {
public:
    ReviewException();
};