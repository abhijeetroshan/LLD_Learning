#pragma once
#include "IVehicle.hpp"

class SUV : public IVehicle {
public:
    std::string getType() override { return "SUV"; }
    float getRatePerKm() override { return 15.0f; }
};
