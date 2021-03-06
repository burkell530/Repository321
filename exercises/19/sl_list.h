/*
* Lauri Burke
* SLList class
* April 7, 2014
*/

#ifndef BURKE_SL_LIST_H_
#define BURKE_SL_LIST_H_

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "sl_node.h"
using std::string;
using std::stringstream;

class SLList {
 public:
  // default constructor, sets values head_(NULL),
  // and size_(0);
  SLList();

  // destructor, calls the clear function
  // calls the clear function
  ~SLList();

  // Function void InsertHead(int), create a new dynamic
  // SLNode with the contents of the parameter and attach
  // as head of list
  void InsertHead(int in_head_to_insert);

  // Create a new dynamic SLNode with the contents of the
  // integer parameter and attach as the tail of the list
  void InsertTail(int in_tail);

  // Remove the head node
  // from the list, or does nothing if list is empty
  void RemoveHead();

  // Remove the head node from the list. Does nothing if the
  // list is empty.
  void RemoveTail();

  // Returns the contents of the tail node (the node the tail is
  // pointing to). Return 0 if the list is empty.
  int GetHead() const;

  // Returns the contents of the tail node (the node the tail is pointing
  // to). Return 0 if the list is empty.
  int GetTail() const;

  // Function void Clear(), clears the entire contents
  // of the list, freeing all memory associated with
  // all nodes
  void Clear();

  // Accessor, returns size_
  unsigned int size() const;

  // Function string ToString() const, return a string
  // representation of the contents of all nodes in the
  // format NUM1, NUM2, ..., LASTNUM. return empty
  // string on empty list.
  string ToString() const;

 private:
  // points to the first node in a singly-linked list
  SLNode* head_;

  // count of the number of nodes in the list
  unsigned int size_;

  // Points to the last node in a singly-linked list
  SLNode* tail_;
};

#endif /* BURKE_SL_LIST_H_ */
