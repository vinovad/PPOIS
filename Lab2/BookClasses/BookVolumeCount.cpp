#include "Book.h"
using namespace std;

BookVolumeCount::BookVolumeCount(int volume, const BookSeries& series)
    : volume_number(volume), associatedSeries(series) {
}
BookVolumeCount::BookVolumeCount() : volume_number(7), associatedSeries(BookSeries("Harry Potter")) {}
int BookVolumeCount::get_volume_number() { return volume_number; }
string BookVolumeCount::get_AssociatedSeries() { return associatedSeries.get_series_name(); }