#include "Room.h"
#include "RoomException.h"

Room::Room(int price) : price(price) {}

Room::Room(int price, Coordinates* coordinates) : price(price), coordinates(coordinates) {}

std::string Room::getCoordinate() {
    try {
        if (coordinates == 0) {
            throw RoomException();
        }
        else {
            return std::to_string(coordinates->latitude) + " " + std::to_string(coordinates->longitude);
        }
    }
    catch (RoomException a) {
        std::cout << "Exception : " << a.what() << std::endl;
        return a.what();
    }
}

double Room::calculateCost(int period) {
    return price * period;
}

bool Room::isAvailable() {
    try {
        if (_isAvailable) {
            return 1;
        }
        else {
            throw RoomError();
        }
    }
    catch (RoomError) {
        return 0;
    }
}

void Room::makeAvailable() {
    _isAvailable = 1;
}

void Room::makeBusy() {
    _isAvailable = 0;
}