#pragma once
#include "TransportOption.h"
#include "Car.h"
#include "Bus.h"
#include "Flight.h"
#include "Train.h"
#include "Ship.h"
#include "BisnessClassFlight.h"
#include "EconomyClassFlight.h"
#include "ElectricCar.h"
#include "ExpressBus.h"
#include "HelicopterTransfer.h"
#include "HighSpeedTrain.h"
#include "LuxuryBus.h"
#include "LuxuryTrain.h"
#include "MiniBus.h"
#include "RegionalTrain.h"
#include "SleeperBus.h"
#include "SUVCar.h"
#include "Hotel.h"

class Trip {
    int id;
    TransportOption* transport;
    Hotel* hotel;
    int days;
public:
    Trip(int id, Hotel* hotel, int days);
    double calculateCost();
};