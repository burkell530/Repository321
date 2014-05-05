/*
 * bs_tree.h
 *
 *  Created on: May 2, 2014
 *      Author: Luke
 */

#ifndef BS_TREE_H_
#define BS_TREE_H_

#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include "bst_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class BSTree {
 public:
  BSTree()
      : root_(NULL),
        size_(0) {
  }

  ~BSTree() {
    Clear();
  }

  bool Insert(int to_insert) {
    return Insert(to_insert, root_);
  }

  void Clear() {
    Clear(root_);
  }

  unsigned int GetSize() const {
    return size_;
  }

  string InOrder() {
    return InOrder(root_);
  }

 private:
  BSTNode *root_;
  unsigned int size_;
  bool Insert(int to_insert, BSTNode*& root);
  void Clear(BSTNode*& root);
  string InOrder(BSTNode* root);
};

#endif /* BS_TREE_H_ */
