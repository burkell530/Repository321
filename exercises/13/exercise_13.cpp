/*
 * Name        : exercise_13.cpp
 * Author      : FILL IN
 * Description : Working with Pointers and Dynamic Objects
 */
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

/*
 * Allocate memory for a dynamic string with specified contents.
 * @param string contents - The desired contents of the dynamic string
 * @return string* - A pointer to the newly allocated string
 */
string* MakeDynoString(string contents);
// Changing exercise 

/*
 * Free the memory associated with a dynamic string and NULL out its pointer.
 * @param string *& the_string - A pointer (passed by reference) to a dynamic
 *                               string
 */
void ClearDynoString(string *&the_string);

/*
 * Count the number of alphabetic and numeric characters in a string and return
 * its length.
 * @uses isdigit() and isalpha()
 * @param string* the_string - A pointer to the string in which characters will
 *                             be counted
 * @param unsigned int &alpha - Contains the count of alphabetic characters in
 *                              the string on return
 * @param unsinged int &num - Contains the count of numeric characters in the
 *                            string on return
 * @return unsigned int - Contains the length of the_string
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
unsigned int CountChars(string* theString, unsigned int &alpha,
                        unsigned int &num);

/*
 * Find a word inside of a string.
 * @uses String Member function find()
 * @uses String Member Variable npos
 * @param string *the_string - The string in which the search for a word will
 *                             take place
 * @param string the_word - The word to look for inside of the_string
 * @return bool - True if the_word is found in the_string, else false
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
bool FindWord(string *the_string, string the_word);

/*
 * Replace one word in a string with another word.
 * @uses String Member Function find()
 * @uses String Member Function replace()
 * @param string *the_string -  The string that will have a word replaced
 * @param string old_word  - The word inside of the_string being replaced
 * @param string new_word - The word that will be used to replace old_word in
 *                          the_string
 * @return bool - True if old_word was found and replaced, else return false
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
bool ReplaceWord(string* the_string, string old_word, string new_word);

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * Allocate memory for a dynamic string with specified contents.
 * @param string contents - The desired contents of the dynamic string
 * @return string* - A pointer to the newly allocated string
 */
string* MakeDynoString(string contents) {
  string *p1 = new string(contents);
  return p1;
}

/*
 * Free the memory associated with a dynamic string and NULL out its pointer.
 * @param string *& the_string - A pointer (passed by reference) to a dynamic
 *                               string
 */
void ClearDynoString(string *&the_string) {
  delete the_string;
  the_string = NULL;
}

/*
 * Count the number of alphabetic and numeric characters in a string and return
 * its length.
 * @uses isdigit() and isalpha()
 * @param string* the_string - A pointer to the string in which characters will
 *                             be counted
 * @param unsigned int &alpha - Contains the count of alphabetic characters in
 *                              the string on return
 * @param unsinged int &num - Contains the count of numeric characters in the
 *                            string on return
 * @return unsigned int - Contains the length of the_string
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
unsigned int CountChars(string* theString, unsigned int &alpha,
                        unsigned int &num) {
  alpha = 0;
  num = 0;
  if (theString == 0)
    throw "NULL STRING REFERENCE";
  for (unsigned int i = 0; i < theString->length(); i++)
    if (isdigit(theString->at(i)))
      num++;
    else if (isalpha(theString->at(i)))
      alpha++;
  return theString->length();
}

/*
 * Find a word inside of a string.
 * @uses String Member function find()
 * @uses String Member Variable npos
 * @param string *the_string - The string in which the search for a word will
 *                             take place
 * @param string the_word - The word to look for inside of the_string
 * @return bool - True if the_word is found in the_string, else false
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
bool FindWord(string *the_string, string the_word) {
  bool found_word_ = false;
  if (the_string == 0)
    throw "NULL STRING REFERENCE";
    std::size_t found = (the_string->find(the_word));
    if (found == string::npos)
    return false;
  else
    found_word_ = true;
    return found_word_;
}

/*
 * Replace one word in a string with another word.
 * @uses String Member Function find()
 * @uses String Member Function replace()
 * @param string *the_string -  The string that will have a word replaced
 * @param string old_word  - The word inside of the_string being replaced
 * @param string new_word - The word that will be used to replace old_word in
 *                          the_string
 * @return bool - True if old_word was found and replaced, else return false
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
bool ReplaceWord(string* the_string, string old_word, string new_word) {
  if (FindWord(the_string, old_word)) {
  the_string->replace(the_string->find(old_word), old_word.length(), new_word);
  return true;
  } else {
      return false;
  }
}

// CODE HERE -- FUNCTION DEFINITION

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  string* my_string = 0;
  unsigned int alpha, num;

  try {
    CountChars(my_string, alpha, num);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL STRING REFERENCE"),
         "CountChars() EXCEPTION HANDLING");
  }

  try {
    FindWord(my_string, "hello");
  } catch (const char* e) {
    Test(!strcmp(e, "NULL STRING REFERENCE"), "FindWord() EXCEPTION HANDLING");
  }

  try {
    ReplaceWord(my_string, "hello", "goodbye");
  } catch (const char* e) {
    Test(!strcmp(e, "NULL STRING REFERENCE"),
         "ReplaceWord() EXCEPTION HANDLING");
  }

  my_string = MakeDynoString("123, abc; 456: hello. 0!");
  Test(my_string != NULL, "MakeDynoString(\"123, abc; 456: hello. 0!\")");
  Test(CountChars(my_string, alpha, num) == 24, "CountChars() for Length");
  Test(alpha == 8, "CountChars() for Alpha");
  Test(num == 7, "CountChars() for Numeric");

  Test(FindWord(my_string, "HELLO") == false, "FindWord(\"HELLO\")");
  Test(FindWord(my_string, "abc") == true, "FindWord(\"abc\")");

  ReplaceWord(my_string, "hello", "goodbye");

  Test(*my_string == "123, abc; 456: goodbye. 0!",
       "ReplaceWord(my_string, \"hello\", \"goodbye\")");
  Test(ReplaceWord(my_string, "HELLO", "GOODBYE") == false,
       "ReplaceWord(my_string, \"HELLO\", \"GOODBYE\")");

  ClearDynoString(my_string);
  Test(my_string == NULL, "ClearDynoString(my_string");
}
// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << test_number << " " << more_info << "!\n";
  test_number++;
}
