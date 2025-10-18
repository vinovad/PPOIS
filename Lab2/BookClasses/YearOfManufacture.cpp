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
        throw YearException("������ ����� �� ��������� � ����� �������");
    }
    else {
        cout << "������ ����� 1997 ����. �������� ������!" << endl;
    }
}