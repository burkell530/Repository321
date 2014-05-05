/*
 * bst_node.h
 *
 *  Created on: May 2, 2014
 *      Author: Luke
 */

#ifndef BST_NODE_H_
#define BST_NODE_H_

#include <iostream>
using std::cout;
using std::endl;

class BSTNode {
 public:
  BSTNode(int contents = 0)
      : contents_(contents),
        left_child_(NULL),
        right_child_(NULL) {
  }

  ~BSTNode() {
    left_child_ = right_child_ = NULL;
  }

  void SetContents(int contents) {
    contents_ = contents;
  }
  int GetContents() const {
    return contents_;
  }
  int& GetContents() {
    return contents_;
  }

  void SetLeftChild(BSTNode *left_child) {
    left_child_ = left_child;
  }
  void SetRightChild(BSTNode *right_child) {
    right_child_ = right_child;
  }

  BSTNode* GetLeftChild() const {
    return left_child_;
  }
  BSTNode*& GetLeftChild() {
    return left_child_;
  }

  BSTNode* GetRightChild() const {
    return right_child_;
  }
  BSTNode*& GetRightChild() {
    return right_child_;
  }

 private:
  int contents_;
  BSTNode *left_child_;
  BSTNode *right_child_;
};

#endif /* BST_NODE_H_ */
