#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
#include "BookVolumeCount.h"
#include <string>
using namespace std;
class MainCharacter {
private:
    string name_character;         
    BookVolumeCount associatedVolumeCount; 

public:
    MainCharacter(const string& nc, const BookVolumeCount& volumeCount);
    MainCharacter();
    string get_character();
    int get_AssociatedVolumeCount();
    string get_AssociatedSeries();
};


#endif
