#pragma once
#include "../users/Driver.hpp"
#include "../users/IObserver.hpp"
#include "../core/RideHistory.hpp"
#include "../strategy/IMatchingStrategy.hpp"
#include <vector>
#include <string>

class RideManager {
private:
    static RideManager* instance;
    std::vector<Driver*> drivers;
    std::vector<IObserver*> observers;
    IMatchingStrategy* strategy;
    RideHistory history;

    RideManager() = default;

public:
    static RideManager* getInstance() {
        if (!instance) instance = new RideManager();
        return instance;
    }

    void addDriver(Driver* driver) {
        drivers.push_back(driver);
    }

    void registerObserver(IObserver* obs) {
        observers.push_back(obs);
    }

    void notifyAll(const std::string& msg) {
        for (IObserver* obs : observers)
            obs->update(msg);
    }

    Driver* findDriver(const std::string& location, const std::string& type) {
        return strategy->matchDriver(drivers, location, type);
    }

    void setStrategy(IMatchingStrategy* s) {
        strategy = s;
    }

    Ride* createRide(Rider* rider, Driver* driver, IVehicle* vehicle, RideType type) {
        driver->available = false;
        Ride* ride = new Ride(rider, driver, vehicle, type);
        history.addRide(ride);
        return ride;
    }
};

RideManager* RideManager::instance = nullptr;
