#include "Book.h"
using namespace std;

Translator::Translator(const string& tr, const NumberOfTranslations& translations)
    : translator(tr), associatedTranslations(translations) {
}
Translator::Translator() : translator(""), associatedTranslations(NumberOfTranslations(1, Language("Russian"))) {}
string Translator::get_translator() { return translator; }
int Translator::get_AssociatedTranslations() { return associatedTranslations.get_number_translations(); }