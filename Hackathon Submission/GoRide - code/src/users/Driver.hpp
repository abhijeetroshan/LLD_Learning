#pragma once
#include "User.hpp"

class Driver : public User {
public:
    std::string vehicleType, location, plateNumber;
    float rating;
    bool available;

    Driver(std::string id, std::string name, std::string phone,
           std::string vtype, std::string loc, std::string plate, float r)
        : User(id, name, phone), vehicleType(vtype), location(loc), plateNumber(plate), rating(r), available(true) {}
};
