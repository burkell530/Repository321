/*
 * Name        : dynamic.cpp
 * Author      : Luke Sathrum
 * Description : Examples of creating pointers and dynamic variables / arrays.
 *               In this example we will dynamically create an array to hold
 *               student's names.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program starts here
int main(int argc, char *argv[]) {
  // Creating some pointers and integer variables
  int *pointer, size, i;
  string *students;

  // Creating a dynamic variable
  pointer = new int;

  // Assigning the value 42 to the dynamic variable
  *pointer = 42;

  // Output the values of *pointer and pointer
  cout << "*pointer == " << *pointer << endl;
  cout << "pointer == " << pointer << endl;

  // Get the size of the array
  cout << "How many students? ";
  cin >> size;
  cin.ignore(1000, '\n');
  // Create our dynamic array
  students = new string[size];

  // Get the names of the students
  for (i = 0; i < size; i++) {
    cout << "Enter the first name of student " << (i + 1) << ": ";
    getline(cin, students[i]);
  }

  // Output the students as a comma separated list
  cout << "The students entered were: ";
  for (i = 0; i < (size - 1); i++) {
    cout << students[i] << ", ";
  }
  cout << students[i] << endl;

  // This ends our program
  return 0;
}
