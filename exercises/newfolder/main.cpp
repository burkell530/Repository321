/*
*Name       : Lab1.cpp
*Author     : Lauri Burke
*Description: Lab to practice functions and algorithms
*Sources    :
*videos by TheNewBoston, online learning
*videos on YouTube.com by LetsLearnC++
*Instructor Luke Sathrum
*Absolute C++ by Savitch
*worldsbestlearningcenter.com
*cplusplus.com
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cctype>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void CountCharacters(string string_to_be_counted, int &num_alpha,
                     int &num_digit);
string UpAndDown(string string_caps_and_lowercase);
string ToLower(string string_caps_and_lowercase);
int CountWords(string user_string);
int Average(int num_array[], int size);
int Minimum(int num_array[], int size);
int Maximum(int num_array[], int size);

void UnitTest();
void Test(bool test, string more_info = "");

int main() {
  UnitTest();
return 0;
}
// Function to count the number of alphabetic
// characters and the number of numeric characters in a string
void CountCharacters(string string_to_be_counted,
                     int &num_alpha, int &num_digit) {
  num_alpha = 0;
  num_digit = 0;
  for (unsigned int i = 0; i < string_to_be_counted.length(); i++) {
    if (isalpha(string_to_be_counted[i]))
      num_alpha++;
    else if (isdigit(string_to_be_counted[i]))
      num_digit++;
  }
}
/* Function to take a string and return a version of it where the first
letter is capitalized, the second is lowercase, the third is capitalized,
and so on.
*/
string UpAndDown(string string_caps_and_lowercase) {
  string_caps_and_lowercase = ToLower(string_caps_and_lowercase);
  for (unsigned int i = 0; i < string_caps_and_lowercase.length(); i += 2) {
    string_caps_and_lowercase.at(i)
     = toupper(string_caps_and_lowercase.at(i));
  }
  return string_caps_and_lowercase;
}
// Function to set alphabetic case to lower.
string ToLower(string string_caps_and_lowercase) {
  for (unsigned int i = 0; i < string_caps_and_lowercase.length(); i++) {
    string_caps_and_lowercase.at(i) = tolower(string_caps_and_lowercase.at(i));
  }
  return string_caps_and_lowercase;
}
/*
Function to take a string of words, delimited by a space character,
and count how many words there are.
*/
int CountWords(string user_string) {
    if (user_string.empty())
      return 0;
    int count = 1;
    for (unsigned int i = 0; i < user_string.length(); i++)
        if (user_string[i] == ' ')
            count++;
    return count;
}
// Function to compute the mean average of the values in the array.
int Average(int num_array[], int size) {
  int sum = 0;
  int average;
  for (int i = 0; i < size; i++) {
    sum += num_array[i];
  }
  average = (sum / size);
  return average;
}

// Function to find and return the smallest value in an array.
int Minimum(int num_array[], int size) {
  int minimum = num_array[0];
    for (int i = 1; i < size; i++) {
      if (num_array[i] < minimum)
        minimum += num_array[i];
    }
  return minimum;
}
// Function to find and return the largest value in an array.
int Maximum(int num_array[], int size) {
  int maximum = num_array[0];
    for (int i = 1; i < size; i++) {
      if (num_array[i] > maximum)
       maximum = num_array[i];
  }
  return maximum;
}
// Function Definitions
void UnitTest() {
  cout << "\nSTARTING UNIT TEST\n\n";
  int n1 = 0, n2 = 0;
  CountCharacters("", n1, n2);
  Test((n1 == 0) && (n2 == 0), "CountCharacters(empty string)");
  CountCharacters("hello", n1, n2);
  Test((n1 == 5) && (n2 == 0), "CountCharacters(\"hello\")");
  CountCharacters("12345", n1, n2);
  Test((n1 == 0) && (n2 == 5), "CountCharacters(\"12345\")");
  CountCharacters("hello 12345", n1, n2);
  Test((n1 == 5) && (n2 == 5), "CountCharacters(\"hello 12345\")");
  CountCharacters("&,.", n1, n2);
  Test((n1 == 0) && (n2 == 0), "CountCharacters(\"&,.\")");
  string s;
  s = UpAndDown("hello");
  Test(s == "HeLlO", "UpAndDown(\"hello\")");
  s = UpAndDown("HeLlO");
  Test(s == "HeLlO", "UpAndDown(\"HeLlO\")");
  s = UpAndDown("hElLo");
  Test(s == "HeLlO", "UpAndDown(\"hElLo\")");
  s = UpAndDown("");
  Test(s == "", "UpAndDown(\"\")");
  s = UpAndDown("a");
  Test(s == "A", "UpAndDown(\"a\")");
  Test(CountWords("") == 0, "CountWords(\"\")");
  Test(CountWords("hello") == 1, "CountWords(\"hello\")");
  Test(CountWords("hello,world") == 1, "CountWords(\"hello world\")");
  Test(CountWords("hello world") == 2, "CountWords(\"hello world\")");
  Test(CountWords("hello, world") == 2, "CountWords(\"hello, world\")");

  int values[] = { 10, 20, 30 };
  Test(Average(values, 3) == 20, "Average([10,20,30])");
  values[0] = 0, values[1] = 0, values[2] = 0;
  Test(Average(values, 3) == 0, "Average([0,0,0])");
  values[0] = 5, values[1] = 7, values[2] = 11;
  Test(Average(values, 3) == 7, "Average([5,7,11])");
  values[0] = -10, values[1] = -20, values[2] = -30;
  Test(Average(values, 3) == -20, "Average([-10,-20,-30])");
  values[0] = -5, values[1] = 0, values[2] = 5;
  Test(Average(values, 3) == 0, "Average([-5,0,5])");
  values[0] = -1, values[1] = 0, values[2] = 1;
  Test(Minimum(values, 3) == -1, "FindMinValue([-1,0,1])");
  values[0] = -3, values[1] = -2, values[2] = -1;
  Test(Minimum(values, 3) == -3, "FindMinValue([-3,-2,-1])");
  values[0] = 0, values[1] = 1, values[2] = 2;
  Test(Minimum(values, 3) == 0, "FindMinValue([0,1,2])");
  values[0] = 1, values[1] = 1, values[2] = 1;
  Test(Minimum(values, 3) == 1, "FindMinValue([1,1,1])");
  values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
  Test(Minimum(values, 3) == INT_MAX,
       "FindMinValue([INT_MAX,INT_MAX,INT_MAX])");
  values[0] = -1, values[1] = 0, values[2] = 1;
  Test(Maximum(values, 3) == 1, "FindMaxValue([-1,0,1])");
  values[0] = -3, values[1] = -2, values[2] = -1;
  Test(Maximum(values, 3) == -1, "FindMaxValue([-3,-2,-1])");
  values[0] = 0, values[1] = 1, values[2] = 2;
  Test(Maximum(values, 3) == 2, "FindMaxValue([0,1,2])");
  values[0] = 1, values[1] = 1, values[2] = 1;
  Test(Maximum(values, 3) == 1, "FindMaxValue([1,1,1])");
  values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
  Test(Maximum(values, 3) == INT_MIN,
       "FindMaxValue([INT_MIN,INT_MIN,INT_MIN])");

  cout << "\nUNIT TEST COMPLETE\n\n";
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


