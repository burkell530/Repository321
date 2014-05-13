/*
 * Name        : exercise_19.cpp
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
  std::stringstream full_head_list, half_head_list, full_tail_list,
      half_tail_list;
  for (int i = 999; i > 0; i--) {
    full_head_list << i << ", ";
    if (i < 500)
      half_head_list << i << ", ";
  }
  full_head_list << 0;
  half_head_list << 0;

  for (int i = 0; i < 999; i++) {
    full_tail_list << i << ", ";
    if (i < 499)
      half_tail_list << i << ", ";
  }
  full_tail_list << 999;
  half_tail_list << 499;

  Test(list.size() == 0, "Default Constructor & size()");
  Test(list.ToString() == "", "ToString()");
  Test(list.GetHead() == 0, "GetHead()");
  Test(list.GetTail() == 0, "GetTail()");

  list.RemoveHead();
  Test(list.size() == 0, "RemoveHead() & size()");

  list.RemoveTail();
  Test(list.size() == 0, "RemoveTail() & size()");

  list.InsertHead(1);
  Test(list.size() == 1, "InsertHead(1) & size()");
  Test(list.ToString() == "1", "ToString()");

  list.RemoveHead();
  Test(list.size() == 0, "RemoveHead() & size()");
  Test(list.ToString() == "", "ToString()");

  list.InsertTail(5);
  Test(list.size() == 1, "InsertTail(5) & size()");
  Test(list.ToString() == "5", "ToString()");

  list.RemoveTail();
  Test(list.size() == 0, "RemoveTail() & size()");
  Test(list.ToString() == "", "ToString()");

  list.InsertHead(10);
  list.InsertHead(20);
  Test(list.size() == 2, "InsertHead(10), InsertHead(20) & size()");
  Test(list.ToString() == "20, 10", "ToString()");

  list.RemoveHead();
  Test(list.size() == 1, "RemoveHead() & size()");
  Test(list.ToString() == "10", "ToString()");

  list.InsertHead(20);
  list.RemoveTail();
  Test(list.size() == 1, "InsertHead(20), RemoveTail() & size()");
  Test(list.ToString() == "20", "ToString()");

  list.InsertHead(5);
  Test(list.size() == 2, "InsertHead(5) & size()");
  Test(list.ToString() == "5, 20", "ToString()"); //19

  list.Clear();
  Test(list.size() == 0, "Clear() & size()");
  Test(list.ToString() == "", "ToString()");

  list.InsertHead(10);
  list.InsertHead(5);
  list.InsertTail(20);
  list.InsertTail(25);
  Test(
      list.size() == 4,
      "InsertHead(10), InsertHead(5), InsertTail(20), InsertTail(25) & size()");
  Test(list.ToString() == "5, 10, 20, 25", "ToString()");

  Test(list.GetHead() == 5, "GetHead()");
  Test(list.GetTail() == 25, "GetTail()");
  Test(list.size() == 4, "size()");
  Test(list.ToString() == "5, 10, 20, 25", "ToString()");

  list.RemoveHead();
  list.RemoveTail();
  list.RemoveHead();
  list.RemoveTail();
  Test(list.size() == 0,
       "RemoveHead(), RemoveTail(), RemoveHead(), RemoveTail() & size()");
  Test(list.ToString() == "", "ToString()");

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertHead(i);
  Test(list.size() == 1000, "InsertHead() \"HIGH LOAD\" & size()");
  Test(list.ToString() == full_head_list.str(), "ToString()");

  for (unsigned int i = 0; i < 500; i++)
    list.RemoveHead();
  Test(list.size() == 500, "RemoveHead() \"HIGH LOAD / 2\" & size()");
  Test(list.ToString() == half_head_list.str(), "ToString()");
  for (unsigned int i = 0; i < 600; i++)
    list.RemoveHead();
  Test(list.size() == 0, "RemoveHead() \"HIGH LOAD / 2\" & size()");
  Test(list.ToString() == "", "ToString()");

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertTail(i);
  Test(list.size() == 1000, "InsertTail() \"HIGH LOAD\" & size()");
  Test(list.ToString() == full_tail_list.str(), "ToString()");

  for (unsigned int i = 0; i < 500; i++)
    list.RemoveTail();
  Test(list.size() == 500, "RemoveTail() \"HIGH LOAD / 2\" & size()");
  Test(list.ToString() == half_tail_list.str(), "ToString()");
  for (unsigned int i = 0; i < 600; i++)
    list.RemoveTail();
  Test(list.size() == 0, "RemoveTail() \"HIGH LOAD / 2\" & size()");
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
