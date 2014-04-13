#include "todo_item.h"

/* Constructor:
* Has three parameters in the following order and sets those
* parameters to their corresponding private member variables
* String for the description
* Integer for the priority, defaults to 1
* Boolean for completion status, defaults to false
*/
// declaration of constructor, initializing
TodoItem::TodoItem(string description, int priority, bool completed) {
  description_ = description;
  priority_ = priority;
  completed_ = completed;
}
// Destructor is empty
TodoItem::~TodoItem() {
}

string TodoItem::ToFile() {
  stringstream ss;
  string converted_string;
  string scrubbed_string;
  ss << Scrub(description_) << '@' << priority_ << '@' << completed_;
  return ss.str();
}

void TodoItem::set_description(string description) {
  description_ = description;
}

void TodoItem::set_priority(int priority) {
  if (priority > 5 || priority < 1) {
    priority = 5;
  }
  priority_ = priority;
}

void TodoItem::set_completed(bool completed) {
  completed_ = completed;
}

string TodoItem::description() const {
  return description_;
}
int TodoItem::priority() const {
  return priority_;
}
bool TodoItem::completed() const {
  return completed_;
}

ostream& operator << (ostream &out, const TodoItem &item_to_write) {
  out  << "Description: " << item_to_write.description_ << endl
  << "    Priority: " << item_to_write.priority_ << endl
  << "    Completion Status: " << item_to_write.completed_;
  return out;
}

// takes a string parameter from member function ToFile
// replaces all @ symbols with # symbols in description_
string TodoItem::Scrub(string in_string_w_symbols) {
  replace(in_string_w_symbols.begin(), in_string_w_symbols.end(), '@', '#');
  return in_string_w_symbols;
}

