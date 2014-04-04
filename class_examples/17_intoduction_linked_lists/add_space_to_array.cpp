/*
 * Name        : add_space_to_array.cpp
 * Author      : Luke Sathrum
 * Description : Example of how to add more space to an array
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

/*
 * Outputs the contents of an array
 * @param int[] scores - The array to fill up
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
  int list_capacity = 5;
  // Note the () will initialize with zeros
  int* values = new int[list_capacity]();
  // Set the initial values
  values[0] = 5, values[1] = 3, values[2] = 8, values[3] = 2;
  int list_size = 4;

  // Let's show the array values
  cout << "Before Adding Space: ";
  Output(values, list_size);
  cout << "All Values in the Array: ";
  Output(values, list_capacity);

  // To be done in class...

  // CODE TO ADD CAPACITY

  // Let's show the array values after
  cout << "After  Adding Space: ";
  Output(values, list_size);
  cout << "All Values in the Array: ";
  Output(values, list_capacity);

  // This ends our program
  return 0;
}
