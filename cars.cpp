#include "inc/cars.hpp"

using json = nlohmann::json;

void Cars::addCar(){
  json newCar;

  try {
    carID = carsjson.listCars();
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

  carsjson.updateCarsJSON(carID);

  std::cout << "Car successfully added." << "\n" << std::endl;
}

void Cars::updateCarModel(json cars, int i){
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
  carsjson.updateCarsJSON(cars);

  std::cout << "Car model successfully updated.\n" << std::endl;
}

void Cars::updateCarYear(json cars, int i){
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
  carsjson.updateCarsJSON(cars);

  std::cout << "Car year successfully updated.\n" << std::endl;
}

void Cars::updateCarCondition(json cars, int i){
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
  carsjson.updateCarsJSON(cars);

  std::cout << "Car condition successfully updated.\n" << std::endl;
}

void Cars::updateCarCost(json cars, int i){
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
  carsjson.updateCarsJSON(cars);

  std::cout << "Car cost successfully updated.\n" << std::endl;
}

void Cars::updateCarAvail(json cars, int i){
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
  carsjson.updateCarsJSON(cars);

  std::cout << "Car availability successfully updated.\n" << std::endl;
}

void Cars::updateCar(int carID){
  int updateChoice;

  isFound = false;
  cars = carsjson.listCars();
  numOfCars = cars.size();

  if(carID < (numOfCars)){
    for(int i = 0; i < numOfCars; i++){
      if(cars[i]["carID"] == carID){
        updateChoice = menu.updateMenu();

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

void Cars::deleteCar(int carID){
  int tempID;

  isFound = false;
  cars = carsjson.listCars();
  numOfCars = cars.size();

  if(carID > (numOfCars - 1)){
    std::cout << "ERROR: Car ID is not listed. Please try again.\n" << std::endl;
    std::cout << "What is the car ID you want to delete: ";
    std::cin >> carID;
    std::cout << "\n";
    
    if(std::cin.fail()){
      std::cout << "Invalid car ID. \n" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      return;
    } else if (carID < 0){
      std::cout << "Cannot accept input. \n" << std::endl;
      return;
    }

    deleteCar(carID);
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

  carsjson.updateCarsJSON(cars);

  std::cout << "Car Deleted.\n" << std::endl;
}

void Cars::listAllCars(){
  cars = carsjson.listCars();
  numOfCars = cars.size();
  
  std::cout << "------------\tAll Car Info\t------------\n" << std::endl;

  for(int i = 0; i < numOfCars; i++){
    std::cout << "Car ID : " << cars[i]["carID"] << std::endl;
    std::cout << "\t- Car Model : " << cars[i]["model"] << std::endl;
    std::cout << "\t- Car Year : " << cars[i]["year"] << std::endl;
    std::cout << "\t- Car Cost : $" << cars[i]["cost"] << std::endl;
    std::cout << "\t- Car Condition : " << cars[i]["con"] << std::endl;
    std::cout << "\t- Available : " << cars[i]["avail"] << std::endl;    
    
    std::cout << std::endl;
  } 
}

void Cars::checkCar(int carID){
  cars = carsjson.listCars();
  numOfCars = cars.size();

  std::cout << "------------\tCar Info\t------------\n" << std::endl;

  if(carID > (numOfCars - 1)){
    std::cout << "ERROR: Car ID is not listed. Please try again.\n" << std::endl;
    std::cout << "What is the car ID you want to check: ";
    std::cin >> carID;
    std::cout << "\n";
    
    if(std::cin.fail()){
      std::cout << "Invalid car ID. \n" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      return;
    } else if (carID < 0){
      std::cout << "Cannot accept input. \n" << std::endl;
      return;
    }

    checkCar(carID);
    return;
  }

  for(int i = 0; i < numOfCars; i++){
    if(cars[i]["carID"] == carID){
      std::cout << "Car ID : " << cars[i]["carID"] << std::endl;
      std::cout << "\t- Car Model : " << cars[i]["model"] << std::endl;
      std::cout << "\t- Car Year : " << cars[i]["year"] << std::endl;
      std::cout << "\t- Car Cost : $" << cars[i]["cost"] << std::endl;
      std::cout << "\t- Car Condition : " << cars[i]["con"] << std::endl;
      std::cout << "\t- Available : " << cars[i]["avail"] << std::endl;    
    }
  }

  std::cout << std::endl;
}

void Cars::rentCar(int carID){
  cars = carsjson.listCars();
  numOfCars = cars.size();

  if(carID > (numOfCars - 1)){
    std::cout << "ERROR: Car ID is not listed. Please try again.\n" << std::endl;
    std::cout << "What is the car ID you want to rent: ";
    std::cin >> carID;
    std::cout << "\n";
    
    if(std::cin.fail()){
      std::cout << "Invalid car ID. \n" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      return;
    } else if (carID < 0){
      std::cout << "Cannot accept input. \n" << std::endl;
      return;
    }

    rentCar(carID);
    return;
  }

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

  carsjson.updateCarsJSON(cars);

  std::cout << "Car rented.\n" << std::endl;
}

void Cars::returnCar(int carID){
  cars = carsjson.listCars();
  numOfCars = cars.size();

  if(carID > (numOfCars - 1)){
    std::cout << "ERROR: Car ID is not listed. Please try again.\n" << std::endl;
    std::cout << "What is the car ID you want to return: ";
    std::cin >> carID;
    std::cout << "\n";
    
    if(std::cin.fail()){
      std::cout << "Invalid car ID. \n" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      return;
    } else if (carID < 0){
      std::cout << "Cannot accept input. \n" << std::endl;
      return;
    }

    returnCar(carID);
    return;
  }

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

  carsjson.updateCarsJSON(cars);

  std::cout << "Car returned.\n" << std::endl;
}