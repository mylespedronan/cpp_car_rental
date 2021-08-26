#include "inc/json_handler.hpp"

using json = nlohmann::json;

json CarsJSON::listCars(){
  json car;

  std::ifstream carJson("json_files/cars.json");
  
  if(!carJson.is_open()){
    throw "File unable to open! Program Exiting.";
  } else {
    carJson >> car;
    carJson.close();
  }

  return car;
}

void CarsJSON::updateCarsJSON(json carInfo){
  std::ofstream jsonOutput("json_files/cars.json");
  jsonOutput << std::setw(4) << carInfo << std::endl;
  jsonOutput.close();
}
