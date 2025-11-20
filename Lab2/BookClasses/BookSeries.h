#ifndef BOOKSERIES_H
#define BOOKSERIES_H
#include <string>
using namespace std;
class BookSeries {
private:
    string series_name;   
    int volume_number;   

public:
    BookSeries(const string& name);
    BookSeries();
    string get_series_name();
};


#endif
