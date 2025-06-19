#pragma once
#include <string>

class IVehicle {
public:
    virtual std::string getType() = 0;
    virtual float getRatePerKm() = 0;
    virtual ~IVehicle() = default;
};
