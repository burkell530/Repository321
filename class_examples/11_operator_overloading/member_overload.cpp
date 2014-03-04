/*
 * Name        : member_overload.cpp
 * Author      : Luke Sathrum
 * Description : Overloading Operators as Member Functions. Our previous example
 *               has been converted to member functions.
 */

#include <iostream>
using std::cout;
using std::endl;

/*
 * A class to represent cents
 */
class Cents {
 public:
  /*
   * This constructor sets the internal cents_ member variable to the provided
   * argument.
   * @param int cents - The cents to set
   */
  Cents(int cents);
  /*
   * Accessor
   * Returns the value of the cents_ member variable
   * @return int - The value of cents_
   */
  int cents() const;
  /*
   * Mutator
   * Sets the value of the cents_ member variable
   * @param int cents - The cents to set
   */
  void set_cents(int cents);
  /*
   * Overload of + operator. Adds the cents_ member variable of calling object
   * and object parameter
   * @param Cents c2 - The second object
   * @return Cents - An object where the cents for the calling object and the
   *                 parameter have been added together.
   */
  const Cents operator +(const Cents &c2) const;
  /*
   * Overload of - operator. Subtracts the cents_ member variable of object
   * parameter from the calling object
   * @param Cents c2 - The second object
   * @return Cents - An object where the cents for the object parameter has been
   *                 subtracted from the calling object.
   */
  const Cents operator -(const Cents &c2) const;
  /*
   * Overload of == operator. Compares the calling object and the object
   * parameter.
   * @param Cents c2 - The second object
   * @return bool - True if the cents are equal, otherwise false
   */
  bool operator ==(const Cents &c2) const;
  /*
   * Overload of unary - operator.
   * @return Cents - An object where the cents have been negated
   */
  const Cents operator -() const;

 private:
  int cents_;
};

// Program starts here
int main() {
  // Create some objects
  Cents cents1(0);
  Cents cents2(1);
  // Use overloaded Arithmetic Operators
  Cents cents_sum = cents1 + cents2;
  Cents cents_difference = cents1 - cents2;
  cout << "I have " << cents_sum.cents() << " cents after addition." << endl;
  cout << "I have " << cents_difference.cents() << " cents after subtraction."
       << endl;
  // Use overloaded unary -
  cents_difference = -cents_difference;
  cout << "I have " << cents_difference.cents() << " after unary minus."
       << endl;
  // Use overloaded assignment operator
  if (cents_sum == cents_difference)
    cout << "The objects have the same values\n";
  else
    cout << "The objects do not have the same values\n";

  // This ends our program
  return 0;
}

Cents::Cents(int cents) {
  cents_ = cents;
}

int Cents::cents() const {
  return cents_;
}

void Cents::set_cents(int cents) {
  cents_ = cents;
}

const Cents Cents::operator +(const Cents &c2) const {
  // Use the Cents constructor and operator+(int, int)
  // Notice that we can access the private member variable of c2
  return Cents(cents_ + c2.cents_);
}

const Cents Cents::operator -(const Cents &c2) const {
  // Use the Cents constructor and operator-(int, int)
  return Cents(cents_ - c2.cents_);
}

bool Cents::operator ==(const Cents &c2) const {
  return (cents_ == c2.cents_);
}

const Cents Cents::operator -() const {
  return (-cents_);
}
