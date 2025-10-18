#include "Book.h"
using namespace std;

Prohibited::Prohibited(bool prohibited, const Country& country)
    : is_prohibited(prohibited), associatedCountry(country) {
}
Prohibited::Prohibited() : is_prohibited(false), associatedCountry(Country("Belarus")) {}
bool Prohibited::get_is_prohibited() { return is_prohibited; }
string Prohibited::get_AssociatedCountry() { return associatedCountry.get_country(); }