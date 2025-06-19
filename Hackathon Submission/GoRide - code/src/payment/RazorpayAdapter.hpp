#pragma once
#include "IPaymentProcessor.hpp"
#include <iostream>

class RazorpayAdapter : public IPaymentProcessor {
public:
    bool process(float amount) override {
        std::cout << "\n[Razorpay] Processed payment of Rs" << amount << "\n\n";
        return true;
    }
};
