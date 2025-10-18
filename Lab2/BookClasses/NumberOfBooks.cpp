#include "Book.h"
using namespace std;

NumberOfBooks::NumberOfBooks(int qty) : quantity(qty) {}
NumberOfBooks::NumberOfBooks() : quantity(50) {}
int NumberOfBooks::get_quantity() { return quantity; }