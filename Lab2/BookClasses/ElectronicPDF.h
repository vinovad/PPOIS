#ifndef ELECTRONICPDF_H
#define ELECTRONICPDF_H
#include "Audiobook.h"
class ElectronicPDF {
private:
    bool has_pdf;     
    Audiobook associatedAudiobook; 
public:
    ElectronicPDF(bool pdf, const Audiobook& audio);
    ElectronicPDF();
    bool has_pdf_version();
    bool get_AssociatedAudiobook();
};


#endif
