/*
 * Name        : exercise_18.cpp
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
using std::stringstream;

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
  SLList list;
  stringstream full_list, half_list;
  for (int i = 999; i > 0; i--) {
    full_list << i << ", ";
    if (i < 500)
      half_list << i << ", ";
  }
  full_list << 0;
  half_list << 0;

  Test(list.size() == 0, "Default Constructor & size()");
  Test(list.ToString() == "", "ToString()");

  list.RemoveHead();
  Test(list.size() == 0, "RemoveHead() & size()");

  list.InsertHead(1);
  Test(list.size() == 1, "InsertHead(1) & size()");
  Test(list.ToString() == "1", "ToString()");

  list.RemoveHead();
  Test(list.size() == 0, "RemoveHead() & size()");
  Test(list.ToString() == "", "ToString()");

  list.InsertHead(10);
  list.InsertHead(20);
  Test(list.size() == 2, "InsertHead(10), InsertHead(20) & size()");
  Test(list.ToString() == "20, 10", "ToString()");

  list.RemoveHead();
  Test(list.size() == 1, "RemoveHead() & size()");
  Test(list.ToString() == "10", "ToString()");

  list.InsertHead(5);
  Test(list.size() == 2, "InsertHead(5) & size()");
  Test(list.ToString() == "5, 10", "ToString()");

  list.Clear();
  Test(list.size() == 0, "Clear() & size()");
  Test(list.ToString() == "", "ToString()");

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertHead(i);
  Test(list.size() == 1000, "InsertHead() \"HIGH LOAD\" & size()");
  Test(list.ToString() == full_list.str(), "ToString()");

  for (unsigned int i = 0; i < 500; i++)
    list.RemoveHead();
  Test(list.size() == 500, "RemoveHead() \"HIGH LOAD / 2\" & size()");
  Test(list.ToString() == half_list.str(), "ToString()");
  for (unsigned int i = 0; i < 600; i++)
    list.RemoveHead();
  Test(list.size() == 0, "RemoveHead() \"HIGH LOAD / 2\" & size()");
  Test(list.ToString() == "", "ToString()");

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
