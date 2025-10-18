#include "Book.h"
using namespace std;

LimitedSeries::LimitedSeries(bool limited, const BookVolumeCount& volumeCount)
    : is_limited(limited), associatedVolumeCount(volumeCount) {
}
LimitedSeries::LimitedSeries() : is_limited(false), associatedVolumeCount(BookVolumeCount(7, BookSeries("Harry Potter"))) {}
bool LimitedSeries::is_limited_edition() { return is_limited; }
int LimitedSeries::get_AssociatedVolumeCount() { return associatedVolumeCount.get_volume_number(); }