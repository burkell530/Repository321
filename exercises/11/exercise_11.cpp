/*
 * Name        : exercise_11.cpp
 * Author      : Luke Sathrum
 * Description : Unit_Test to test your class.
 */
#include <iostream>
#include <sstream>
#include <streambuf>
#include "money.h"
using std::cout;
using std::endl;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();

// Program Execution Starts Here
int main(int argc, char* argv[]) {
  // To help test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  Money amount1(123, 45), amount2(10, 9);
  Money sum = amount1 + amount2;
  Money diff1 = amount1 - amount2;
  Money diff2 = amount2 - amount1;

  Test(sum.dollars() == 133 && sum.cents() == 54, "$123.45 + $10.09");
  Test(diff1.dollars() == 113 && diff1.cents() == 36, "$123.45 - $10.09");
  Test(diff2.dollars() == -113 && diff2.cents() == -36, "$10.09 - $123.45");
  amount1 = -amount1;
  Test(amount1.dollars() == -123 && amount1.cents() == -45, "-$123.45");
  Test((diff2 == diff1) == false, "$113.36 == $-113.36");

  amount1.set_dollars(-8);
  amount1.set_cents(-75);
  amount2.set_dollars(0);
  amount2.set_cents(50);
  sum = amount1 + amount2;
  diff1 = amount1 - amount2;
  diff2 = amount2 - amount1;

  Test(sum.dollars() == -8 && sum.cents() == -25, "$-8.75 + $0.50");
  Test(diff1.dollars() == -9 && diff1.cents() == -25, "$-8.75 - $0.50");
  Test(diff2.dollars() == 9 && diff2.cents() == 25, "$0.50 - $8.75");
  diff1 = -diff1;
  Test(diff1.dollars() == 9 && diff1.cents() == 25, "-$-9.25");
  Test((diff2 == diff1) == true, "$9.25 == $9.25");

  Money one(0, 10), two(0, -10), three(100, 2), four(-100, -2);
  std::streambuf* old_cout = cout.rdbuf();
  std::ostringstream capture_cout;
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(0, 10);
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "$0.10", "<< Money(0, 10)");
  capture_cout.str("");
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(0, -10);
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "$-0.10", "<< Money(0, -10)");
  capture_cout.str("");
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(100, 2);
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "$100.02", "<< Money(100, 2)");
  capture_cout.str("");
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(-100, -2);
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "$-100.02", "<< Money(-100, -2)");
  cout << string(temp.length() - 1, '-') << endl;
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
