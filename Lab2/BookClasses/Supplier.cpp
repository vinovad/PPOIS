#include "Book.h"
using namespace std;

Supplier::Supplier(const string& name, const ImportCountry& importCountry, const BookCondition& bookCondition)
    : supplier_name(name), associatedImportCountry(importCountry), associatedBookCondition(bookCondition) {
}
Supplier::Supplier() : supplier_name("Bloomsbury Publishing"),
associatedImportCountry(ImportCountry("United Kingdom", Prohibited(false, Country("Belarus")))),
associatedBookCondition(BookCondition("new")) {
}
string Supplier::get_supplier() { return supplier_name; }
string Supplier::get_AssociatedImportCountry() { return associatedImportCountry.get_import_country(); }
bool Supplier::get_AssociatedImportProhibited() { return associatedImportCountry.get_AssociatedProhibitedStatus(); }
string Supplier::get_AssociatedBookCondition() { return associatedBookCondition.get_condition(); }