/*
 * Name        : exercise_10.cpp
 * Author      : Luke Sathrum
 * Description : Unit_Test to test your class.
 */
#include <iostream>
#include "temperature.h"
using std::cout;
using std::endl;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();

// Program Execution Starts Here
int main(int argc, char* argv[]) {
  // To help test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  Temperature temp1;
  Test(temp1.GetTempAsKelvin() == 0, "Default Constructor / GetTempAsKelvin()");
  temp1.SetTempFromKelvin(50);
  Test(temp1.GetTempAsKelvin() == 50,
       "SetTempFromKelvin(50) / GetTempAsCelsius()");
  temp1.SetTempFromCelsius(5);
  Test(
      temp1.GetTempAsFahrenheit() >= 40.99
          && temp1.GetTempAsFahrenheit() <= 41.01,
      "SetTempFromCelsius(5) / GetTempAsFarenheit()");
  temp1.SetTempFromFahrenheit(5);
  Test(temp1.GetTempAsKelvin() >= 258.149 && temp1.GetTempAsKelvin() <= 258.151,
       "SetTempFromFahrenheit(5) / GetTempAsKelvin()");
  Test(temp1.ToString() == "258.15 Kelvin", "ToString()");

  Temperature temp2(50);
  Test(
      temp2.GetTempAsFahrenheit() >= -369.68
          && temp2.GetTempAsFahrenheit() <= -369.66,
      "Constructor(50) / GetTempAsFahrenheit()");
  Test(temp2.ToString('C') == "-223.15 Celsius", "ToString('C')");
  Temperature temp3(5, 'F');
  Test(
      temp3.GetTempAsKelvin() >= 258.14
          && temp3.GetTempAsFahrenheit() <= 258.16,
      "Constructor(5, 'F') / GetTempAsKelvin()");
  Temperature temp4(5, 'f');
  Test(
      temp4.GetTempAsKelvin() >= 258.14
          && temp4.GetTempAsFahrenheit() <= 258.16,
      "Constructor(5, 'f') / GetTempAsKelvin()");
  Temperature temp5(5, 'C');
  Test(
      temp5.GetTempAsKelvin() >= 278.14
          && temp5.GetTempAsFahrenheit() <= 278.16,
      "Constructor(5, 'C') / GetTempAsKelvin()");
  Temperature temp6(5, 'c');
  Test(
      temp6.GetTempAsKelvin() >= 278.14
          && temp6.GetTempAsFahrenheit() <= 278.16,
      "Constructor(5, 'c') / GetTempAsKelvin()");
  Temperature temp7(5, 'K');
  Test(temp7.GetTempAsKelvin() == 5, "Constructor(5, 'K') / GetTempAsKelvin()");
  Temperature temp8(5, '5');
  Test(temp8.GetTempAsKelvin() == 5, "Constructor(5, '5') / GetTempAsKelvin()");
  Test(temp8.ToString('c') == "-268.15 Celsius", "ToString('c')");
  Test(temp8.ToString('K') == "5 Kelvin", "ToString('K')");
  Test(temp8.ToString('k') == "5 Kelvin", "ToString('k')");
  Test(temp8.ToString('F') == "-450.67 Fahrenheit", "ToString('F')");
  Test(temp8.ToString('f') == "-450.67 Fahrenheit", "ToString('f')");
  Test(temp8.ToString('1') == "Invalid Unit", "ToString('1')");
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
