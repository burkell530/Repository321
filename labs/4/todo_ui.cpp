#include "todo_ui.h"
// Constructor definition
TodoUI::TodoUI() {
  TodoList = new TodoList;
  // make an initializer like in todolist?
}

// Destructor definition
TodoUI::~TodoUI() {
  delete[] the_array;
}

// Function to interact with the user.
void TodoUI::Menu() {
  bool quit = false;
  while (quit == false) {
  cout << "This is a program that will build a To-do list for you \n"
  << "Here are the choices to choose from: \n"
  << "1. Create new menu item \n"
  << "2. Edit item \n"
  << "3. Delete an item \n"
  << "4. View all items \n"
  << "5. View a specific item \n"
  << "6. Delete all items \n"
  << "0. Quit Program \n";
  cout << "Please make a choice and enter the number: " << endl;
  int userInt;
  userInt = reader.readInt(0, 6);
  cout << "Your choice was; \n";
  switch (userInt) {
    case 1:
      CreateItem();
      break;
    case 2:
      EditItem();
      break;
    case 3: 
      DeleteItem();
      break;
    case 4:
      ViewAllItems();
      break;
    case 5: 
      ViewSpecificItem();
      break;
    case 6:
      DeleteAllItems();
      break;
    case 0:
      quit = true;
      break;
    }
  }
}

void TodoUI::DeleteItem() {
  ViewAllItems();
  cout << "Please choose an option from above \n";
  int user_option;
  user_option = reader.readInt(0, 6);
  delete the_array[user_option - 1];
  cout << "Item deleted \n";
}

void TodoUI::CreateItem() {
  string user_string = "";
  int user_priority = 5;
  bool user_complete_status = false;
  cout << "Please enter a description for the item \n";
  user_string = reader.readString();
  cout << "Please enter a priority for the item 1 through 6, or 0 to quit \n";
  user_priority = reader.readInt(0, 6);
  cout << "Please enter T for true, if the item is completed, or F for false "
    << "if it is not completed " << endl;
  user_complete_status = reader.readBool();
  user_complete_status = (toupper(user_complete_status));
  TodoItem* newItem = new TodoItem(description, priority, completed);
  AddItem(newItem);
}

void TodoUI::EditItem() {
  int user_item_choice = 0;
  int user_modifier_choice = 0;
  ViewAllItems();
  cout << "Please choose an item to edit: ";
  user_item_choice = reader.readInt(0, 6);
  cout << "You chose item: " << user_item_choice << endl << endl;
  cout << "From the following menu please choose an option to edit: " << endl;
  cout << "1. Edit the description of the item "
       << "2. Edit the priority of the item "
       << "3. Edit the completion status of the item " 
       << "0. Return to the main menu " << endl;
  cout << "Your choice was: " << endl;
  user_modifier_choice = reader.readInt(0, 3);
  switch (user_modifier_choice) {
    case 1:
      string temp_description = "";
      cout << "Please enter the a new description for the item: " << endl;
      in_description = reader.readString();
      the_array.GetItem(user_item_choice - 1)->SetDescription(temp_description);
      cout << "Your description has been reset " << endl;
      break;
    case 2:
      int temp_priority = 0;
      cout "Please enter a priority 1 - 5 for your item: " << endl;
      in_priority = reader.readInt(1, 5);
      the_array[user_item_choice - 1]->SetPriority(temp_priority);
      cout << "The priority of your item has been reset " << endl;
      break;
    case 3: 
      bool in_completed = false;
      cout << "Please enter the new status of your item. Enter true if the "
        << "item has been completed, false if it has not. " << endl;
      in_completed = reader.readBool();
      the_array[user_item_choice - 1]->SetCompleted(in_completed);
      cout << "The status of your item has been updated " << endl;
      break;
}

// Outputs a list of all the items in the array.
// uses a for loop, starts at 1 for the viewer.
// While the size of the array + 1 is greater than the iterator, 
// print 1: (the_array[i - 1])
void TodoUI::ViewAllItems() {
  for(unsigned int i = 1; i < (GetSize() + 1); i++) {
    cout << i << ":" << the_array[i - 1]->GetItem() << endl;
  }
}

// Allows a user to view one specific item in the array.
// Calls the ViewAllItems function, uses user input - 1 to 
// access the array index for that item and prints it. 
void TodoUI::ViewSpecificItem() {
  ViewAllItems();
  int user_int;
  cout << "Please enter number of choice from the menu above: \n";
  user_int = reader.readInt(1, (GetSize()+1);
  user_int = user_int - 1;
  cout << GetItem(user_int) << end;
}

// function 
void TodoUI::DeleteAllItems() {
  Freelist();
}
