#pragma once
#include "IFareCalculator.hpp"

class BaseFareCalculator : public IFareCalculator {
public:
    float calculateFare(float baseFare) override {
        return baseFare;
    }
};
