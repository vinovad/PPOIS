#include "Book.h"
#include "PublisherException.h"
#include <iostream>
using namespace std;

Publisher::Publisher(const string& p) : publisher(p) {}
Publisher::Publisher() : publisher("Bloomsbury") {}
string Publisher::get_publisher() { return publisher; }

void Publisher::set_publisher(string p) {
    if (p != "Bloomsbury") {
        throw PublisherException("Данная книга выпущена другим издательством");
    }
    else {
        cout << " Хорошего чтения!" << endl;
    }
    publisher = p;
}