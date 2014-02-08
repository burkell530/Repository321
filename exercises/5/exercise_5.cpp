/*
 * Name        : exercise_5.cpp
 * Author      : FILL IN
 * Description : Practicing Functions
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <streambuf>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 * function name: Hello
 * parameters: none
 * default arguments: n/a
 * return type: void
 *
 * Display "Hello world!" to stdout (no newline character after)
 */
// CODE HERE (FUNCTION PROTOTYPE)

/*
 * function name: PrintMessage
 * parameters: string message (const call-by-reference)
 * default arguments: none
 * return type: void
 *
 * Display message to stdout (no newline character after)
 */
// CODE HERE (FUNCTION PROTOTYPE)

/*
 * function name: GetAnswer
 * parameters: none
 * default arguments: n/a
 * return type: int
 *
 * Return the value 42
 */
// CODE HERE (FUNCTION PROTOTYPE)

/*
 * function name: FindLarger
 * parameters: int (const call-by-reference), int (const call-by-reference)
 * default arguments: none
 * return type: int
 *
 * Return the larger of the two parameter values. Should work correctly
 * if the values are equivalent.
 */
// CODE HERE (FUNCTION PROTOTYPE)

/*
 * function name: GetStats
 * parameters: string (const call-by-reference), int (call-by-reference),
 *             int (call-by-reference)
 * default arguments: none
 * return type: int
 *
 * Return the length of string. On return second parameter (int) should contain
 * a count of the number of uppercase characters of first parameter (string),
 * third parameter (int) should contain a count of the number of lowercase
 * characters in the first parameter (string)
 */
// CODE HERE (FUNCTION PROTOTYPE)

/*
 * function name: BuildMessage
 * parameters: string (call-by-value), bool (call-by-value)
 * default arguments: string = "" (empty string), bool = false
 * return type: string
 *
 * Return the string "Message: STRING", where STRING is replaced by the value of
 * the first parameter (string). If second parameter (bool) is true, convert
 * first parameter (string) to all uppercase letters before concatenating it
 * with "Message: ". If first parameter is the empty string, return
 * "Message: empty".
 */
// CODE HERE (FUNCTION PROTOTYPE)


// For testing (DO NOT ALTER)
void UnitTest();
void Test(bool test, string more_info = "");

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE HERE (FUNCTION DEFINITIONS)


// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  std::streambuf* oldCout = cout.rdbuf();
  std::ostringstream captureCout;
  cout.rdbuf(captureCout.rdbuf());
  Hello();
  cout.rdbuf(oldCout);
  Test(captureCout.str() == "Hello world!", "Hello()");
  captureCout.str("");
  cout.rdbuf(captureCout.rdbuf());
  PrintMessage("Hello again!");
  cout.rdbuf(oldCout);
  Test(captureCout.str() == "Hello again!", "PrintMessage(\"Hello again!\")");
  Test(GetAnswer() == 42, "GetAnswer()");
  Test(FindLarger(-1, 1) == 1, "FindLarger(-1, 1)");
  Test(FindLarger(1, -1) == 1, "FindLarger(1, -1)");
  Test(FindLarger(1, 1) == 1, "FindLarger(1, 1)");
  int upper = 0, lower = 0;
  Test(GetStats("abc ABC", upper, lower) == 7 && upper == 3 && lower == 3,
       "GetStats(\"abc 123\", upper, lower)");
  Test(GetStats("abc", upper, lower) == 3 && upper == 0 && lower == 3,
       "GetStats(\"abc\", upper, lower)");
  Test(GetStats("ABC", upper, lower) == 3 && upper == 3 && lower == 0,
       "GetStats(\"ABC\", upper, lower)");
  Test(GetStats("", upper, lower) == 0 && upper == 0 && lower == 0,
       "GetStats(\"\", upper, lower)");
  Test(BuildMessage("hello") == "Message: hello", "BuildMessage(\"hello\")");
  Test(BuildMessage("hello", true) == "Message: HELLO",
       "BuildMessage(\"hello\", true)");
  Test(BuildMessage("HELLO", false) == "Message: HELLO",
       "BuildMessage(\"HELLO\", false)");
  Test(BuildMessage("HELLO", true) == "Message: HELLO",
       "BuildMessage(\"HELLO\", true)");
  Test(BuildMessage() == "Message: empty", "BuildMessage()");
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
