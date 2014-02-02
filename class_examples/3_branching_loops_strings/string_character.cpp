/*
 * Name        : string_character.cpp
 * Author      : Luke Sathrum
 * Description : Examples of string and character functions
 */

#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program starts here
int main() {
  // Create our string
  string my_string;

  // Use = for assignment
  my_string = "Hello";
  // Use + for concatenation
  my_string = my_string + " World!";
  // Output the string
  cout << my_string << endl;

  // Let's create a second string that is all lowercase
  string lower_string = "hello world!";

  // Compare the string
  if (my_string > lower_string)
    cout << "\nmy_string > lower_string\n";
  else
    cout << "\nmy_string <= lower_string\n";

  // Strings are initialized to the empty string
  string empty_string;

  if (empty_string == "")
    cout << "\nempty_string is empty\n";

  // Getting Characters
  cout << "The character at location 0 is: " << my_string.at(0) << endl;
  cout << "The character at location 3 is: " << my_string.at(3) << endl;
  cout << "The character at location 4 is: " << my_string.at(4) << endl;
  // What if we go beyond our string
  //  cout << "The character at location 20 is: " << myString.at(20) << endl;

  // Setting Character
  my_string.at(0) = 'J';
  cout << "New Word: " << my_string << endl;
  my_string.at(4) = 'Y';
  cout << "New Word: " << my_string << endl;

  // Length
  cout << "The length of our string is: " << my_string.length() << endl << endl;

  // Length and Location in a for loop
  for (unsigned int i = 0; i < my_string.length(); i++) {
    cout << my_string.at(i) << endl;
  }

  // Set the string to something else to test string functions
  my_string = "HELLO";
  cout << "Our String is: " << my_string << endl;

  // Substring
  cout << "The substring is: " << my_string.substr(2, 2) << endl;

  // Empty
  if (my_string.empty() == true)
    cout << "The string is empty\n";
  else
    cout << "The string is not empty\n";

  // Insert into string
  my_string.insert(2, "LLL");
  cout << "Our new string after insert is: " << my_string << endl;

  // Replace
  my_string.replace(0, 3, "___");
  cout << "Our new string after replace is: " << my_string << endl;

  // Find
  cout << "The location of \"LLL\" in our string is: " << my_string.find("LLL")
       << endl;

  // Find First Of
  cout << "The first location of any of the following characters \"LUKE\" is: "
       << my_string.find_first_of("LUKE") << endl;

  cout << "\n\nCharacter Functions\n";

  // Setup some characters
  char char_a = 'A', char_b = 'b', char_c = '1', char_d = ',';

  // Testing characters, don't forget 0 is false and every other number is true
  cout << "Is char_a Alpha? " << isalpha(char_a) << endl;
  cout << "Is char_b Numeric? " << isdigit(char_b) << endl;
  cout << "Is char_c AlphaNumeric? " << isalnum(char_c) << endl;
  cout << "Is char_d Punctuation? " << ispunct(char_d) << endl;

  // Testing character case
  cout << "Is char_a lowercase? " << islower(char_a) << endl;

  // Convert to lowercase
  cout << "char_a to lower is: " << tolower(char_a) << endl;

  // This ends our program
  return 0;
}
