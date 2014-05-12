/*
 * Name        : exercise_24.cpp
 * Author      : Luke Sathrum
 * Description : Modifying your first Binary Search Tree
 */

#include <iostream>
#include <string>
#include <sstream>
#include "bs_tree.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "", string yours = "!", string actual =
              "!");
void UnitTest();
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
  cout << "Total Number of Tests: 67" << endl;
  // Tests
  BSTree tree;
  string actual = "";

  Test(tree.Remove(1) == false, "Default Constructor / Remove(1)");
  Test(
      tree.Insert(50) == true && tree.Insert(50) == false
          && tree.Insert(25) == true && tree.Insert(25) == false
          && tree.Insert(75) == true && tree.Insert(75) == false
          && tree.Insert(30) == true && tree.Insert(30) == false
          && tree.Insert(29) == true && tree.Insert(29) == false
          && tree.Insert(31) == true && tree.Insert(31) == false
          && tree.Insert(32) == true && tree.Insert(32) == false
          && tree.Insert(33) == true && tree.Insert(33) == false
          && tree.Insert(34) == true && tree.Insert(34) == false,
      "Insert Stress Test");
  Test(tree.GetSize() == 9, "GetSize()");
  actual = "25 29 30 31 32 33 34 50 75 ";
  Test(tree.FindMin() == 25, "FindMin()");
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  tree.Clear();
  Test(tree.GetSize() == 0, "Clear() / GetSize()");
  Test(tree.FindMin() == 0, "FindMin()");

  Test(tree.Insert(10) == true, "Insert(10)");
  Test(tree.GetSize() == 1, "GetSize()");
  actual = "10 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Remove(10) == true, "Remove(10)");
  Test(tree.GetSize() == 0, "GetSize()");
  actual = "";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(
      tree.Insert(10) == true && tree.Insert(5) == true
          && tree.Insert(15) == true,
      "Insert(10), Insert(5), Insert(15)");
  Test(tree.GetSize() == 3, "GetSize()");
  Test(tree.FindMin() == 5, "FindMin()");
  actual = "5 10 15 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(1) == false, "Remove(1)");
  Test(tree.Remove(5) == true, "Remove(5)");
  Test(tree.GetSize() == 2, "GetSize()");
  Test(tree.FindMin() == 10, "FindMin()");
  actual = "10 15 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(5) == true, "Insert(5)");
  Test(tree.GetSize() == 3, "GetSize()");
  Test(tree.FindMin() == 5, "FindMin()");
  actual = "5 10 15 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(15) == true, "Remove(15)");
  Test(tree.GetSize() == 2, "GetSize()");
  Test(tree.FindMin() == 5, "FindMin()");
  actual = "5 10 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(15) == true, "Insert(15)");
  Test(tree.GetSize() == 3, "GetSize()");
  Test(tree.FindMin() == 5, "FindMin()");
  actual = "5 10 15 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(10) == true, "Remove(10)");
  Test(tree.GetSize() == 2, "GetSize()");
  Test(tree.FindMin() == 5, "FindMin()");
  actual = "5 15 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(3) == true, "Insert(3)");
  Test(tree.GetSize() == 3, "GetSize()");
  Test(tree.FindMin() == 3, "FindMin()");
  actual = "3 5 15 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);


  Test(tree.Remove(15) == true, "Remove(15)");
  Test(tree.GetSize() == 2, "GetSize()");
  Test(tree.FindMin() == 3, "FindMin()");
  actual = "3 5 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(10) == true, "Insert(10)");
  Test(tree.GetSize() == 3, "GetSize()");
  Test(tree.FindMin() == 3, "FindMin()");
  actual = "3 5 10 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(1) == false, "Remove(1)");
  Test(tree.Remove(100) == false, "Remove(100)");
  Test(tree.Remove(4) == false, "Remove(4)");
  Test(tree.Remove(7) == false, "Remove(7)");

  Test(tree.Remove(5) == true, "Remove(5)");
  Test(tree.GetSize() == 2, "GetSize()");
  Test(tree.FindMin() == 3, "FindMin()");
  actual = "3 10 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(10) == true, "Remove(10)");
  Test(tree.GetSize() == 1, "GetSize()");
  Test(tree.FindMin() == 3, "FindMin()");
  actual = "3 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(3) == true, "Remove(10)");
  Test(tree.GetSize() == 0, "GetSize()");
  Test(tree.FindMin() == 0, "FindMin()");
  actual = "";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(1) == false, "Remove(1)");

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n" << "Passed: " << ut_passed << " / "
       << ut_total << endl << "Failed: " << ut_failed << " / " << ut_total
       << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info, string yours, string actual) {
  static int test_number = 1;
  if (test) {
    cout << "PASSSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED  TEST ";
    ut_failed++;
  }
  cout << test_number << " " << more_info << "!" << endl;
  if (!test) {
    if (yours != "!")
      cout << "Yours: \"" << yours << '"' << endl;
    if (actual != "!")
      cout << "Actual: \"" << actual << '"' << endl;
  }
  ut_total++;
  test_number++;
}
