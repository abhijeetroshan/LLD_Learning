#include "users/Rider.hpp"
#include "users/Driver.hpp"
#include "strategy/NearestDriverStrategy.hpp"
#include "vehicle/VehicleFactory.hpp"
#include "pricing/BaseFareCalculator.hpp"
#include "pricing/SurgeFareDecorator.hpp"
#include "pricing/RideTypeFareDecorator.hpp"
#include "payment/RazorpayAdapter.hpp"
#include "notification/TwilioAdapter.hpp"
#include "facade/RideFacade.hpp"

#include <iostream>
using namespace std;

int main() {
    // ✅ Example 1: Carpool ride with surge pricing (successful)
    cout << "\n-- Rider 1 --\n";
    Rider* r1 = new Rider("R001", "Sakshi", "9876543210", "MG Road");
    Driver* d1 = new Driver("D001", "Rohan", "9876512345", "Sedan", "MG Road", "MH12AB1234", 4.8);

    RideManager* manager = RideManager::getInstance();
    manager->addDriver(d1);
    manager->registerObserver(r1);
    manager->setStrategy(new NearestDriverStrategy());

    IFareCalculator* base = new BaseFareCalculator();
    IFareCalculator* surge = new SurgeFareDecorator(base);
    IFareCalculator* final = new RideTypeFareDecorator(surge, RideType::CARPOOL);

    IPaymentProcessor* pay = new RazorpayAdapter();
    INotificationService* notify = new TwilioAdapter();

    RideFacade* app = new RideFacade(manager, final, pay, notify);
    app->bookRide(r1, "MG Road", "Sedan", RideType::CARPOOL);

    cout << "\n-- Rider 2 --\n";

    // ✅ Example 2: Private ride without surge (successful)
    Rider* r2 = new Rider("R002", "Aarav", "9123456789", "FC Road");
    Driver* d2 = new Driver("D002", "Priya", "9988776655", "SUV", "FC Road", "MH14XY5678", 4.6);

    manager->addDriver(d2);
    manager->registerObserver(r2);

    IFareCalculator* base2 = new BaseFareCalculator();
    IFareCalculator* final2 = new RideTypeFareDecorator(base2, RideType::PRIVATE);

    RideFacade* app2 = new RideFacade(manager, final2, pay, notify);
    app2->bookRide(r2, "FC Road", "SUV", RideType::PRIVATE);

    cout << "\n-- Rider 3 --\n";

    // 🚫 Example 3: Rider and Driver are at DIFFERENT LOCATIONS (should fail)

    Rider* r3 = new Rider("R003", "Neha", "9999999999", "JM Road");         // JM Road
    Driver* d3 = new Driver("D003", "Amit", "9111122222", "SUV", "SB Road", // SB Road (different)
                            "MH13ZT9999", 4.2);

    manager->addDriver(d3);
    manager->registerObserver(r3);

    IFareCalculator* base3 = new BaseFareCalculator();
    IFareCalculator* final3 = new RideTypeFareDecorator(base3, RideType::PRIVATE);

    RideFacade* app3 = new RideFacade(manager, final3, pay, notify);
    app3->bookRide(r3, "JM Road", "SUV", RideType::PRIVATE);


    return 0;
}
