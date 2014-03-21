/*
 * Name        : exercise_9.cpp
 * Author      : Lauri Burke
 * Description : Working with Classes
 */
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


// Class Spaceship
class Spaceship {
 public:
  // Sets the name of the spaceship
  void set_name(string name);

  // Sets the speed of the spaceship
  void set_top_speed(double top_speed);

  // Sets the fuel source of the spaceship
  void set_fuel_source(string fuel_source);


  // Sets the crew capacity of the spaceship
  void set_crew_capacity(int crew_capacity);
  // Gets the name of the spaceship
  string name() const;

  // Gets the top speed of the spaceship
  double top_speed() const;

  // Gets the fuel source for the spaceship
  string fuel_source() const;

  // Gets the crew capacity for the spaceship
  int crew_capacity() const;

  // Gets a string representation, formatted, of the spaceship
  string ToString() const;

 private:
  string name_;
  float top_speed_;
  string fuel_source_;
  int crew_capacity_;
};

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest(int argc, char *argv[]);

// Program Execution Starts Here
int main(int argc, char* argv[]) {
  // To test your code (DO NOT ALTER)
  UnitTest(argc, argv);
  // This ends program execution
  return 0;
}


void Spaceship::set_name(string name) {
  name_ = name;
}
void Spaceship::set_top_speed(double top_speed) {
  top_speed_ = top_speed;
}
void Spaceship::set_fuel_source(string fuel_source) {
  fuel_source_ = fuel_source;
}
void Spaceship::set_crew_capacity(int crew_capacity) {
  crew_capacity_ = crew_capacity;
}
string Spaceship::name() const {
  return name_;
}
double Spaceship::top_speed() const {
  return top_speed_;
}
string Spaceship::fuel_source() const {
  return fuel_source_;
}
int Spaceship::crew_capacity() const {
  return crew_capacity_;
}
string Spaceship::ToString() const {
  stringstream ss;
  ss.setf(std::ios::left|std::ios::fixed|std::ios::showpoint);
  ss << name_ << "\n" << std::setw(15) << "Top Speed:"
  << "Warp " << std::setprecision(2) << top_speed_ << "\n"
  << std::setw(15) << "Fuel Source:" << fuel_source_<< "\n"
  << std::setw(15) << "Crew Capacity:" << crew_capacity_;
  return ss.str();
}
// CODE HERE -- CLASS DEFINITION

// For testing (DO NOT ALTER)
void UnitTest(int argc, char *argv[]) {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  Spaceship enterprise;

  enterprise.set_name("USS Enterprise-D");
  Test(enterprise.name() == "USS Enterprise-D", "set_name()/name()");

  enterprise.set_top_speed(9.6);
  Test(enterprise.top_speed() >= 9.59 && enterprise.top_speed() <= 9.61,
       "set_top_speed()/top_speed()");

  enterprise.set_fuel_source("Plasma");
  Test(enterprise.fuel_source() == "Plasma", "set_fuel_source()/fuel_source()");

  enterprise.set_crew_capacity(5000);
  Test(enterprise.crew_capacity() == 5000,
       "set_crew_capacity()/crew_capacity()");

  Test(enterprise.ToString() == "USS Enterprise-D\n"
                                "Top Speed:     Warp 9.60\n"
                                "Fuel Source:   Plasma\n"
                                "Crew Capacity: 5000",
      "ToString()");
  cout << "\n\n" << enterprise.ToString();
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
