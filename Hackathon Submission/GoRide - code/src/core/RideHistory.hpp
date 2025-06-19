#pragma once
#include <vector>
#include "Ride.hpp"

class RideHistory {
    std::vector<Ride*> rides;
public:
    void addRide(Ride* r) {
        rides.push_back(r);
    }
};
