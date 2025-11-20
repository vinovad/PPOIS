#ifndef LIMITEDSERIES_H
#define LIMITEDSERIES_H

#include "BookVolumeCount.h"
class LimitedSeries {
private:
    bool is_limited;         
    BookVolumeCount associatedVolumeCount; 

public:
    LimitedSeries(bool limited, const BookVolumeCount& volumeCount);
    LimitedSeries();
    bool is_limited_edition();
    int get_AssociatedVolumeCount();
};


#endif
