#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "NumberOfTranslations.h"
#include <string>
using namespace std;
class Translator {
private:
    string translator;                    
    NumberOfTranslations associatedTranslations; 

public:
    Translator(const string& tr, const NumberOfTranslations& translations);
    Translator();
    string get_translator();
    int get_AssociatedTranslations();
};


#endif
