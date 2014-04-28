/*
 * Name        : exercise_22.cpp
 * Author      : Luke Sathrum
 * Description : Recursive Functions
 */

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value an unsigned integer containing the value for which the factorial will be computed
 * @return an unsigned integer containing the computed factorial of the value
 */
unsigned int Factorial(unsigned int value);

/*
 * Return a specified value in a Fibonacci sequence. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue an unsigned integer specifying which value in the Fibonacci sequence to return
 * @return an unsigned integer containing the requested value in the Fibonacci sequence
 */
unsigned int Fibonacci(unsigned int fib_value);

/*
 * Test a single word to see if it is a palindrome. The word must be all in the same case
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word a string containing the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool WordIsPalindrome(string word);

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going forward to the end of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param startIndex an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the array
 */
string ArrayForwardsAsString(int array[], unsigned int start,
                             unsigned int size);

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going backward to the beginning of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param startIndex an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces, in reverse order; returns empty string
 *         if the startIndex is < zero
 */
string ArrayBackwardsAsString(int array[], int start, unsigned int size);

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE FUNCTION DEFINITIONS HERE

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  cout << "Total Number of Test: 18" << endl;
  // Tests

  Test(Factorial(0) == 1, "Factorial(0)");
  Test(Factorial(1) == 1, "Factorial(1)");
  Test(Factorial(2) == 2, "Factorial(2)");
  Test(Factorial(5) == 120, "Factorial(5)");
  Test(Fibonacci(1) == 1, "Fibonacci(1)");
  Test(Fibonacci(2) == 1, "Fibonacci(2)");
  Test(Fibonacci(3) == 2, "Fibonacci(3)");
  Test(Fibonacci(15) == 610, "Fibonacci(610)");
  Test(WordIsPalindrome("") == true, "WordIsPalindrome(\"\")");
  Test(WordIsPalindrome("a") == true, "WordIsPalindrome(\"a\")");
  Test(WordIsPalindrome("sitonapotatopanotis") == true,
       "WordIsPalindrome(\"sitonapotatopanotis\")");
  Test(WordIsPalindrome("baseball") == false, "WordIsPalindrome(\"baseball\")");

  int numbers[5] = { 5, 10, 15, 20, 25 };
  Test(ArrayForwardsAsString(numbers, 0, 5) == "5 10 15 20 25 ",
       "ArrayForwardsAsString(numbers, 0, 5)");
  Test(ArrayForwardsAsString(numbers, 3, 5) == "20 25 ",
       "ArrayForwardsAsString(numbers, 3, 5)");
  Test(ArrayForwardsAsString(numbers, 5, 5) == "",
       "ArrayForwardsAsString(numbers, 5, 5)");
  Test(ArrayBackwardsAsString(numbers, 4, 5) == "25 20 15 10 5 ",
       "ArrayBackwardsAsString(numbers, 4, 5)");
  Test(ArrayBackwardsAsString(numbers, 1, 5) == "10 5 ",
       "ArrayBackwardsAsString(numbers, 1, 5)");
  Test(ArrayBackwardsAsString(numbers, -1, 5) == "",
       "ArrayBackwardsAsString(numbers, -1, 5)");

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n" << "Passed: " << ut_passed << " / "
       << ut_total << endl << "Failed: " << ut_failed << " / " << ut_total
       << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test) {
    cout << "PASSSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED  TEST ";
    ut_failed++;
  }
  cout << test_number << " " << more_info << "!" << endl;
  test_number++;
  ut_total++;
}
