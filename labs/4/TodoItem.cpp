#include "TodoItem.h"

/* Constructor:
* Has three parameters in the following order and sets those 
* parameters to their corresponding private member variables 
* String for the description 
* Integer for the priority, defaults to 1 
* Boolean for completion status, defaults to false 
*/
// declaration of constructor, initializing 
TodoItem::TodoItem() {
  description_ = ""; // not sure if this is supposed to be empty string
  priority_ = 1;
  bool completed_ = false;
}
// Destructor is empty
TodoItem::~TodoItem(){
    
}

// Public member functions:
string TodoItem::ToFile();

// Accessors:
void TodoItem::SetDescription(string description) {
  description_ = description;
}
void TodoItem::SetPriority(int priority) {
  priority_ = priority;
}
void TodoItem::SetCompleted(bool completed) {
  completed_ = completed;
}

// Mutators:
string TodoItem::GetDescription() const {
  return description_;
}
int TodoItem::GetPriority() const {
  return priority_;
}
bool TodoItem::GetCompleted() const {
  return completed_;
}

// Friend function allows for chaining
ostream& operator << (ostream &out, const TodoItem &amount);//not 'amount' parameter

/*Private member functions:
* ? use .find and .replace from exercise_13.cpp
* takes a string parameter from member function ToFile
* replaces all @ symbols with # symbols in the description
*/
string TodoItem::Scrub(string /* parameter here*/);

