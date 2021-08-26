#ifndef _JSON_HANDLER_HPP_
#define _JSON_HANDLER_HPP_

#include <iostream>
#include <fstream>
#include <iomanip>
#include "json.hpp"

class CarsJSON{
  public:
    CarsJSON(){};
    
    nlohmann::json listCars();
    void updateCarsJSON(nlohmann::json carInfo);
};

#endif // _JSON_HANDLER_HPP_
