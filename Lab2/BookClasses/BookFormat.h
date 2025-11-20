#ifndef BOOKFORMAT_H
#define BOOKFORMAT_H

#include "PageCount.h"
#include <string>
using namespace std;
class BookFormat {
private:
    string bookformat;        
    PageCount associatedPageCount; 

public:
    BookFormat(const string& bf, const PageCount& pageCount);
    BookFormat();
    string get_bookformat();
    int get_AssociatedPageCount();
};


#endif
