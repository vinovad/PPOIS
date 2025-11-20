#ifndef BOOKTITLE_H
#define BOOKTITLE_H
#include <string>
using namespace std;
class BookTitle {
private:
    string title_book;        
    string original_title;  
    string subtitle;    

public:
    BookTitle(const string& title);
    BookTitle();
    string get_Book();

    void set_Book(string tb);
};


#endif
