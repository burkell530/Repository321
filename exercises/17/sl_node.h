/*
* Lauri Burke
* SLNode class
* April 7, 2014
*/

#ifndef BURKE_SL_NODE_H_
#define BURKE_SL_NODE_H_

#include <cstdlib>
#include <string>
#include <iostream>

// declaration of class SLNode
class SLNode {
 public:
  // default constructor, sets value next_node_(NULL)
  // and contents_ to 0;
  SLNode();

  // overloaded constructor, parameter is contents_
  SLNode(int contents);

  // empty destructor
  ~SLNode();

  // mutators
  void set_contents(int contents);
  void set_next_node(SLNode* next_node);

  // accessors
  int contents() const;
  SLNode* next_node() const;

 private:
  SLNode* next_node_;
  int contents_;
};

#endif /* BURKE_SL_NODE_H_ */
