#ifndef _CARS_HPP_
#define _CARS_HPP_

#include <iostream>
#include <limits.h>
#include <string>
#include "json.hpp"
#include "json_handler.hpp"
#include "menu.hpp"

class Cars{
  private:
    CarsJSON carsjson;
    Menu menu;
    
    nlohmann::json carID, cars;
    std::string carModel;
    int numCar, carYear, carCost, numOfCars;
    bool carCon, avail, isFound;
  public:
    Cars(){};

    void addCar();
    void updateCarModel(nlohmann::json cars, int i);
    void updateCarYear(nlohmann::json cars, int i);
    void updateCarCondition(nlohmann::json cars, int i);
    void updateCarCost(nlohmann::json cars, int i);
    void updateCarAvail(nlohmann::json cars, int i);
    void updateCar(int carID);
    void deleteCar(int carID);
    void listAllCars();
    void checkCar(int carID);
    void rentCar(int carID);
    void returnCar(int carID);
};

#endif // _CARS_HPP_
