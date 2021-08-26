#include "inc/menu.hpp"

int Menu::carMenu(){
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
  std::cin >> choice;
  std::cout << std::endl;

  if(std::cin.fail()){
    std::cout << "ERROR: Choice selected is not a number. Please try again." << "\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    choice = 0;
  }

  return choice;
}

int Menu::updateMenu(){
  std::cout << "------------\tUpdate Menu\t------------" << "\n" << std::endl;
  std::cout << "What would you like to update: " << std::endl;
  std::cout << "1. Update Car Model" << std::endl;
  std::cout << "2. Update Car Year" << std::endl;
  std::cout << "3. Update Car Condition" << std::endl;
  std::cout << "4. Update Car Cost" << std::endl;
  std::cout << "5. Update Car Availability" << std::endl;
  std::cout << "6. Change Car to Update" << std::endl;
  std::cout << "7. Return to Previous Menu" << std::endl;
  std::cout << "\n" << "Your choice: ";
  std::cin >> choice;
  std::cout << "\n";

  if(std::cin.fail()){
    std::cout << "Invalid option. Please try again." << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    updateMenu();
    choice = 0;
  } 

  return choice;
}