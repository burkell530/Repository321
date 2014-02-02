/*
 * Name        : branching.cpp
 * Author      : Luke Sathrum
 * Description : Examples of branching statements
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Program starts here
int main() {
  // Declare Variables
  int number;

  // Prompt for a number
  cout << "Please enter a number between 1 and 100: ";
  cin >> number;

  // if-else statement
  if (number > 50)
    cout << "The number is high.";
  else
    cout << "The number is low.";
  cout << endl;

  // if-else-if-else
  if (number >= 90) {
    cout << "A\n";
    cout << "Great Job!";
  } else if (number >= 80) {
    cout << "B\n";
    cout << "Good Job!";
  } else if (number >= 70) {
    cout << "C\n";
    cout << "OK Job!";
  } else {
    cout << "D or F\n";
    cout << "Poor Job!";
  }
  cout << endl;

  // switch
  switch (number / 10) {
    case 9:
      cout << "A";
      break;
    case 8:
      cout << "B";
      break;
    case 7:
      cout << "C";
      break;
    case 6:
      cout << "D";
      break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
      cout << "F";
      break;
    default:
      cout << "Unknown Input";
  }
  cout << endl;

  // This ends our program
  return 0;
}
