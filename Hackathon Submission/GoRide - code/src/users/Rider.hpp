#pragma once
#include "User.hpp"
#include "IObserver.hpp"
#include <iostream>

class Rider : public User, public IObserver {
public:
    std::string location;
    Rider(std::string id, std::string name, std::string phone, std::string loc)
        : User(id, name, phone), location(loc) {}

    void update(const std::string& msg) override {
        std::cout << "[Rider Notification] " << msg << "\n";
    }
};
