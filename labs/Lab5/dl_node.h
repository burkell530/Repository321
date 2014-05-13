/*
* Lauri Burke
* April 21, 2014
* Lab 5 dl_node.h
*/

#ifndef BURKE_DLNODE_H_
#define BURKE_DLNODE_H_

#include <iostream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class DLNode {
 public:
  // Constructor #1. Constructs a
  // new node object . Has no parameters.
  // Sets the previous pointer to NULL.
  // Sets the next pointer to NULL.
  // Sets the member integer to 0;
  DLNode();

  // Destructor is empty. Takes
  // no parameters. Destroys node
  // objects.
  ~DLNode();

  // Mutator #1. Named SetContents.
  // Has one integer parameter. Sets
  // the internal integer parameter to
  // the given parameter's value. Does
  // not return anything.
  void SetContents(int in_contents);

  // Mutator #2. Named SetNext. Has one
  // parameter which is a pointer to a DLNode
  // Sets the internal pointer to the
  // given parameter's value. Does not
  // return anything.
  void SetNext(DLNode* in_next);

  // Mutator #3. Named SetPrevious.
  // Has one parameter which is
  // a pointer to the given parameter's
  // value.
  //  Does not return anything.
  void SetPrevious(DLNode* in_previous);

  // Accessor #1. Named GetContents.
  // Returns the value of the internal
  // integer. It is a const function.
  int GetContents() const;

  // Accessor #2. Named GetNext. Returns the
  // pointer to the next node. It is a const
  // function.
  DLNode* GetNext() const;

  // Accessor #3. Named GetPrevious. Returns the
  // pointer to the previous node. It is
  // a const function.
  DLNode* GetPrevious() const;

 private:
  // An integer for the contents of the node
  int m_contents;

  // A pointer to the previous node
  DLNode* mp_previous;

  // A pointer to the next node
  DLNode* mp_next;
};

#endif  // BURKE_DLNODE_H_

