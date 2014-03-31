#include "TodoItem.cpp"

/* Constructor:
* Has three parameters in the following order and sets those 
* parameters to their corresponding private member variables 
* String for the description 
* Integer for the priority, defaults to 1 
* Boolean for completion status, defaults to false 
*/
TodoItem::TodoItem(); // declaration of constructor:
 
// Destructor is empty
TodoItem::~TodoItem();

// Public member functions:
string TodoItem::ToFile();

// Accessors:
void TodoItem::SetDescription(string description);
void TodoItem::SetPriority(int priority);
void TodoItem::SetCompleted(bool completed);

// Mutators:
string TodoItem::GetDescription() const;
int TodoItem::GetPriority() const;
bool TodoItem::GetCompleted() const;

// Friend function allows for chaining
ostream& operator << (ostream &out, const TodoItem &amount);//not 'amount' parameter

/*Private member functions:
* ? use .find and .replace from exercise_13.cpp
* takes a string parameter from member function ToFile
* replaces all @ symbols with # symbols in the description
*/
string TodoItem::Scrub(string /* parameter here*/);

