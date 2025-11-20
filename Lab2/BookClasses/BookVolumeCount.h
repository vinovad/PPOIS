#ifndef BOOKVOLUMECOUNT_H
#define BOOKVOLUMECOUNT_H
#include "BookSeries.h"
class BookVolumeCount {
private:
    int volume_number;        
    BookSeries associatedSeries; 

public:
    BookVolumeCount(int volume, const BookSeries& series);
    BookVolumeCount();
    int get_volume_number();
    string get_AssociatedSeries();
};


#endif
