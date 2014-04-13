#include "sl_list.h"

// increment nodes?

// default constructor, sets values head_(NULL),
// and size_(0);
SLList::SLList() {
  head_ = NULL; 
  size_ = 0; 
}

// destructor, calls the clear function
// calls the clear function
SLList::~SLList() {
  Clear();  
}

// Function void InsertHead(int), create a new dynamic
// SLNode with the contents of the parameter and attach
// as head of list
void SLList::InsertHead (int in_head_to_insert) {
  // here I create a node from another class (SLNode*)
  SLNode* initial_node = new SLNode(in_head_to_insert);
  // pointing at nothing? Mistake?
  initial_node->set_next_node(head_); // setting next node to head.
  head_ = initial_node; // now initial node is the head. 
  size_++;
}

// Function void RemoveHead(); remove the head node
// from the list, or does nothing if list is empty
void SLList::RemoveHead() {
  if (head_ != NULL) {
    SLNode* temp = head_; // make temp point to the head
    head_ = head_->next_node();
    delete[] temp;
    size_--;
  }
}

// Function void Clear(), clears the entire contents
// of the list, freeing all memory associated with 
// all nodes
void SLList::Clear() {
  while (head_ != NULL) {
    RemoveHead();
  }
}

//Accessor, returns size
unsigned int SLList::size() const {
  return size_;
}

// Function string ToString() const, return a string
// representation of the contents of all nodes in the
// format NUM1, NUM2, ..., LASTNUM. return empty 
// string on empty list. 
string SLList::ToString() const {
  if (head_ == NULL) {
    return "";
  }
  stringstream ss;
  // go through the nodes and grab the contents
  for (SLNode* i = head; i != NULL; i = i -> next_node()) {
    ss << i -> contents();
    if (i -> next_node() != NULL) {
      ss << ", ";
      // remember to check for empty string when testing
    }
  }
  return ss.str();
}

