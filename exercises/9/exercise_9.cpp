/*
 * Name        : exercise_9.cpp
 * Author      : FILL IN
 * Description : Working with Classes
 */
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Class Spaceship.
 * A class to model a simple spaceship for a science fiction
 * game or story.
 */
class Spaceship {
 public:
  /*
   * Set the name of this Spaceship.
   * @param string name - The name for this Spaceship
   */
  void set_name(string name);

  /*
   * Set the top speed of this Spaceship.
   * @param double top_speed - The top speed for this Spaceship in warp
   */
  void set_top_speed(double top_speed);

  /*
   * Set the fuel source of this Spaceship.
   * @param string fuel_source - A fuel source for this Spaceship
   */
  void set_fuel_source(string fuel_source);

  /*
   * Set the crew capacity of this Spaceship.
   * @param int crew_capacity - A crew capacity for this Spaceship
   */
  void set_crew_capacity(int crew_capacity);

  /*
   * Get the name of this Spaceship.
   * @return string - The name of this Spaceship
   */
  string name() const;

  /*
   * Get the top speed of this Spaceship.
   * @return double - The top speed of this Spaceship
   */
  double top_speed() const;

  /*
   * Get the fuel source of this Spaceship.
   * @return string - The fuel source of this Spaceship
   */
  string fuel_source() const;

  /*
   * Get the crew capacity of this Spaceship.
   * @return int - The crew capacity of this Spaceship
   */
  int crew_capacity() const;

  /*
   * Get a string representation of this Spaceship's specifications.
   * The string will be formatted as
   * "NAME\n
   *  Top Speed:     Warp TOP_SPEED\n
   *  Fuel Source:   FUEL_SOURCE\n
   *  Crew Capacity: CREW_CAPACITY"
   * where NAME, TOP_SPEED (to two decimal places), FUEL_SOURCE, and
   * CREW_CAPACITY contain the values of the associated member variables.
   * @uses stringstream
   * @return string - A representation of this Spaceship's specifications
   */
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
