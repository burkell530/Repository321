/*
 * Name        : exercise_23.cpp
 * Author      : Luke Sathrum
 * Description : Creating a Node for a Binary Search Tree
 */

#include <iostream>
#include <string>
#include <sstream>
#include "bst_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();
void UpdateContents(int& contents, int new_contents);
void UpdateLink(BSTNode*& link, BSTNode* new_link);
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  cout << "Total Number of Test: 12" << endl;
  // Tests

  BSTNode node1;
  BSTNode node2(99);
  BSTNode node3(-1);

  Test(node1.GetContents() == 0, "Default Constructor / GetContents()");
  Test(node1.GetLeftChild() == NULL, "Default Constructor / GetLeftChild()");
  Test(node1.GetRightChild() == NULL, "Default Constructor / GetRightChild()");

  Test(node2.GetContents() == 99, "Constructor(99) / GetContents()");
  Test(node2.GetLeftChild() == NULL, "Constructor(99) / GetLeftChild()");
  Test(node2.GetRightChild() == NULL, "Constructor(99) / GetRightChild()");

  // node 2 is leftChild, node 3 is rightChild
  node1.SetLeftChild(&node2);
  Test(node1.GetLeftChild() == &node2, "SetLeftChild() / GetLeftChild()");
  node1.SetRightChild(&node3);
  Test(node1.GetRightChild() == &node3, "SetRightChild() / GetRightChild()");
  // swap children -- node3 leftChild, node2 rightChild
  UpdateLink(node1.GetLeftChild(), &node3);
  UpdateLink(node1.GetRightChild(), &node2);
  Test(node1.GetLeftChild() == &node3, "SetLeftChild() / GetLeftChild()");
  Test(node1.GetRightChild() == &node2, "SetRightChild() / GetRightChild()");

  node1.SetContents(42);
  Test(node1.GetContents() == 42, "SetContents(42) / GetContents()");
  UpdateContents(node1.GetContents(), 24);
  Test(node1.GetContents() == 24, "SetContents(24) / GetContents()");

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n" << "Passed: " << ut_passed << " / "
       << ut_total << endl << "Failed: " << ut_failed << " / " << ut_total
       << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test) {
    cout << "PASSSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED  TEST ";
    ut_failed++;
  }
  cout << test_number << " " << more_info << "!" << endl;
  test_number++;
  ut_total++;
}

void UpdateContents(int& contents, int new_contents) {
  contents = new_contents;
}

void UpdateLink(BSTNode*& link, BSTNode* new_link) {
  link = new_link;
}
