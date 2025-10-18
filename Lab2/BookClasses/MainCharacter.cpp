#include "Book.h"
using namespace std;

MainCharacter::MainCharacter(const string& nc, const BookVolumeCount& volumeCount)
    : name_character(nc), associatedVolumeCount(volumeCount) {
}
MainCharacter::MainCharacter() : name_character("Harry Potter"), associatedVolumeCount(BookVolumeCount(7, BookSeries("Harry Potter"))) {}
string MainCharacter::get_character() { return name_character; }
int MainCharacter::get_AssociatedVolumeCount() { return associatedVolumeCount.get_volume_number(); }
string MainCharacter::get_AssociatedSeries() { return associatedVolumeCount.get_AssociatedSeries(); }