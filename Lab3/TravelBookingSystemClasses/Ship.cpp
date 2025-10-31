#include "Ship.h"

Ship::Ship(double price, double duration) :
    TransportOption("Ship", price, duration), deckCount(5) {
}

int Ship::getDeckCount() {
    return deckCount;
}

bool Ship::hasCabinRooms() {
    return true;
}