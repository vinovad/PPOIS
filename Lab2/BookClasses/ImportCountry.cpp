#include "Book.h"
using namespace std;

ImportCountry::ImportCountry(const string& country, const Prohibited& prohibited)
    : import_country(country), associatedProhibited(prohibited) {
}
ImportCountry::ImportCountry() : import_country("United Kingdom"), associatedProhibited(Prohibited(false, Country("Belarus"))) {}
string ImportCountry::get_import_country() { return import_country; }
bool ImportCountry::get_AssociatedProhibitedStatus() { return associatedProhibited.get_is_prohibited(); }
string ImportCountry::get_AssociatedProhibitedCountry() { return associatedProhibited.get_AssociatedCountry(); }