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
  int position_to_insert = 3;
  int value_to_insert = 10;

  // To be done in class...

  // Make sure we aren't leaving gaps and the location is at least 0 and there
  // is room to insert
  if (position_to_insert > list_size || position_to_insert < 0) {
    cerr << "That location is invalid!" << endl;
  } else if (list_size >= list_capacity) {
    cerr << "The list is full!" << endl;
  } else {
    // Shift all elements "down"
    for (int i = list_size; i > position_to_insert; i--) {
      values[i] = values[i - 1];
    }
    // Insert the value
    values[position_to_insert] = value_to_insert;
    // Increment the list size
    list_size++;
  }

  // Let's show the array values after
  cout << "After  Insertion: ";
  Output(values, list_size);

  // This ends our program
  return 0;
}
