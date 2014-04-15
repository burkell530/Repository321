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

class TodoUI {
 public:
  TodoUI(); 
  ~TodoUI();
  void Menu();

 private:
  void EditItem();
  void CreateItem();
  void DeleteItem();
  void ViewAllItems();
  void ViewSpecificItem();
  void DeleteAllItems();
  CinReader reader;
  TodoList* todo_list_;  
};

#endif /* BURKE_TODOITEM_H_ */