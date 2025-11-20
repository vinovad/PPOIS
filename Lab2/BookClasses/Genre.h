#ifndef GENRE_H
#define GENRE_H

#include "Tag.h"
#include <string>
using namespace std;
class Genre {
private:
    string genre;      
    Tag associatedTag;    

public:
    Genre(const string& g, const Tag& tag);
    Genre();
    string get_Genre();
    string get_AssociatedTag();
    void set_Genre(string gen);
};


#endif
