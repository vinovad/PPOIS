#ifndef AUTHOR_H
#define AUTHOR_H
#include "Country.h"
#include "Language.h"
#include <string>
#include <vector>
using namespace std;
class Author {
private:
    string name;
    string birth_year;
    int books_written;
    Country associatedCountry;
    Language associatedLanguage;
    string pseudonym;
    string nationality;
    string awards;
    string education;
    string death_year;
    string biography;
    string website;
    string social_media;
    vector<string> genres;
public:
    Author(const string& n, const string& by, int bw, const Country& country, const Language& language);
    Author();
    string get_Author();
    string get_birth();
    int get_books();
    string get_AssociatedCountry();
    string get_AssociatedLanguage();
    void set_birth(int by);
    void set_books(int bw);
};


#endif

