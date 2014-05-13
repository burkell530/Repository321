/*
* Lauri Burke
* April 21, 2014
* Lab 5, dl_list.h
* Sources: Luke Sathrum, Boyd Trolenger
* Rob Bishop, Sean Michaels, Hanna
* Absolute C++ by Savitch
*/

#ifndef BURKE_DLLIST_H_
#define BURKE_DLLIST_H_

#include "dl_node.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::cerr;

// Class declaration
class DLList  {
 public:
  // Constructor, initializes head and tail to NULL, size_ to 0.
  DLList();

  // Destructor, call the clear() function
  ~DLList();

  // Member function #1. Named GetSize. Returns the size of the list.
  // It is a const function.
  int GetSize() const;

  // Member function #2. Named PushFront. Has one parameter,
  // an integer to add to the list. Creates a  DLNode with
  // the contents of the parameter and adds that node to
  // the front of the list. Does not return anything.
  void PushFront(int in_add_to_list);

  // Member function #3. Named PushBack. Has one parameter,
  // an integer to add to the list. Creates a DLNode
  // with the contents of the parameter and adds that
  // node to the front of the list. Does not return
  // anything.
  void PushBack(int in_add_to_List);

  // Member function #4. Named GetFront. Returns the
  // integer value of the node a the beginning of
  // the list. It is a const function. Outputs
  // "List Empty" to standard error output if the
  // list is empty and return 0.
  int GetFront() const;

  // Member function #5. Named GetBack.
  // Returns the integer value of the node at the
  // end of the list. It is a const function
  // Outputs "List Empty" to standard error output
  // if the list is empty and return 0.
  int GetBack() const;

  // Member function #6. Named PopFront.
  // Removes the first node in the list.
  // Outputs "List Empty" to the standard
  // error output if the list was already empty.
  void PopFront();

  // Member function #7. Named PopBack.
  // Removes the last node in the list.
  // Output "List Empty" to standard error
  // output if the list was already empty.
  void PopBack();

  // Member function #8. Named Remove First.
  // Has one parameter, and an integer to find.
  // If the value is found, remove that value
  // from the list. Will only remove the
  // first node that matches the value.
  // If the value is not found, output
  // "Not Found" to the standard error output.
  void RemoveFirst(int in_value_to_find);

  // Member function #9. Named RemoveAll. Has
  // one parameter, an integer to find. If
  // the value is found, remove that node from
  // the list. Will remove all nodes that match
  // that value. If the value is not found
  // output "Not Found" to standard error
  // output.
  void RemoveAll(int in_value_to_add);

  // Member function #10. Named Exists.
  // Has one parameter, an integer to find.
  // If the value is found, return true, else
  // return false.
  bool Exists(int value_to_find);

  // Member function #11. Named Clear.
  // Clears all nodes from the list,
  // resets size to 0 and head and
  // tail to NULL.
  void Clear();

  // Member function #12. Named ToStringForwards.
  // Outputs the contents of the list as a
  // comma-separated list: ("1, 2, 3, etc")
  // starting at the first node and ending at
  // the last node. If the list is empty,
  // return the empty string, and output
  // "List Empty" to standard error output.
  string ToStringForwards();

  // Member function #13. Named ToStringBackwards.
  // Outputs the contents of the list as
  // a comma-separated list ("1, 2, 3, etc")
  // starting at the last node and ending at the
  // first node. If the list is empty,
  // return the empty string and output
  // "List Empty" to standard error output.
  string ToStringBackwards();

 private:
  void RemoveNode(DLNode* node_to_remove);
  // The size of the list
  int m_size;

  // Pointer to the head node
  DLNode* mp_head;

  // Pointer to the tail node
  DLNode* mp_tail;
};

#endif  // BURKE_DLLIST_H_

