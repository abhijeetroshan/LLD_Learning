#pragma once
#include "../core/RideManager.hpp"
#include "../core/RideStatusCommand.hpp"
#include "../pricing/IFareCalculator.hpp"
#include "../payment/IPaymentProcessor.hpp"
#include "../notification/INotificationService.hpp"
#include "../vehicle/VehicleFactory.hpp"

class RideFacade {
    RideManager* manager;
    IFareCalculator* fareCalc;
    IPaymentProcessor* payment;
    INotificationService* notifier;

public:
    RideFacade(RideManager* m, IFareCalculator* f, IPaymentProcessor* p, INotificationService* n)
        : manager(m), fareCalc(f), payment(p), notifier(n) {}

    void bookRide(Rider* rider, std::string location, std::string vehicleType, RideType rideType) {
        std::cout << " Searching for nearby drivers...\n";

        Driver* driver = manager->findDriver(location, vehicleType);
        if (!driver) {
            std::cout << " No driver available.\n";
            return;
        }

        IVehicle* vehicle = VehicleFactory::createVehicle(vehicleType);
        Ride* ride = manager->createRide(rider, driver, vehicle, rideType);

        RideStatusCommand(ride, RideStatus::ASSIGNED).execute();
        RideStatusCommand(ride, RideStatus::EN_ROUTE).execute();
        RideStatusCommand(ride, RideStatus::IN_PROGRESS).execute();
        RideStatusCommand(ride, RideStatus::COMPLETED).execute();

        float baseFare = vehicle->getRatePerKm() * 10;
        float finalFare = fareCalc->calculateFare(baseFare);

        std::cout << "\n================ Overview of Ride  ================\n";
        std::cout << "- Rider Name     : " << rider->name << " (" << rider->phone << ")\n";
        std::cout << "- Pickup Location: " << location << "\n";
        std::cout << "- Ride Type      : " << (rideType == RideType::CARPOOL ? "Carpool" : "Private") << "\n\n";

        std::cout << " Driver Assigned:\n";
        std::cout << "   Name           : " << driver->name << "\n";
        std::cout << "   Plate Number   : " << driver->plateNumber << "\n";
        std::cout << "   Vehicle Type   : " << driver->vehicleType << "\n";
        std::cout << "   Rating         : " << driver->rating << " \n\n";

        std::cout << " Fare Details:\n";
        std::cout << "   Base Fare      : Rs" << baseFare << "\n";
        std::cout << "   Final Fare     : Rs" << finalFare << " (after surge + ride type discount)\n";
        std::cout << "==================================================\n\n";

        if (payment->process(finalFare)) {
            notifier->send("Ride booked successfully. Fare: Rs" + std::to_string(finalFare));
            manager->notifyAll("\nYour ride is completed.\n");
        }
    }
};
