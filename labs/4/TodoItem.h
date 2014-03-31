/*
* Lauri Burke
* Lab 4, TodoItem.h
* March 28, 2014
*/
//include guards
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
ostream& operator << (ostream &out, const TodoItem &amount);
// class definition:
class TodoItem {
public:
// Destructor
~TodoItem();
  // constructor:
  TodoItem (); // declaration of constructor:
  // Public member functions:
  string ToFile();
  // Accessors:
  void SetDescription(string description);
  void SetPriority(int priority);
  void SetCompleted(bool completed);
  // Mutators:
  string GetDescription() const;
  int GetPriority() const;
  bool GetCompleted() const;
  // Friend functions:
  //Overloaded friend function here operator << 
  friend ostream& operator << (ostream &out, const TodoItem &amount);
  
private:
  // Private member functions:
  string Scrub(string /* parameter here*/);
  // Private member varables:
  string description_;
  int priority_;
  bool completed_;
};

