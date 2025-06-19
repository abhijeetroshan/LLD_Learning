#pragma once
#include "Sedan.hpp"
#include "SUV.hpp"

class VehicleFactory {
public:
    static IVehicle* createVehicle(std::string type) {
        if (type == "Sedan") return new Sedan();
        if (type == "SUV") return new SUV();
        return nullptr;
    }
};
