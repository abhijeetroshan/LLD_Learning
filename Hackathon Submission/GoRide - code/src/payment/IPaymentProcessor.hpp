#pragma once

class IPaymentProcessor {
public:
    virtual bool process(float amount) = 0;
    virtual ~IPaymentProcessor() = default;
};
