#pragma once
#include "IFareCalculator.hpp"

class SurgeFareDecorator : public IFareCalculator {
    IFareCalculator* base;
public:
    SurgeFareDecorator(IFareCalculator* b) : base(b) {}
    float calculateFare(float baseFare) override {
        return base->calculateFare(baseFare) * 1.05f; // 5% surge
    }
};
