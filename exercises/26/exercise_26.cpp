/*
 * Name        : exercise_26.cpp
 * Author      : Luke Sathrum
 * Description : Creating a Templated Node for a Binary Search Tree
 */

#include <iostream>
#include <string>
#include <sstream>
#include "bst_nodet.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();
template<typename T>
void UpdateContents(T& contents, T new_contents);
template<typename T>
void UpdateLink(BSTNode<T>*& link, BSTNode<T>* new_link);
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
  cout << "Total Number of Test: 36" << endl;
  // Tests
  cout << "******<int>******" << endl;
  BSTNode<int> inode1;
  BSTNode<int> inode2(99);
  BSTNode<int> inode3(-1);

  Test(inode1.GetContents() == 0, "Default Constructor / GetContents()");
  Test(inode1.GetLeftChild() == NULL, "Default Constructor / GetLeftChild()");
  Test(inode1.GetRightChild() == NULL, "Default Constructor / GetRightChild()");

  Test(inode2.GetContents() == 99, "Constructor(99) / GetContents()");
  Test(inode2.GetLeftChild() == NULL, "Constructor(99) / GetLeftChild()");
  Test(inode2.GetRightChild() == NULL, "Constructor(99) / GetRightChild()");

  // node 2 is leftChild, node 3 is rightChild
  inode1.SetLeftChild(&inode2);
  Test(inode1.GetLeftChild() == &inode2, "SetLeftChild() / GetLeftChild()");
  inode1.SetRightChild(&inode3);
  Test(inode1.GetRightChild() == &inode3, "SetRightChild() / GetRightChild()");
  // swap children -- node3 leftChild, node2 rightChild
  UpdateLink(inode1.GetLeftChild(), &inode3);
  UpdateLink(inode1.GetRightChild(), &inode2);
  Test(inode1.GetLeftChild() == &inode3, "SetLeftChild() / GetLeftChild()");
  Test(inode1.GetRightChild() == &inode2, "SetRightChild() / GetRightChild()");

  inode1.SetContents(42);
  Test(inode1.GetContents() == 42, "SetContents(42) / GetContents()");
  UpdateContents(inode1.GetContents(), 24);
  Test(inode1.GetContents() == 24, "SetContents(24) / GetContents()");

  cout << "******<char>******" << endl;
  BSTNode<char> cnode1;
  BSTNode<char> cnode2('A');
  BSTNode<char> cnode3('a');

  Test(cnode1.GetContents() == '\0', "Default Constructor / GetContents()");
  Test(cnode1.GetLeftChild() == NULL, "Default Constructor / GetLeftChild()");
  Test(cnode1.GetRightChild() == NULL, "Default Constructor / GetRightChild()");

  Test(cnode2.GetContents() == 'A', "Constructor('A') / GetContents()");
  Test(cnode2.GetLeftChild() == NULL, "Constructor('A') / GetLeftChild()");
  Test(cnode2.GetRightChild() == NULL, "Constructor('A') / GetRightChild()");

  // node 2 is leftChild, node 3 is rightChild
  cnode1.SetLeftChild(&cnode2);
  Test(cnode1.GetLeftChild() == &cnode2, "SetLeftChild() / GetLeftChild()");
  cnode1.SetRightChild(&cnode3);
  Test(cnode1.GetRightChild() == &cnode3, "SetRightChild() / GetRightChild()");
  // swap children -- node3 leftChild, node2 rightChild
  UpdateLink(cnode1.GetLeftChild(), &cnode3);
  UpdateLink(cnode1.GetRightChild(), &cnode2);
  Test(cnode1.GetLeftChild() == &cnode3, "SetLeftChild() / GetLeftChild()");
  Test(cnode1.GetRightChild() == &cnode2, "SetRightChild() / GetRightChild()");

  cnode1.SetContents('Z');
  Test(cnode1.GetContents() == 'Z', "SetContents('Z') / GetContents()");
  UpdateContents(cnode1.GetContents(), 'z');
  Test(cnode1.GetContents() == 'z', "SetContents('z') / GetContents()");

  cout << "******<string>******" << endl;
  BSTNode<string> snode1;
  BSTNode<string> snode2("Hello");
  BSTNode<string> snode3("Goodbye");

  Test(snode1.GetContents() == "", "Default Constructor / GetContents()");
  Test(snode1.GetLeftChild() == NULL, "Default Constructor / GetLeftChild()");
  Test(snode1.GetRightChild() == NULL, "Default Constructor / GetRightChild()");

  Test(snode2.GetContents() == "Hello",
       "Constructor(\"Hello\") / GetContents()");
  Test(snode2.GetLeftChild() == NULL,
       "Constructor(\"Hello\") / GetLeftChild()");
  Test(snode2.GetRightChild() == NULL,
       "Constructor(\"Hello\") / GetRightChild()");

  // node 2 is leftChild, node 3 is rightChild
  snode1.SetLeftChild(&snode2);
  Test(snode1.GetLeftChild() == &snode2, "SetLeftChild() / GetLeftChild()");
  snode1.SetRightChild(&snode3);
  Test(snode1.GetRightChild() == &snode3, "SetRightChild() / GetRightChild()");
  // swap children -- node3 leftChild, node2 rightChild
  UpdateLink(snode1.GetLeftChild(), &snode3);
  UpdateLink(snode1.GetRightChild(), &snode2);
  Test(snode1.GetLeftChild() == &snode3, "SetLeftChild() / GetLeftChild()");
  Test(snode1.GetRightChild() == &snode2, "SetRightChild() / GetRightChild()");

  snode1.SetContents("One");
  Test(snode1.GetContents() == "One", "SetContents(\"One\") / GetContents()");
  UpdateContents(snode1.GetContents(), string("Two"));
  Test(snode1.GetContents() == "Two", "SetContents(\"Two\") / GetContents()");

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

template<typename T>
void UpdateContents(T& contents, T new_contents) {
  contents = new_contents;
}

template<typename T>
void UpdateLink(BSTNode<T>*& link, BSTNode<T>* new_link) {
  link = new_link;
}
