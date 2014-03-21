/*
* Name    :user_input_handler
* Author  :Lauri Burke
* Sources: Allen Webster, Boyd Trollenger's Cin Reader
*          Absolute C++ by Savitch, Classmates: Sean,
*          Hanna, Luke Sathrum.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <climits>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// Class definition
class UserInputHandler {
public:
// Constructor
  UserInputHandler();
// Function to get a single character from input
  char GetSingleCharacter(string str_ = "");
// Function to get an integer from input
  int GetInteger(int min_int_ = INT_MIN, int max_int_ = INT_MAX);
// Function to get a floating point number from input
  double GetDouble();
// Function to get a boolean value from input
  bool GetBoolean();
// Function to get a string from input within specified parameters
  string GetString(int max_length_ , bool empty_string_);

// Getters and setters to access and mutate private member variables
  void SetInvalidChar(string invalid_char);
  string GetInvalidChar() const;
  void SetCharNotAllowed(string char_not_allowed);
  string GetCharNotAllowed() const;
  void SetInvalidInt(string invalid_int);
  string GetInvalidInt() const;
  void SetLowInt(string low_int);
  string GetLowInt() const;
  void SetHighInt(string high_int);
  string GetHighInt() const;
  void SetInvalidDouble(string invalid_double);
  string GetInvalidDouble() const;
  void SetInvalidBool(string invalid_bool);
  void SetTooLongString (string too_long_string);
  string GetTooLongString() const;
  void SetEmptyString(string empty_string);
  string GetEmptyString() const;

// Private varaibles
private:
  string invalid_char_;
  string char_not_allowed_;
  string invalid_int_;
  string low_int_;
  string high_int_;
  string invalid_double_;
  string invalid_bool_;
  string too_long_string_;
  string empty_string_;  
};
