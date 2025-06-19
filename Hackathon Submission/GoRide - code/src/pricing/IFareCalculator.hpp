#pragma once

class IFareCalculator {
public:
    virtual float calculateFare(float baseFare) = 0;
    virtual ~IFareCalculator() = default;
};
