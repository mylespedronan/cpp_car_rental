#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>
#include <iomanip>
#include <limits.h>

using json = nlohmann::json;

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

void updateCarsJSON(json carInfo){
  std::ofstream jsonOutput("cars.json");
  jsonOutput << std::setw(4) << carInfo << std::endl;
  jsonOutput.close();
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
  } else if (carCost < 0 || carCost > INT_MAX){
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
  std::cout << "7. Return a Car" << std::endl;
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

int updateMenu(){
  int updateChoice;

  std::cout << "------------\tUpdate Menu\t------------" << std::endl;
  std::cout << "What would you like to update: " << std::endl;
  std::cout << "1. Update Car Model" << std::endl;
  std::cout << "2. Update Car Year" << std::endl;
  std::cout << "3. Update Car Condition" << std::endl;
  std::cout << "4. Update Car Cost" << std::endl;
  std::cout << "5. Update Car Availability" << std::endl;
  std::cout << "6. Change Car to Update" << std::endl;
  std::cout << "7. Return to Previous Menu" << std::endl;
  std::cout << "\n" << "Your choice: ";
  std::cin >> updateChoice;
  std::cout << "\n";

  if(std::cin.fail()){
    std::cout << "Invalid option. Please try again." << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    updateMenu();
    updateChoice = 0;
  } 

  return updateChoice;
}

void updateCarModel(json cars, int i){
  std::string carModel;

  std::cout << "Enter a model [toyota, honda, subaru]: ";
  std::cin >> carModel;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    updateCarModel(cars, i);

    return;
  } else if (carModel != "toyota" && carModel != "honda" && carModel != "subaru"){
    std::cout << "Invalid option. Please try again.\n" << std::endl;
    updateCarModel(cars, i);

    return;
  } 

  cars[i]["model"] = carModel;  
  updateCarsJSON(cars);

  std::cout << "Car model successfully updated.\n" << std::endl;
}

void updateCarYear(json cars, int i){
  int carYear;

  std::cout << "Enter the car year: ";
  std::cin >> carYear;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    updateCarYear(cars, i);

    return;
  } else if (carYear < 1800 || carYear > 2025){
    std::cout << "Invalid year option. Please try again.\n" << std::endl;
    updateCarYear(cars, i);

    return;
  }

  cars[i]["year"] = carYear;
  updateCarsJSON(cars);

  std::cout << "Car year successfully updated.\n" << std::endl;
}

void updateCarCondition(json cars, int i){
  bool carCon;

  std::cout << "Is the car new [true] or used [false]: ";
  std::cin >> std::boolalpha >> carCon;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    updateCarCondition(cars, i);

    return;    
  } 

  cars[i]["con"] = carCon;
  updateCarsJSON(cars);

  std::cout << "Car condition successfully updated.\n" << std::endl;
}

void updateCarCost(json cars, int i){
  int carCost;

  std::cout << "Enter the car cost: ";
  std::cin >> carCost;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    updateCarCost(cars, i);

    return;
  } else if (carCost < 0 || carCost > INT_MAX){
    std::cout << "Invalid Cost. Please try again.\n" << std::endl;
    updateCarCost(cars, i);

    return;
  }

  cars[i]["cost"] = carCost;
  updateCarsJSON(cars);

  std::cout << "Car cost successfully updated.\n" << std::endl;
}

void updateCarAvail(json cars, int i){
  bool avail;

  std::cout << "Is the car available [true] or taken [false]: ";
  std::cin >> std::boolalpha >> avail;

  if(std::cin.fail()){
    std::cout << "Invalid option.\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    updateCarAvail(cars, i);

    return;    
  } 

  cars[i]["avail"] = avail;
  updateCarsJSON(cars);

  std::cout << "Car availability successfully updated.\n" << std::endl;
}

void updateCar(int carID){
  json cars;
  int numOfCars, updateChoice;
  bool isFound;

  isFound = false;
  cars = listCars();
  numOfCars = cars.size();

  if(carID < (numOfCars)){
    for(int i = 0; i < numOfCars; i++){
      if(cars[i]["carID"] == carID){
        updateChoice = updateMenu();

        switch(updateChoice){
          case 1:
            updateCarModel(cars, i);

            break;
          case 2:
            updateCarYear(cars, i);

            break;
          case 3:
            updateCarCondition(cars, i);

            break;
          case 4:
            updateCarCost(cars, i);

            break;
          case 5:
            updateCarAvail(cars, i);

            break;
          case 6:
            int tempID;

            std::cout << "Enter a new Car ID: ";
            std::cin >> tempID;
            std::cout << std::endl;

            if(std::cin.fail()){
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              std::cin.clear();
              std::cin.ignore(10000, '\n');
            } else {
              carID = tempID;
            }
            
            break;
          case 7:
            return;

            break;
          default:
            std::cout << "Input is out of range. Please try again." << std::endl;

            break;
        }
        
        isFound = true;
      }
    }
  }

  if(!isFound){
    std::cout << "ERROR: Car ID not found.\n" << std::endl;

    return;
  }

  updateCar(carID);
}

void deleteCar(int carID){
  json cars, newCars;
  int numOfCars, tempID, newCarID;
  bool isFound;

  isFound = false;
  cars = listCars();
  numOfCars = cars.size();

  if(carID > (numOfCars - 1)){
    std::cout << "ERROR: Car ID is not listed. Please try again.\n" << std::endl;
    std::cout << "What is the car ID you want to delete: ";
    std::cin >> newCarID;
    std::cout << "\n";
    
    if(std::cin.fail()){
      std::cout << "Invalid car ID. \n" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      return;
    } else if (newCarID < 0){
      std::cout << "Cannot accept input. \n" << std::endl;
      return;
    }

    deleteCar(newCarID);
    return;
  }

  for(int i = 0; i < numOfCars; i++){
    if(isFound){
      cars[i]["carID"] = tempID;
      tempID++;
    }
    if((cars[i]["carID"] == carID) && !isFound){
      isFound = true;
      tempID = carID;
    }
  }

  cars.erase(cars.begin() + carID);

  updateCarsJSON(cars);

  std::cout << "Car Deleted.\n" << std::endl;
}

void listAllCars(){
  json cars;
  int numOfCars;

  cars = listCars();
  numOfCars = cars.size();
  
  std::cout << "------------\tAll Car Info\t------------\n" << std::endl;

  for(int i = 0; i < numOfCars; i++){
    std::cout << "Available : " << cars[i]["avail"] << std::endl;
    std::cout << "Car ID : " << cars[i]["carID"] << std::endl;
    std::cout << "Car Condition : " << cars[i]["con"] << std::endl;
    std::cout << "Car Cost : " << cars[i]["cost"] << std::endl;
    std::cout << "Car Model : " << cars[i]["model"] << std::endl;
    std::cout << "Car Year : " << cars[i]["year"] << std::endl;
    std::cout << std::endl;
  } 
}

void checkCar(int carID){
  json cars;
  int numOfCars;

  cars = listCars();
  numOfCars = cars.size();

  std::cout << "------------\tCar Info\t------------\n" << std::endl;

  if(carID < (numOfCars)){
    for(int i = 0; i < numOfCars; i++){
      if(cars[i]["carID"] == carID){
        std::cout << "Available : " << cars[i]["avail"] << std::endl;
        std::cout << "Car ID : " << cars[i]["carID"] << std::endl;
        std::cout << "Car Condition : " << cars[i]["con"] << std::endl;
        std::cout << "Car Cost : " << cars[i]["cost"] << std::endl;
        std::cout << "Car Model : " << cars[i]["model"] << std::endl;
        std::cout << "Car Year : " << cars[i]["year"] << std::endl;
      }
    }
  }

  std::cout << std::endl;
}

void rentCar(int carID){
  json cars;
  int numOfCars;

  cars = listCars();
  numOfCars = cars.size();

  for(int i = 0; i < numOfCars; i++){
    if(cars[i]["carID"] == carID){
      if(cars[i]["avail"]){
        cars[i]["avail"] = false;
      } else {
        std::cout << "ERROR: Car is already taken!\n" << std::endl;
        return;
      }
    }
  }

  updateCarsJSON(cars);

  std::cout << "Car rented.\n" << std::endl;
}

void returnCar(int carID){
  json cars;
  int numOfCars;

  cars = listCars();
  numOfCars = cars.size();

  for(int i = 0; i < numOfCars; i++){
    if(cars[i]["carID"] == carID){
      if(!cars[i]["avail"]){
        cars[i]["avail"] = true;
      } else {
        std::cout << "ERROR: Car is already returned!\n" << std::endl;
        return;
      }
    }
  }

  updateCarsJSON(cars);

  std::cout << "Car returned.\n" << std::endl;
}

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
      std::cout << "\n";

      if(std::cin.fail()){
        std::cout << "Invalid car ID. \n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        break;
      } else if (carChoice < 0 || carChoice > INT_MAX){
        std::cout << "Cannot accept input. \n" << std::endl;
        break;
      }

      updateCar(carChoice);
      break;
    case 3:
      std::cout << "What is the car ID you want to delete: ";
      std::cin >> carChoice;
      std::cout << "\n";
      
      if(std::cin.fail()){
        std::cout << "Invalid car ID. \n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        break;
      } else if (carChoice < 0 || carChoice > INT_MAX){
        std::cout << "Cannot accept input. \n" << std::endl;
        break;
      }

      deleteCar(carChoice);
      break;
    case 4:
      listAllCars();
      break;
    case 5:
      std::cout << "What is the car ID you want to check: ";
      std::cin >> carChoice;
      std::cout << "\n";

      if(std::cin.fail()){
        std::cout << "Invalid car ID. \n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        break;
      } else if (carChoice < 0 || carChoice > INT_MAX){
        std::cout << "Cannot accept input. \n" << std::endl;
        break;
      }

      checkCar(carChoice);
      break;
    case 6:
      std::cout << "What car ID do you want to rent: ";
      std::cin >> carChoice;
      std::cout << "\n";

      if(std::cin.fail()){
        std::cout << "Invalid car ID. \n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        break;
      } else if (carChoice < 0 || carChoice > INT_MAX){
        std::cout << "Cannot accept input. \n" << std::endl;
        break;
      }

      rentCar(carChoice);
      break;
    case 7:
      std::cout << "What car ID do you want to return: ";
      std::cin >> carChoice;
      std::cout << "\n";

      if(std::cin.fail()){
        std::cout << "Invalid car ID. \n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        break;
      } else if (carChoice < 0 || carChoice > INT_MAX){
        std::cout << "Cannot accept input. \n" << std::endl;
        break;
      }

      returnCar(carChoice);
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
