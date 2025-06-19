#pragma once
#include "ICommand.hpp"
#include "RideStatus.hpp"
#include "Ride.hpp"

class RideStatusCommand : public ICommand {
    Ride* ride;
    RideStatus status;

public:
    RideStatusCommand(Ride* r, RideStatus s) : ride(r), status(s) {}
    void execute() override {
        ride->updateStatus(status);
    }
};
