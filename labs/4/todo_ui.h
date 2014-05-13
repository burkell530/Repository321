/*
* Lauri Burke
* Lab 4, todo_ui.h
* March 28, 2014
*/

#ifndef BURKE_TODOUI_H_
#define BURKE_TODOUI_H_

#include "todo_list.h"
#include "CinReader.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Class declaration
class TodoUI {
 public:
 
  // Constructor declaration
  TodoUI();
  
  // Destructor declaration
  ~TodoUI();
  
  // Public member function
  void Menu();

 private:
  // Private member functions
  void EditItem();
  void CreateItem();
  void DeleteItem();
  void ViewAllItems();
  void ViewSpecificItem();
  void DeleteAllItems();
  
  // Instance of CinReader
  CinReader reader;
  
  // Pointer variable
  TodoList* todo_list_;
};

#endif /* BURKE_TODOITEM_H_ */
