/*
 * Name        : exercise_21.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for function templates.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <string>
#include <sstream>
#include "template.cpp"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

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
  cout << "Total Number of Test: 51" << endl;
  // Tests
  int int_values[] = { 3, 5, 7, 9, 11 };
  int size = 5;
  cout << "\n********Testing Integers********\n";
  Test(PrepareForDisplay(int_values, size) == "3,5,7,9,11",
       "PrepareForDisplay(values, size)");
  Test(PrepareForDisplay(int_values, size, ' ') == "3 5 7 9 11",
       "PrepareForDisplay(values, size, ' ')");
  Test(PrepareForDisplay(int_values, size, ':') == "3:5:7:9:11",
       "PrepareForDisplay(values, size, ':')");
  Test(HasValue(int_values, size, 0) == false, "HasValue(values, size, 0)");
  Test(HasValue(int_values, size, 3) == true, "HasValue(values, size, 3)");
  Test(HasValue(int_values, size, 11) == true, "HasValue(values, size, 11)");
  bool error = true;
  Test(ValueAt(int_values, size, 0, error) == 3 && error == false,
       "ValueAt(values, size, 0, error)");
  Test(ValueAt(int_values, size, 5, error) == 0 && error == true,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(int_values, size, 4, error) == 11 && error == false,
       "ValueAt(values, size, 4, error)");
  Test(Sum(int_values, size) == 35, "Sum(values, size)");
  Test(Sum(int_values, 1) == 3, "Sum(values, 1)");
  Test(Sum(int_values, 0) == 0, "Sum(values, 0)");
  bool success;
  success = SwapValues(int_values, size, 0, 4);
  Test(int_values[0] == 11 && int_values[4] == 3 && success,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(int_values, size, 1, 3);
  Test(int_values[1] == 9 && int_values[3] == 5 && success,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(int_values, size, 2, 2);
  Test(int_values[2] == 7 && success, "SwapValues(values, size, 2, 2)");
  success = SwapValues(int_values, size, -2, 2);
  Test(int_values[2] == 7 && !success, "SwapValues(values, size, -2, 2)");
  success = SwapValues(int_values, size, 2, 10);
  Test(int_values[2] == 7 && !success, "SwapValues(values, size, 2, 10)");

  double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
  cout << "\n********Testing Doubles********\n";
  Test(PrepareForDisplay(double_values, size) == "3.10,5.20,7.30,9.40,11.50",
       "PrepareForDisplay(values, size)");
  Test(
      PrepareForDisplay(double_values, size, ' ')
          == "3.10 5.20 7.30 9.40 11.50",
      "PrepareForDisplay(values, size, ' ')");
  Test(
      PrepareForDisplay(double_values, size, ':')
          == "3.10:5.20:7.30:9.40:11.50",
      "PrepareForDisplay(values, size, ':')");
  Test(HasValue(double_values, size, 0.0) == false,
       "HasValue(values, size, 0.0)");
  Test(HasValue(double_values, size, 3.10) == true,
       "HasValue(values, size, 3.10)");
  Test(HasValue(double_values, size, 11.50) == true,
       "HasValue(values, size, 11.50)");
  error = true;
  Test(ValueAt(double_values, size, 0, error) == 3.1 && error == false,
       "ValueAt(values, size, 0, error)");
  Test(ValueAt(double_values, size, 5, error) == 0 && error == true,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(double_values, size, 4, error) == 11.5 && error == false,
       "ValueAt(values, size, 4, error)");
  Test(Sum(double_values, size) == 36.5, "Sum(values, size)");
  Test(Sum(double_values, 1) == 3.10, "Sum(values, 1)");
  Test(Sum(double_values, 0) == 0.0, "Sum(values, 0)");
  success = SwapValues(double_values, size, 0, 4);
  Test(double_values[0] == 11.5 && double_values[4] == 3.1 && success,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(double_values, size, 1, 3);
  Test(double_values[1] == 9.4 && double_values[3] == 5.2 && success,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(double_values, size, 2, 2);
  Test(double_values[2] == 7.3 && success, "SwapValues(values, size, 2, 2)");
  success = SwapValues(double_values, size, -2, 2);
  Test(double_values[2] == 7.3 && !success, "SwapValues(values, size, -2, 2)");
  success = SwapValues(double_values, size, 2, 10);
  Test(double_values[2] == 7.3 && !success, "SwapValues(values, size, 2, 10)");

  string string_values[] = { "A", "B", "C", "D", "E" };
  cout << "\n********Testing Strings********\n";
  Test(PrepareForDisplay(string_values, size) == "A,B,C,D,E",
       "PrepareForDisplay(values, size)");
  Test(PrepareForDisplay(string_values, size, ' ') == "A B C D E",
       "PrepareForDisplay(values, size, ' ')");
  Test(PrepareForDisplay(string_values, size, ':') == "A:B:C:D:E",
       "PrepareForDisplay(values, size, ':')");
  Test(HasValue(string_values, size, string(1, 'a')) == false,
       "HasValue(values, size, \"a\")");
  Test(HasValue(string_values, size, string(1, 'B')) == true,
       "HasValue(values, size, \"B\")");
  Test(HasValue(string_values, size, string(1, 'E')) == true,
       "HasValue(values, size, \"E\")");
  error = true;
  Test(ValueAt(string_values, size, 0, error) == "A" && error == false,
       "ValueAt(values, size, 0, error)");
  Test(ValueAt(string_values, size, 5, error) == "" && error == true,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(string_values, size, 4, error) == "E" && error == false,
       "ValueAt(values, size, 4, error)");
  Test(Sum(string_values, size) == "ABCDE", "Sum(values, size)");
  Test(Sum(string_values, 1) == "A", "Sum(values, 1)");
  Test(Sum(string_values, 0) == "", "Sum(values, 0)");
  success = SwapValues(string_values, size, 0, 4);
  Test(string_values[0] == "E" && string_values[4] == "A" && success,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(string_values, size, 1, 3);
  Test(string_values[1] == "D" && string_values[3] == "B" && success,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(string_values, size, 2, 2);
  Test(string_values[2] == "C" && success, "SwapValues(values, size, 2, 2)");
  success = SwapValues(string_values, size, -2, 2);
  Test(string_values[2] == "C" && !success, "SwapValues(values, size, -2, 2)");
  success = SwapValues(string_values, size, 2, 10);
  Test(string_values[2] == "C" && !success, "SwapValues(values, size, 2, 10)");

  cout << string(temp.length() - 1, '-') << endl;
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
