/*
 * Name        : exercise_5.cpp
 * Author      : Lauri Burke
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

void Hello();
void PrintMessage(const string &message);
int GetAnswer();
int FindLarger (const int &kvalue1, const int &kvalue2);
int GetStats (const string &kstat1, int &kstat2,  int &kstat3);
string BuildMessage (const string &kmessage = "", const bool &kevaluate = false);

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
 //void function to print "Hello World!".
void Hello() {
  cout << "Hello world!";
}
//void function to print a string named message.
void PrintMessage(const string &message) {
  cout << message;
}
//function to return the integer 42
int GetAnswer() {
  return 42;
}
//function to return the larger of two parameter values.
int FindLarger (const int &kvalue1, const int &kvalue2) {
  if (kvalue1 > kvalue2)
    return kvalue1;
  else
    return kvalue2;
  }
/*function to return the length of a string containing a count of the number of
  uppercase characters of the first parameter. The third parameter to contain a
 count of the number of lowercase characters in the first parameter string.
*/
int GetStats (const string &kstat1, int &kstat2, int &kstat3) {
    kstat2 = 0;
    kstat3 = 0;
  
  for (unsigned int i = 0; i <= kstat1.length(); i++) {
  if (isalpha(kstat1[i])) {
  if (isupper(kstat1[i]))
      kstat2 += 1;
     else 
      kstat3 += 1;
    }
  }
  return kstat1.length();
}
/*function to return the string "Message: STRING, where STRING is replaced by 
  the value of the first parameter (string) If second parameter (bool) is true, 
  convert first parameter (string) to all uppercase letters before concatenating
  it with "Message: ". If first parameter is the empty string, return "Message:
  empty".
*/
string BuildMessage (const string &kmessage, const bool &kevaluate) {
std::stringstream ss;
string copy = kmessage;
  if (kmessage == "")
    return "Message: empty";
  if (kevaluate == true) {
    for (unsigned int i = 0; i < kmessage.length(); i++) {
     copy[i] = toupper(kmessage[i]);
    }
    ss << "Message: " << copy;
    return ss.str();
  }//end of else if
  else {
    ss << "message: " << kmessage;
    return ss.str();
  }
}
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
