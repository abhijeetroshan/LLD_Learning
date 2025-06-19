#pragma once
#include <string>

class INotificationService {
public:
    virtual void send(const std::string& message) = 0;
};
