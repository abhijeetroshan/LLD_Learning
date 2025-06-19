#pragma once
#include "../users/Driver.hpp"
#include <vector>

class IMatchingStrategy {
public:
    virtual Driver* matchDriver(std::vector<Driver*>& drivers, const std::string& location, const std::string& type) = 0;
};
