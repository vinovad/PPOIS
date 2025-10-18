#include "Book.h"
using namespace std;

ElectronicPDF::ElectronicPDF(bool pdf, const Audiobook& audio) : has_pdf(pdf), associatedAudiobook(audio) {}
ElectronicPDF::ElectronicPDF() : has_pdf(true), associatedAudiobook(Audiobook(true)) {}
bool ElectronicPDF::has_pdf_version() { return has_pdf; }
bool ElectronicPDF::get_AssociatedAudiobook() { return associatedAudiobook.has_audiobook_version(); }