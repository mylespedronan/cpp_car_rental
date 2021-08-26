#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>

class Menu{
  private:
    int choice;
  public:
    Menu(){
      choice = 0;
    };
    
    int carMenu();
    int updateMenu();
};

#endif // _MENU_HPP_
