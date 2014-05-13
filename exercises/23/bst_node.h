/*
* Lauri Burke
* Exercise 23, bst_node.h
* May 5, 2014
*/

#ifndef BURKE_BSTNODE_H_
#define BURKE_BSTNODE_H_

#include <iostream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BSTNode {
 public:
  // default constructor, sets
  // left and right child to NULL
  // and the contents to 0.
  BSTNode();

  // overloaded constructor,
  // int parameter assigned
  // to the contents.
  BSTNode(int in_contents);

  // destructor, sets left and
  // right child to NULL .
  ~BSTNode();

  // Named SetContents.
  // Has one integer parameter. Sets
  // the internal integer parameter to
  // the given parameter's value. Does
  // not return anything.
  void SetContents(int in_contents);

  // Named GetContents.
  // Returns the value of the internal
  // integer. It is a const function.
  int GetContents() const;

  // Named GetContents.
  // Returns the value of the internal
  // integer. Call by reference.
  int& GetContents();

  // Named SetLeftChild.
  // Has one parameter which is
  // a pointer to the given parameter's
  // value. Does not return anything.
  void SetLeftChild(BSTNode* in_left_child);

  // Named SetRightChild.
  // Has one parameter which is
  // a pointer to the given parameter's
  // value. Does not return anything.
  void SetRightChild(BSTNode* in_right_child);

  // Named GetLeftChild. Returns the
  // pointer to the left child node. It is
  // a const function.
  BSTNode* GetLeftChild() const;

  // Named GetLeftChild. Returns the
  // pointer to the left child node. It is
  // call by reference.
  BSTNode*& GetLeftChild();

  // Named GetRightChild. Returns the
  // pointer to the right child node. It is
  // a const function.
  BSTNode* GetRightChild() const;

  // Named GetRightChild. Returns the
  // pointer to the right child node. It is
  // call by reference.
  BSTNode*& GetRightChild();

 private:
  // BSTNode* to point to a left child.
  BSTNode* mp_left_child;

  // BSTNode* to point to a right child.
  BSTNode* mp_right_child;

  // int used to store the data contents
  // of this BSTNode.
  int m_contents;
};

#endif  // BURKE_DLNODE_H_
