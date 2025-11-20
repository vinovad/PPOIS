#ifndef NUMBEROFTRANSLATIONS_H
#define NUMBEROFTRANSLATIONS_H

#include "Language.h"
class NumberOfTranslations {
private:
    int number_translations;   
    Language associatedLanguage; 

public:
    NumberOfTranslations(int tran, const Language& language);
    NumberOfTranslations();
    int get_number_translations();
    string get_AssociatedLanguage();
};


#endif
