#include "BookingExceprion.h"

BookingExceprion::BookingExceprion()
    : std::runtime_error("this booking is already closed") {}