#ifndef TAG_H
#define TAG_H

#include <string>
using namespace std;
class Tag {
private:
    string book_tag; 

public:
    Tag(const string& t);
    Tag();
    string get_Tag();
    void set_Tag(string tg);
};


#endif
