#pragma once
#include "IVehicle.hpp"

class Sedan : public IVehicle {
public:
    std::string getType() override { return "Sedan"; }
    float getRatePerKm() override { return 10.0f; }
};
