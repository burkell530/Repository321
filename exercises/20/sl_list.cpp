#include "sl_list.h"

// default constructor, sets values head_(NULL),
// and size_(0);
SLList::SLList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

// destructor, calls the clear function
// calls the clear function
SLList::~SLList() {
  Clear();
}

// Creates a new SLNode with the contents of the parameter and
// inserts it into the correct position in the list. The list
// will be sorted with the lowest values in the front and the
// largest values in the back.
void SLList::Insert(int new_data) {
  if (head_ == NULL || new_data <= head_->contents()) {
      InsertHead(new_data);
  } else if (new_data >= tail_->contents()) {
      InsertTail(new_data);
  } else {
    SLNode* new_node = new SLNode(new_data);
    SLNode* itr_ = head_;
    SLNode* trailer = itr_;
    while (itr_ != NULL && itr_->contents() <= new_node->contents()) {
      trailer = itr_;
      itr_ = itr_->next_node();
    }
    new_node->set_next_node(itr_);
    trailer->set_next_node(new_node);
    size_++;
  }
}

// Remove the first occurence of the supplied parameter
// found as the data in a node. Return true on successful
// removal or false if the list is empty of if the value
// is not found/removed
bool SLList::RemoveFirstOccurence(int value_to_remove) {
  if (head_ == NULL) {
  return false;
  } else {
    SLNode* itr_ = head_;
    SLNode* trailer = head_;
    while (itr_ != NULL && itr_->contents() != value_to_remove) {
      trailer = itr_;
      itr_ = itr_->next_node();
    }
    if (itr_ == NULL) {
      return false;
    } else if (itr_ == head_) {
      RemoveHead();
    } else if (itr_ == tail_) {
      RemoveTail();
    } else {
       trailer->set_next_node(itr_->next_node());
      delete itr_;
      size_--;
    }
  }
  return true;
}

// Function void InsertHead(int), create a new dynamic
// SLNode with the contents of the parameter and attach
// as head of list
void SLList::InsertHead(int in_head_to_insert) {
  // here I create a node from another class (SLNode*)
  SLNode* initial_node = new SLNode(in_head_to_insert);
    if (head_ == NULL) {
      tail_ = initial_node;
    }
    initial_node->set_next_node(head_);
    head_ = initial_node;
    size_++;
}

// Create a new dynamic SLNode with the contents of
// the integer parameter and attach as the tail of the list
void SLList::InsertTail(int in_tail) {
  if (head_ == 0) {
    InsertHead(in_tail);
  } else {
    SLNode* temp = new SLNode(in_tail);
    tail_->set_next_node(temp);
    tail_ = temp;
    size_++;
  }
}

// Function void RemoveHead(); remove the head node
// from the list, or does nothing if list is empty
void SLList::RemoveHead() {
  if (head_ != NULL) {
    SLNode* temp = head_;
    head_ = head_->next_node();
    delete temp;
    size_--;
  }
}

// Remove the tail node from the list.
// Does nothing if the list is empty
void SLList::RemoveTail() {
  if (head_ != NULL) {
    if (head_ == tail_) {
       RemoveHead();
    } else {
      SLNode *iter = head_;
      while (iter->next_node() != tail_) {
         iter = iter->next_node();
      }
      iter->set_next_node(NULL);
      delete tail_;
      tail_ = iter;
      size_--;
    }
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

// Returns the contents of the head node (The node the head is
// pointing to Return 0 if the list is empty
int SLList::GetHead() const {
  if (head_ == NULL) {
    return 0;
  } else {
  return head_->contents();
  }
}

//  Returns the contents of the tail node (The node the tail is
//  pointing to  Return 0 is the list is empty
int SLList::GetTail() const {
  if (tail_ == NULL) {
    return 0;
  } else {
    return tail_->contents();
  }
}

// Accessor, returns size
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
  for (SLNode* i = head_; i != NULL; i = i -> next_node()) {
    ss << i -> contents();
    if (i -> next_node() != NULL) {
      ss << ", ";
    }
  }
  return ss.str();
}

