/*
 * Name        : exercise_6.cpp
 * Author      : Lauri Burke
 * Description : Working with Arrays
 */

#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

string PrepareForDisplay(int values[], int size, char separator = ',');
bool HasValue(int values[], int size, int value);
int ValueAt(int values[], int size, int index, bool& error);
int Sum(int values[], int size);
bool SwapValues(int values[], int size, int index1, int index2);

// For testing (DO NOT ALTER)
void UnitTest();
void Test(bool test, string more_info = "");

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}
int ValueAt(int values[], int size, int index, bool& error) {
  for (int i = 0; i < size; i++) {
      if (index >= size || size == 0) {
        error = true;
        return 0;
        } else {
        error = false;
        return values[index];
      }
  }
}
bool HasValue(int values[], int size, int value) {
  bool evaluation = false;
  for (int i = 0; i < size; i++) {
      if (values[i] == value) {
      evaluation = true;
      return evaluation;
    }
  }
  return evaluation;
}
string PrepareForDisplay(int values[], int size, char separator) {
stringstream ss;
for (int i = 0; i < size -1; i++) {
  ss << values[i] << separator;
  }
  ss << values[size - 1];
  return ss.str();
}
bool SwapValues(int values[], int size, int index1, int index2) {
  bool test_works = false;
  if (index1 > size || index1 < 0 || index2 > size || index2 < 0) {
    return test_works;
    }  else {
    int temp = values[index1];
    values[index1] = values[index2];
    values[index2] = temp;
    test_works = true;
    return test_works;
    }
}
int Sum(int values[], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += values[i];
  }
  return total;
}
// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  int values[] = { 3, 5, 7, 9, 11 };
  int size = 5;
  Test(PrepareForDisplay(values, size) == "3,5,7,9,11",
       "PrepareForDisplay(values, size)");
  Test(PrepareForDisplay(values, size, ' ') == "3 5 7 9 11",
       "PrepareForDisplay(values, size, ' ')");
  Test(PrepareForDisplay(values, size, ':') == "3:5:7:9:11",
       "PrepareForDisplay(values, size, ':')");
  Test(HasValue(values, size, 0) == false, "HasValue(values, size, 0)");
  Test(HasValue(values, size, 3) == true, "HasValue(values, size, 3)");
  Test(HasValue(values, size, 11) == true, "HasValue(values, size, 11)");
  bool error = true;
  Test(ValueAt(values, size, 0, error) == 3 && error == false,
       "ValueAt(values, size, 0, error)");
  Test(ValueAt(values, size, 5, error) == 0 && error == true,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(values, size, 4, error) == 11 && error == false,
       "ValueAt(values, size, 4, error)");
  Test(Sum(values, size) == 35, "Sum(values, size)");
  Test(Sum(values, 1) == 3, "Sum(values, 1)");
  Test(Sum(values, 0) == 0, "Sum(values, 0)");
  bool success;
  success = SwapValues(values, size, 0, 4);
  Test(values[0] == 11 && values[4] == 3 && success,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(values, size, 1, 3);
  Test(values[1] == 9 && values[3] == 5 && success,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(values, size, 2, 2);
  Test(values[2] == 7 && success, "SwapValues(values, size, 2, 2)");
  success = SwapValues(values, size, -2, 2);
  Test(values[2] == 7 && !success, "SwapValues(values, size, -2, 2)");
  success = SwapValues(values, size, 2, 10);
  Test(values[2] == 7 && !success, "SwapValues(values, size, 2, 10)");
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
