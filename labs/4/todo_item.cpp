#include "todo_item.h"

// Declaration of constructor, initializing description_
// priority_ and completed_.
TodoItem::TodoItem(string description, int priority, bool completed) {
  description_ = description;
  priority_ = priority;
  completed_ = completed;
}

// Empty destructor.
TodoItem::~TodoItem() {
}

// Function returns a string containing the description,
// priority and eompoleted status separated by the @ symbol. Uses the Scrub
// function to change @ symbols in the description.
string TodoItem::ToFile() {
  stringstream ss;
  string converted_string;
  string scrubbed_string;
  ss << Scrub(description_) << '@' << priority_ << '@' << completed_;
  return ss.str();
}

// Funtion to set the member variable to the incoming parameter.
void TodoItem::set_description(string description) {
  description_ = description;
}

// Function to set the priority of the item. Checks to be sure entry is
// within acceptable parameters. 
void TodoItem::set_priority(int priority) {
  if (priority > 5 || priority < 1) {
    priority = 5;
  }
  priority_ = priority;
}

// Function to set the member variable completed_ to the incoming
// parameter.
void TodoItem::set_completed(bool completed) {
  completed_ = completed;
}

// Function returns description_.
string TodoItem::description() const {
  return description_;
}

// Function returns priority_.
int TodoItem::priority() const {
  return priority_;
}

// Function returns completed_. 
bool TodoItem::completed() const {
  return completed_;
}

// Function outputs in a nice looking way all of the information
// about the item. 
ostream& operator << (ostream &out, const TodoItem &item_to_write) {
  out  << "Description: " << item_to_write.description_ << endl
  << "    Priority: " << item_to_write.priority_ << endl
  << "    Completion Status: " << item_to_write.completed_;
  return out;
}

// Function replaces all '@' symbols with # symbols and returns the
// modified string. 
string TodoItem::Scrub(string in_string_w_symbols) {
  replace(in_string_w_symbols.begin(), in_string_w_symbols.end(), '@', '#');
  return in_string_w_symbols;
}

