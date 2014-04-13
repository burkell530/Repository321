/*
* Lauri Burke
* Lab 4, todo_item.h
* March 28, 2014
*/

#ifndef BURKE_TODOITEM_H_
#define BURKE_TODOITEM_H_

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;
using std::stringstream;

class TodoItem;
ostream& operator << (ostream &out, const TodoItem &item_to_write);
// class definition:
class TodoItem {
 public:
  // Destructor
  ~TodoItem();

  // constructor:
  TodoItem(string description, int priority = 1, bool completed = false);

  // Returns a string with description, priority,
  // and completed status.
  string ToFile();

  // Mutators:
  void set_description(string description);
  void set_priority(int priority);
  void set_completed(bool completed);

  // Accessors:
  string description() const;
  int priority() const;
  bool completed() const;

  // Friend functions:
  friend ostream& operator << (ostream &out, const TodoItem &item_to_write);

 private:
  // Replaces '@' with '#' and returns modified string
  string Scrub(string in_string_w_symbols);

  // Private member variables:
  string description_;
  int priority_;
  bool completed_;
};

#endif /* BURKE_TODOITEM_H_ */
