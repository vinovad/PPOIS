#include "Book.h"
using namespace std;

ExportCountry::ExportCountry(const string& country2, const Prohibited& prohibited)
    : export_country(country2), associatedProhibited(prohibited) {
}
ExportCountry::ExportCountry() : export_country("United Kingdom"), associatedProhibited(Prohibited(false, Country("Belarus"))) {}
string ExportCountry::get_export_country() { return export_country; }
bool ExportCountry::get_AssociatedProhibitedStatus() { return associatedProhibited.get_is_prohibited(); }
string ExportCountry::get_AssociatedProhibitedCountry() { return associatedProhibited.get_AssociatedCountry(); }