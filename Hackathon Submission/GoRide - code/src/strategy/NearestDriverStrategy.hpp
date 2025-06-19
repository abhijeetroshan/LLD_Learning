#pragma once
#include "IMatchingStrategy.hpp"

class NearestDriverStrategy : public IMatchingStrategy {
public:
    Driver* matchDriver(std::vector<Driver*>& drivers, const std::string& location, const std::string& type) override {
        for (Driver* d : drivers) {
            if (d->available && d->vehicleType == type && d->location == location)
                return d;
        }
        return nullptr;
    }
};
