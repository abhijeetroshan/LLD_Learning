#pragma once
#include "../users/Rider.hpp"
#include "../users/Driver.hpp"
#include "../vehicle/IVehicle.hpp"
#include "RideStatus.hpp"
#include "RideType.hpp"

class Ride {
public:
    Rider* rider;
    Driver* driver;
    IVehicle* vehicle;
    RideStatus status;
    RideType rideType;
    float fare;

    Ride(Rider* r, Driver* d, IVehicle* v, RideType type)
        : rider(r), driver(d), vehicle(v), status(RideStatus::REQUESTED), rideType(type), fare(0.0f) {}

    void updateStatus(RideStatus newStatus) {
        status = newStatus;

        std::string message;
        switch (newStatus) {
            case RideStatus::ASSIGNED:
                message = "Driver has been assigned.";
                break;
            case RideStatus::EN_ROUTE:
                message = "Driver is en route to pickup.";
                break;
            case RideStatus::IN_PROGRESS:
                message = "Ride is in progress.";
                break;
            case RideStatus::COMPLETED:
                message = "Ride has been completed.";
                break;
            default:
                message = "Ride status updated.";
                break;
        }

        rider->update("[Status Update] " + message);
    }

    void complete() {
        status = RideStatus::COMPLETED;
        driver->available = true;
    }
};
