#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>
#include <iomanip>

using json = nlohmann::json;

//int carID, newCost;

json listCars(){
  json car;

  std::ifstream carJson("cars.json");
  
  if(!carJson.is_open()){
    throw "File unable to open! Program Exiting.";
  } else {
    carJson >> car;
    carJson.close();
  }

  return car;
}

void addCar(){
  json carID, newCar;
  std::string carModel;
  int numCar, carYear, carCost;
  bool carCon;

  try {
    carID = listCars();
    numCar = carID.size();
  } catch(const char* msg) {
    std::cerr << msg << "\n" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "Enter a model [toyota, honda, subaru]: ";
  std::cin >> carModel;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    addCar();

    return;
  } else if (carModel != "toyota" && carModel != "honda" && carModel != "subaru"){
    std::cout << "Invalid option. Please try again.\n" << std::endl;
    addCar();

    return;
  }

  std::cout << "Enter the car year: ";
  std::cin >> carYear;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    addCar();

    return;
  } else if (carYear < 1800 || carYear > 2025){
    std::cout << "Invalid year option. Please try again.\n" << std::endl;
    addCar();

    return;
  }

  std::cout << "Is the car new [true] or used [false]: ";
  std::cin >> std::boolalpha >> carCon;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    addCar();

    return;    
  } 

  std::cout << "Enter the car cost: ";
  std::cin >> carCost;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    addCar();

    return;
  } else if (carCost < 0){
    std::cout << "Invalid Cost. Please try again.\n" << std::endl;
    addCar();

    return;
  }  

  newCar["carID"] = numCar;
  newCar["model"] = carModel;
  newCar["year"] = carYear;
  newCar["con"] = carCon;
  newCar["cost"] = carCost;
  newCar["avail"] = true;

  carID += newCar;

  std::ofstream jsonOutput("cars.json");
  jsonOutput << std::setw(4) << carID << std::endl;
  jsonOutput.close();

  std::cout << "Car successfully added." << "\n" << std::endl;
}

int menu(){
  int ch; 

  std::cout << "------------\t Welcome to the Car Rental Program! \t------------" << "\n" << std::endl;
  std::cout << "Please select an option: " << std::endl;
  std::cout << "1. Add a Car" << std::endl;
  std::cout << "2. Update Car Details" << std::endl;
  std::cout << "3. Remove Car" << std::endl;
  std::cout << "4. List All Cars" << std::endl;
  std::cout << "5. Check a Car" << std::endl;
  std::cout << "6. Rent a Car" << std::endl;
  std::cout << "7. Modify Rent Records" << std::endl;
  std::cout << "8. Exit Program" << "\n" << std::endl;
  std::cout << "Your Choice: ";
  std::cin >> ch;
  std::cout << std::endl;

  if(std::cin.fail()){
    std::cout << "ERROR: Choice selected is not a number. Please try again." << "\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    ch = 0;
  }

  return ch;
}

void updateCar(int carID){
  json cars;
  int numOfCars;
  std::string carModel;
  int carYear, carCost;
  bool carCon, avail, isFound;

  isFound = false;
  cars = listCars();
  numOfCars = cars.size();

  for(int i = 0; i < numOfCars; i++){
    if(cars[i]["carID"] == carID){
      std::cout << "Enter a model [toyota, honda, subaru]: ";
      std::cin >> carModel;

      if(std::cin.fail()){
        std::cout << "Invalid option.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        updateCar(carID);

        return;
      } else if (carModel != "toyota" && carModel != "honda" && carModel != "subaru"){
        std::cout << "Invalid option. Please try again.\n" << std::endl;
        updateCar(carID);

        return;
      }

      std::cout << "Enter the car year: ";
      std::cin >> carYear;

      if(std::cin.fail()){
        std::cout << "Invalid option.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        updateCar(carID);

        return;
      } else if (carYear < 1800 || carYear > 2025){
        std::cout << "Invalid year option. Please try again.\n" << std::endl;
        updateCar(carID);

        return;
      }

      std::cout << "Is the car new [true] or used [false]: ";
      std::cin >> std::boolalpha >> carCon;

      if(std::cin.fail()){
        std::cout << "Invalid option.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        updateCar(carID);

        return;    
      } 

      std::cout << "Enter the car cost: ";
      std::cin >> carCost;

      if(std::cin.fail()){
        std::cout << "Invalid option.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        updateCar(carID);

        return;
      } else if (carCost < 0){
        std::cout << "Invalid Cost. Please try again.\n" << std::endl;
        updateCar(carID);

        return;
      }

      std::cout << "Is the car available [true] or taken [false]: ";
      std::cin >> std::boolalpha >> avail;

      if(std::cin.fail()){
        std::cout << "Invalid option.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        updateCar(carID);

        return;    
      } 

      // cars[i]["carID"] = numCar;
      cars[i]["model"] = carModel;
      cars[i]["year"] = carYear;
      cars[i]["con"] = carCon;
      cars[i]["cost"] = carCost;
      cars[i]["avail"] = avail;

      std::ofstream jsonOutput("cars.json");
      jsonOutput << std::setw(4) << carID << std::endl;
      jsonOutput.close();

      isFound = true;
    }
  }

  if(!isFound){
    std::cout << "ERROR: Car ID not found.\n" << std::endl;

    return;
  } else {
    std::ofstream jsonOutput("cars.json");
    jsonOutput << std::setw(4) << cars << std::endl;
    jsonOutput.close();

    std::cout << "Car successfully updated." << "\n" << std::endl;
  }
}

// bool deleteCar(int carID){}
// void checkCar(int carID){}
// bool rentCar(int carID){}
// bool modCost(int carID, int newCost){}

int main() {
  int choice = menu();
  int carChoice;

  switch(choice){
    case 0:
      break;
    case 1:
      addCar();
      break;
    case 2:
      std::cout << "What is the car ID you want to update: ";
      std::cin >> carChoice;

      if(std::cin.fail()){
        std::cout << "Invalid car ID. \n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        break;
      } else if (carChoice < 0){
        std::cout << "Cannot accept input. \n" << std::endl;
        break;
      }

      updateCar(carChoice);
      break;
    case 8:
      std::cout << "Exiting Program" << std::endl;
      exit(0);
      break;
    default:
      std::cout << "Invalid Choice!" << std::endl;
      break;
  }

  main();
}