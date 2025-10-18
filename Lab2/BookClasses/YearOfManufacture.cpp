#include "Book.h"
#include "YearException.h"
#include <iostream>
using namespace std;

YearOfManufacture::YearOfManufacture(int y) : year(y) {}
YearOfManufacture::YearOfManufacture() : year(1997) {}
int YearOfManufacture::get_Year() { return year; }
void YearOfManufacture::set_Year(int y) { year = y; }

void YearOfManufacture::set_Year(string g) {
    if (g != "90e") {
        throw YearException("Данная книга не относится к этому времени");
    }
    else {
        cout << "Данная книга 1997 года. Хорошего чтения!" << endl;
    }
}