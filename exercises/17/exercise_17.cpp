/*
 * Name        : exercise_17.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class SLNode.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include "sl_node.h"

#include <iostream>
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();

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
  // Tests
  SLNode node1;
  SLNode node2(1);

  Test(node1.contents() == 0, "Default Constructor & contents()");
  Test(node1.next_node() == NULL, "Default Constructor & next_node()");
  Test(node2.contents() == 1, "Overloaded Constructor & contents()");
  Test(node2.next_node() == NULL, "Overloaded Constructor & next_node()");

  SLNode* pNode = &node2;
  node1.set_next_node(&node2);
  Test(node1.next_node() == pNode, "set_next_node() & next_node()");

  pNode = &node1;
  // node1 and node2 now connect each to the other -- not something you should
  // ever do outside of a testing situation
  node2.set_next_node(pNode);
  Test(node2.next_node() == pNode, "set_next_node() & next_node()");

  node1.set_next_node(NULL);
  Test(node1.next_node() == NULL, "set_next_node(NULL) & next_node()");

  node2.set_next_node(NULL);
  Test(node2.next_node() == NULL, "set_next_node(NULL) & next_node()");

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n\n";
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << test_number << " " << more_info << "!\n";
  test_number++;
}
