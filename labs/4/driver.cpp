/*
* Lauri Burke
* Lab 4, driver.cpp
* March 28, 2014
* Sources: Luke Sathrum, Boyd trolinger,
* CinReader copyright by Boyed trolinger, 
* Rob Bishop, Sean Michaels, Allen Webster,
* Absolute C++ by Savitch, Cplusplus.com,
*/

#include "CinReader.h"
#include "todo_item.h"
#include "todo_list.h"
#include "todo_ui.h"
#include <iostream>

// start of program, calls a constructor
// and the Menu function. Sets up a bool
// to keep the while loop going until
// quit = true
int main() {
  TodoUI user_interface;
  user_interface.Menu();
}
