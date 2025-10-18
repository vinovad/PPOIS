#include "Book.h"
using namespace std;

NumberOfTranslations::NumberOfTranslations(int tran, const Language& language)
    : number_translations(tran), associatedLanguage(language) {
}
NumberOfTranslations::NumberOfTranslations() : number_translations(1), associatedLanguage(Language("English")) {}
int NumberOfTranslations::get_number_translations() { return number_translations; }
string NumberOfTranslations::get_AssociatedLanguage() { return associatedLanguage.get_language(); }