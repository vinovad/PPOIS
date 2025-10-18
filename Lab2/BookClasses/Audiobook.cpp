#include "Book.h"
using namespace std;

Audiobook::Audiobook(bool audio) : has_audiobook(audio) {}
Audiobook::Audiobook() : has_audiobook(true) {}
bool Audiobook::has_audiobook_version() { return has_audiobook; }