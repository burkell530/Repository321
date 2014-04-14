/*
 * Name        : exercise_20.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class SList.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include "sl_list.h"
#include "sl_node.h"

#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
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
  // Tests
  SLList list;

  Test(list.size() == 0, "Default Constructor & size()");
  Test(list.ToString() == "", "ToString()");
  Test(list.GetHead() == 0, "GetHead()");
  Test(list.GetTail() == 0, "GetTail()");

  list.Insert(10);
  Test(list.size() == 1, "Insert(10) & size()");
  Test(list.ToString() == "10", "ToString()");

  list.Insert(50);
  Test(list.size() == 2, "Insert(50) & size()");
  Test(list.ToString() == "10, 50", "ToString()");

  list.Insert(30);
  Test(list.size() == 3, "Insert(30) & size()");
  Test(list.ToString() == "10, 30, 50", "ToString()");
  Test(list.GetHead() == 10, "GetHead()");
  Test(list.GetTail() == 50, "GetTail()");

  list.Insert(5);
  Test(list.size() == 4, "Insert(5) & size()");
  Test(list.ToString() == "5, 10, 30, 50", "ToString()");

  list.Insert(55);
  Test(list.size() == 5, "Insert(55) & size()");
  Test(list.ToString() == "5, 10, 30, 50, 55", "ToString()");

  list.Insert(20);
  Test(list.size() == 6, "Insert(20) & size()");
  Test(list.ToString() == "5, 10, 20, 30, 50, 55", "ToString()");

  list.Insert(40);
  Test(list.size() == 7, "Insert(40) & size()");
  Test(list.ToString() == "5, 10, 20, 30, 40, 50, 55", "ToString()");

  list.Insert(30);
  Test(list.size() == 8, "Insert(30) & size()");
  Test(list.ToString() == "5, 10, 20, 30, 30, 40, 50, 55", "ToString()");

  list.Insert(5);
  Test(list.size() == 9, "Insert(5) & size()");
  Test(list.ToString() == "5, 5, 10, 20, 30, 30, 40, 50, 55", "ToString()");

  list.Insert(55);
  Test(list.size() == 10, "Insert(55) & size()");
  Test(list.ToString() == "5, 5, 10, 20, 30, 30, 40, 50, 55, 55", "ToString()");

  cout << "\nYour List: " << list.ToString() << endl << endl;

  Test(list.RemoveFirstOccurence(1) == false, "RemoveFirstOccurence(1)");

  Test(list.RemoveFirstOccurence(5) == true, "RemoveFirstOccurence(5)");
  Test(list.size() == 9, "size()");
  Test(list.ToString() == "5, 10, 20, 30, 30, 40, 50, 55, 55", "ToString()");

  Test(list.RemoveFirstOccurence(30) == true, "RemoveFirstOccurence(30)");
  Test(list.size() == 8, "size()");
  Test(list.ToString() == "5, 10, 20, 30, 40, 50, 55, 55", "ToString()");

  Test(list.RemoveFirstOccurence(30) == true, "RemoveFirstOccurence(30)");
  Test(list.size() == 7, "size()");
  Test(list.ToString() == "5, 10, 20, 40, 50, 55, 55", "ToString()");

  Test(list.RemoveFirstOccurence(55) == true, "RemoveFirstOccurence(55)");
  Test(list.size() == 6, "size()");
  Test(list.ToString() == "5, 10, 20, 40, 50, 55", "ToString()");

  Test(list.RemoveFirstOccurence(10) == true, "RemoveFirstOccurence(10)");
  Test(list.size() == 5, "size()");
  Test(list.ToString() == "5, 20, 40, 50, 55", "ToString()");

  Test(list.GetHead() == 5, "GetHead()");
  Test(list.GetTail() == 55, "GetTail()");

  list.Clear();
  Test(list.size() == 0, "Clear() & size()");
  Test(list.ToString() == "", "ToString()");

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
  cout << test_number << " " << more_info << "!\n";
  test_number++;
  ut_total++;
}
