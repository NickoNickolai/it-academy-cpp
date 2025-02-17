#include <iostream>
#include "passengercar.h"
#include "cargocar.h"
#include "servicestation.h"
#include "display.h"

int main()
{
    std::cout << "-> Setup cars & services" << std::endl;
    ServiceStation<PassengerCar> psngrStation;
    ServiceStation<CargoCar>     cargoStation;
    ServiceStation<Car>          univsStation;

    std::vector<std::shared_ptr<PassengerCar>> psngrCars =
    {
        std::make_shared<PassengerCar>("BMW E34"),
        std::make_shared<PassengerCar>("Mercedes W124"),
        std::make_shared<PassengerCar>("Mazda 626"),
        std::make_shared<PassengerCar>("WV Golf"),
        std::make_shared<PassengerCar>("Toyota Corolla E90"),
        std::make_shared<PassengerCar>("WV Passat B5")
    };
    for(const auto &car : psngrCars)
    {
        psngrStation.addCar(car);
    }

    std::vector<std::shared_ptr<CargoCar>> cargoCars =
    {
        std::make_shared<CargoCar>("Volvo FH16"),
        std::make_shared<CargoCar>("DAF 95"),
        std::make_shared<CargoCar>("JAC K7"),
        std::make_shared<CargoCar>("Scania G500"),
        std::make_shared<CargoCar>("Iveco EuroCargo"),
        std::make_shared<CargoCar>("MAN TGX")
    };
    for(const auto &car : cargoCars)
    {
        cargoStation.addCar(car);
    }

    univsStation.addCar(psngrCars.back());
    univsStation.addCar(cargoCars.back());

    psngrStation.displayStation();
    psngrStation.displayGarage();
    cargoStation.displayStation();
    cargoStation.displayGarage();
    univsStation.displayStation();
    univsStation.displayGarage();
    displayCarsInfo("Passenger cars", cargoCars);
    displayCarsInfo("Cargo cars", cargoCars);

    std::cout << "-> Repair cars in specific services" << std::endl;
    psngrStation.repairAll();
    cargoStation.repairAll();

    psngrStation.displayStation();
    psngrStation.displayGarage();
    cargoStation.displayStation();
    cargoStation.displayGarage();
    displayCarsInfo("Passenger cars", cargoCars);
    displayCarsInfo("Cargo cars", cargoCars);

    std::cout << "-> Repair rest broken cars on universal service" << std::endl;
    univsStation.repairAll();

    univsStation.displayStation();
    univsStation.displayGarage();
    displayCarsInfo("Passenger cars", cargoCars);
    displayCarsInfo("Cargo cars", cargoCars);

    return 0;
}
