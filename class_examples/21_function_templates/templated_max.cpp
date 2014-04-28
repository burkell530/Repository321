/*
 * Name        : templated_max.cpp
 * Author      : Luke Sathrum
 * Description : Example of writing a single templated function to determine
 *               which value is larger
 */

#include <iostream>
using std::cout;
using std::endl;

// This function can handle any type to determine which value is larger
// Note this function cannot handle a call with two different types
template<typename Type>
Type Max(Type x, Type y) {
  if (x > y)
    return x;
  else
    return y;
}

// Program starts here
int main() {
  // Call our templated function (not really calling it but its instances)
  cout << "Which is bigger (5, 10)?      ";
  cout << Max(5, 10) << endl;
  cout << "Which is bigger (10.3, 10.1)? ";
  cout << Max(5.5, 10.1) << endl;

  // This ends our program
  return 0;
}
