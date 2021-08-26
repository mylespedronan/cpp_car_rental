#include <iostream>
#include "inc/menu.hpp"
#include "inc/cars.hpp"

Menu menu;
Cars cars;

int main() {
  int choice = menu.carMenu();
  int carChoice;

  switch(choice){
    case 0:
      break;
    case 1:
      cars.addCar();
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

      cars.updateCar(carChoice);
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

      cars.deleteCar(carChoice);
      break;
    case 4:
      cars.listAllCars();
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

      cars.checkCar(carChoice);
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

      cars.rentCar(carChoice);
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

      cars.returnCar(carChoice);
      break;    
    case 8:
      std::cout << "Exiting Program" << "\n" << std::endl;
      exit(0);
      break;
    default:
      std::cout << "Invalid Choice!" << std::endl;
      break;
  }

  main();
}
