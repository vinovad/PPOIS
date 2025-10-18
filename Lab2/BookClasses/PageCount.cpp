#include "Book.h"
#include "PageCountException.h"
#include <iostream>
using namespace std;

PageCount::PageCount(int pages) : number_pages(pages) {}
PageCount::PageCount() : number_pages(400) {}
int PageCount::get_number_pages() { return number_pages; }

void PageCount::set_number_pages(int n) {
    if (n < 362) {
        throw PageCountException("���������� ������� � ������ ����� ������, ��� �� �������");
    }
    else {
        cout << "�������� ������!" << endl;
    }
    number_pages = n;
}