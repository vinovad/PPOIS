#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "ImportCountry.h"
#include "BookCondition.h"
#include <string>
using namespace std;
class Supplier {
private:
    string supplier_name;              
    ImportCountry associatedImportCountry; 
    BookCondition associatedBookCondition; 

public:
    Supplier(const string& name, const ImportCountry& importCountry, const BookCondition& bookCondition);
    Supplier();
    string get_supplier();
    string get_AssociatedImportCountry();
    bool get_AssociatedImportProhibited();
    string get_AssociatedBookCondition();
};


#endif
