#include "Book.h"
using namespace std;

BookCondition::BookCondition(const string& cond) : condition(cond) {}
BookCondition::BookCondition() : condition("new") {}
string BookCondition::get_condition() { return condition; }