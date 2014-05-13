/*
* Lauri Burke
* Exercise 24, bs_tree.h
* May 6, 2014
*/

#ifndef BURKE_BSTREE_H_
#define BURKE_BSTREE_H_

#include "bst_node.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::cerr;

class BSTree {
 public:
  // default constructor
  // sets the root to NULL
  // and size to 0.
  BSTree();

  // destructor
  // calls the Clear function.
  ~BSTree();

  // bool Insert(int),
  // calls private function
  // Insert(int, root).
  bool Insert(int data_to_insert);

  // void Clear(), call private
  // function Clear(root).
  void Clear();

  // unsigned int GetSize() const.
  unsigned int GetSize() const;

  // string InOrder ()
  // call private function InOrder(root).
  string InOrder();

 private:
  string InOrder(BSTNode* in_item_to_print);

  void Clear(BSTNode*& in_clear_this);

  bool Insert(int data_to_insert, BSTNode*& in_node);

  BSTNode* m_root;

  unsigned int m_size;
};

#endif  // BURKE_BSTREE_H_
