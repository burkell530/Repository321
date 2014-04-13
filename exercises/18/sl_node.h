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

  // sets the contents_ to parameter contents
  void set_contents(int contents)

  // sets set_next_node to next_node pointer
  void set_next_node(SLNode* next_node);

  // accessor gets the contents 0f contents_
  int contents() const;
  
  // pointer that gets the next node
  SLNode* next_node() const;

 private:
  // pointer to the next node
  SLNode* next_node_;
  
  // holds data contents of this SLNode 
  int contents_;
};

#endif /* BURKE_SL_NODE_H_ */
