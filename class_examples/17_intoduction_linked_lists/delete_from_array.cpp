/*
 * Name        : delete_from_array.cpp
 * Author      : Luke Sathrum
 * Description : Example of how to delete from an array
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
  int values[5] = { 5, 3, 8, 2 };
  int list_size = 4;

  // Let's show the array values
  cout << "Before Deletion: ";
  Output(values, list_size);

  // Where we want to delete
  int position_to_delete = 1;

  // To be done in class...

  // Make sure the position to delete is valid
  if (position_to_delete >= 0 && position_to_delete < list_size) {
    list_size--;
    for (int i = position_to_delete; i < list_size; i++) {
      values[i] = values[i + 1];
    }
  } else {
    cerr << "That location is invalid!" << endl;
  }

  // Let's show the array values after
  cout << "After  Deletion: ";
  Output(values, list_size);

  // This ends our program
  return 0;
}
