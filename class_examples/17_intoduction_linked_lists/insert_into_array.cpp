/*
 * Name        : insert_into_array.cpp
 * Author      : Luke Sathrum
 * Description : Example of how to insert into an array
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

/*
 * Outputs the contents of an array
 * @param int[] array - The array to output
 * @param const int &size - The size of the array
 */
void Output(int array[], const int &size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    cout << array[i] << ", ";
  }
  cout << array[i] << endl;
}

// Program starts here
int main() {
  // Setup our array and variables
  int values[5] = { 5, 8, 2 };
  int list_size = 3;
  int list_capacity = 5;

  // Let's show the array values
  cout << "Before Insertion: ";
  Output(values, list_size);

  // What and where we want to insert
  int position_to_insert = 1;
  int value_to_insert = 3;

  // CODE FOR INSERTION

  // Let's show the array values after
  cout << "After  Insertion: ";
  Output(values, list_size);

  // This ends our program
  return 0;
}
