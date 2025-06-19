#pragma once
#include "INotificationService.hpp"
#include <iostream>

class TwilioAdapter : public INotificationService {
public:
    void send(const std::string& message) override {
        std::cout << "[Twilio] Notification: " << message << "\n";
    }
};
