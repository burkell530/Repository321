/*
 * Name        : arithmetic.cpp
 * Author      : Luke Sathrum
 * Description : Escape Sequences, Constants, Arithmetic, Increment/Decrement
 *               and Type Casting
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Program Execution Starts Here
int main() {
  // Create some constants
  const char kTab = '\t';
  const double kPI = 3.1415927;

  // Calculate the area of a circle
  cout << "The area of circle with radius 5 is: " << kTab << 5 * 5 * kPI
       << endl;

  // Some simple arithmetic
  cout << "int 6 + int 9 = " << (6 + 9) << endl;
  cout << "double 6.1 + double 9.2 = " << (6.1 + 9.2) << endl;
  cout << "int 6 + double 9.2 = " << (6 + 9.2) << endl;

  // Integer vs. Double division
  cout << "double 6.0 / double 9.0 = " << (6.0 / 9.0) << endl;
  cout << "int 6 / int 9 = " << (6 / 9) << endl;

  // Type Casting
  cout << "int 6 / typecasted int->double 9 = " << (6 / static_cast<double>(9))
       << endl;

  // Increment and Decrement
  int a = 2, value_produced;

  // Postfix Example
  value_produced = 2 * (a++);
  cout << "a = " << a << "   value_produced = " << value_produced << endl;

  // Prefix Example
  a = 2;
  value_produced = 2 * (++a);
  cout << "a = " << a << "   value_produced = " << value_produced << endl;

  // This ends program execution
  return 0;
}
