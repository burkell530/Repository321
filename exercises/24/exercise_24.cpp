/*
 * Name        : exercise_24.cpp
 * Author      : Luke Sathrum
 * Description : Creating your first Binary Search Tree
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
  cout << "Total Number of Test: 31" << endl;
  // Tests
  BSTree tree;
  string actual = "";

  Test(tree.GetSize() == 0, "Default Constructor / GetSize()");
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(50) == true, "Insert(50)");
  Test(tree.GetSize() == 1, "GetSize()");
  actual = "50 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(20) == true, "Insert(20)");
  Test(tree.GetSize() == 2, "GetSize()");
  actual = "20 50 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(80) == true, "Insert(80)");
  Test(tree.GetSize() == 3, "GetSize()");
  actual = "20 50 80 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(30) == true, "Insert(30)");
  Test(tree.GetSize() == 4, "GetSize()");
  actual = "20 30 50 80 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(70) == true, "Insert(70)");
  Test(tree.GetSize() == 5, "GetSize()");
  actual = "20 30 50 70 80 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(0) == true, "Insert(0)");
  Test(tree.GetSize() == 6, "GetSize()");
  actual = "0 20 30 50 70 80 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(100) == true, "Insert(100)");
  Test(tree.GetSize() == 7, "GetSize()");
  actual = "0 20 30 50 70 80 100 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);
  Test(tree.Insert(50) == false, "Insert(50)");
  Test(tree.GetSize() == 7, "GetSize()");
  actual = "0 20 30 50 70 80 100 ";
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

  tree.Clear();
  Test(tree.GetSize() == 0, "Clear() / GetSize()");
  actual = "";
  Test(tree.InOrder() == "", "InOrder()", tree.InOrder(), actual);

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
  Test(tree.InOrder() == actual, "InOrder()", tree.InOrder(), actual);

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
      cout << "Actual: \"" << actual << '"' <<endl;
  }
  test_number++;
  ut_total++;
}
