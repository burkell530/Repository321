#include "bst_node.h"

// default constructor, sets
// left and right child to NULL
// and the contents to 0.
BSTNode::BSTNode() {
  mp_left_child = NULL;
  mp_right_child = NULL;
  m_contents = 0;
}

// overloaded constructor,
// int parameter assigned
// to the contents.
BSTNode::BSTNode(int in_contents) {
  mp_left_child = NULL;
  mp_right_child = NULL;
  m_contents = in_contents;
}

// destructor, sets left and
// right child to NULL .
BSTNode::~BSTNode() {
  mp_left_child = NULL;
  mp_right_child = NULL;
}

// Named SetContents.
// Has one integer parameter. Sets
// the internal integer parameter to
// the given parameter's value. Does
// not return anything.
void BSTNode::SetContents(int in_contents) {
  m_contents = in_contents;
}

// Named GetContents.
// Returns the value of the internal
// integer. It is a const function.
int BSTNode::GetContents() const {
  return m_contents;
}

// Named GetContents.
// Returns the value of the internal
// integer. Call by reference.
int& BSTNode::GetContents() {
  return m_contents;
}

// Named SetLeftChild.
// Has one parameter which is
// a pointer to the given parameter's
// value. Does not return anything.
void BSTNode::SetLeftChild(BSTNode* in_left_child) {
  mp_left_child = in_left_child;
}

// Named SetRightChild.
// Has one parameter which is
// a pointer to the given parameter's
// value. Does not return anything.
void BSTNode::SetRightChild(BSTNode* in_right_child) {
  mp_right_child = in_right_child;
}

// Named GetLeftChild. Returns the
// pointer to the left child node. It is
// a const function.
BSTNode* BSTNode::GetLeftChild() const {
  return mp_left_child;
}

// Named GetLeftChild. Returns the
// pointer to the left child node. It is
// call by reference.
BSTNode*& BSTNode::GetLeftChild() {
  return mp_left_child;
}

// Named GetRightChild. Returns the
// pointer to the right child node. It is
// a const function.
BSTNode* BSTNode::GetRightChild() const {
  return mp_right_child;
}

// Named GetRightChild. Returns the
// pointer to the right child node. It is
// call by reference.
BSTNode*& BSTNode::GetRightChild() {
  return mp_right_child;
}

