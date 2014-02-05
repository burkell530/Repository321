/*
 * Name        : functions.cpp
 * Author      : Luke Sathrum
 * Description : Example of a function in C++
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * TotalCost computes the total cost based on the price and quantity of an item
 * @param const int &quantity - How many items
 * @param const double &price - How much the individual item costs
 * @return double - The computed total cost
 */
double TotalCost(const int &quantity, const double &price);

// Program starts here
int main() {
  // Set up our Variables
  double price, bill;
  int number;

  // Get price and number from the user
  cout << "Enter the number of items purchased: ";
  cin >> number;
  cout << "Enter the price per item $";
  cin >> price;

  // Call function TotalCost
  bill = TotalCost(number, price);
  // The Magic Formula
  cout.setf(std::ios::fixed | std::ios::showpoint);
  cout.precision(2);
  // Output our computed bill
  cout << endl << number << " items @ $" << price << " each.\n"
       << "Final bill: $" << bill << endl;

  // This ends our program
  return 0;
}

double TotalCost(const int &quantity, const double &price) {
  // Calculate and return the total cost
  return price * quantity;
}
