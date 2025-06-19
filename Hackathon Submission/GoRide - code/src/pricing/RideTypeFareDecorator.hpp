#pragma once
#include "IFareCalculator.hpp"
#include "../core/RideType.hpp"

class RideTypeFareDecorator : public IFareCalculator {
    IFareCalculator* base;
    RideType type;

public:
    RideTypeFareDecorator(IFareCalculator* b, RideType t) : base(b), type(t) {}
    
    float calculateFare(float baseFare) override {
        float fare = base->calculateFare(baseFare);
        if (type == RideType::CARPOOL)
            return fare * 0.80f; // 20% off
        return fare;
    }
};
