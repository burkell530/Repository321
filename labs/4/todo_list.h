/*
* Lauri Burke
* todo_list.h
* March 28, 2014
*/

#ifndef BURKE_TODOLIST_H_
#define BURKE_TODOLIST_H_

#include "todo_item.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class TodoList;
ostream& operator << (ostream &out, const TodoList &item_to_write);

class TodoList {
 public:
  // Constructor declaration
  TodoList();

  // Destructor declaration
  ~TodoList();

  // Public member functions
  void AddItem(TodoItem* in_item_to_add);
  void DeleteItem(unsigned int in_location_to_delete);
  TodoItem* GetItem(unsigned int in_location_to_retrive_item_from);
  unsigned int GetSize();
  unsigned int GetCapacity();
  void Sort();
  string ToFile();

  // Friend functions
  friend ostream& operator << (ostream &out, const TodoList &item_to_write);

 private:
  // Private member functions
  void FreeList();
  void Initialize(unsigned int in__current_number_of_slots_in_list);
  void IncreaseCapacity();
  void ShiftElements(unsigned int empty_space_to_fill);

  // Pointer to an array
  TodoItem** the_array;

  // Member variables
  unsigned int m_current_number_of_slots_in_list;
  unsigned int m_current_size_of_list;
};

#endif /* BURKE_TODOLIST_H_ */
