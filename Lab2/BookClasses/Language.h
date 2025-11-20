#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>
using namespace std;
class Language {
private:
    string language; 

public:
    Language(const string& l);
    Language();
    string get_language();
    void set_language(string l);
};


#endif
