#include "todo_ui.h"
#include "todo_list.h"
// Constructor definition
TodoUI::TodoUI() {
  todo_list_ = new TodoList;
  // make an initializer like in todolist?
}

// Destructor definition
TodoUI::~TodoUI() {
  delete todo_list_;
}

// Function to interact with the user.
void TodoUI::Menu() {
  bool quit = false;
  while (quit == false) {
  cout << "This is a program that will build a To-do list for you \n"
  << "Here are the choices to choose from: \n"
  << "1. Create new item \n"
  << "2. Edit item \n"
  << "3. Delete an item \n"
  << "4. View all items \n"
  << "5. View a specific item \n"
  << "6. Delete all items \n"
  << "0. Quit Program \n";
  cout << "Please make a choice and enter the number: " << endl;
  int userInt;
  userInt = reader.readInt(0, 6);
  cout << "Your choice was: " << userInt << endl;
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
    cout << "Please choose an item to delete from above \n";
    int user_option = reader.readInt(0, todo_list_->GetSize());
    todo_list_->DeleteItem(user_option);
    cout << "Item deleted \n";

}

void TodoUI::CreateItem() {

  cout << "Please enter a description for the item \n";
  string user_string = reader.readString();
  if (user_string == "") {
    cout << "Your description was empty " << endl;
    CreateItem();
  }
  cout << "Your description read: " << user_string << endl;
  cout << "Please enter a priority for the item 1 through 5 " << endl;
  int user_priority = reader.readInt(1, 5);
  cout << "You chose " << user_priority << endl;
  cout << "Please enter T for true, if the item is completed, or F for false "
    << "if it is not completed " << endl;
  bool user_complete_status = reader.readBool();
  if (user_complete_status == 1) {
    cout << "You chose True" << endl;
  } else {
    cout << "You chose False" << endl;
  }
  TodoItem* newItem = new TodoItem(user_string, user_priority, user_complete_status);
  todo_list_->AddItem(newItem);
}

void TodoUI::EditItem() {
  if (todo_list_->GetSize() == 0) {
  cout << "There is nothing there " << endl;
  } else {
    ViewAllItems();

    cout << "Please choose an item to edit: ";
    int user_item_choice = reader.readInt(1, todo_list_->GetSize());

    cout << "You chose item: " << user_item_choice << endl << endl;
    cout << "From the following menu please choose an option to edit: " << endl;
    cout << "1. Edit the description of the item "
         << "2. Edit the priority of the item "
         << "3. Edit the completion status of the item "
         << "0. Return to the main menu " << endl;

  cout << "Your choice was: " << endl;
  int user_modifier_choice = reader.readInt(0, 3);

  TodoItem* const theCurrentItem = todo_list_->GetItem(user_item_choice);

  switch (user_modifier_choice) {
    case 1: {
      cout << "Please enter the a new description for the item: " << endl;
      string temp_description = reader.readString();
      theCurrentItem->set_description(temp_description);
      cout << "Your description has been reset " << endl;
      break;
    }
    case 2: {
      cout << "Please enter a priority 1 - 5 for your item: " << endl;
      int temp_priority = reader.readInt(1, 5);
      theCurrentItem->set_priority(temp_priority);
      cout << "The priority of your item has been reset " << endl;
      break;
    }
    case 3: {
      cout << "Please enter the new status of your item. Enter true if the "
        << "item has been completed, false if it has not. " << endl;
      bool temp_completed = reader.readBool();
      theCurrentItem->set_completed(temp_completed);
      cout << "The status of your item has been updated " << endl;
      break;
    }
   }
  }
}

// Outputs a list of all the items in the array.
// uses a for loop, starts at 1 for the viewer.
// While the size of the array + 1 is greater than the iterator,
// print 1: (the_array[i - 1])
void TodoUI::ViewAllItems() {
  if (todo_list_->GetSize() == 0) {
    cout << "There is nothing there " << endl;
  } else {
    cout << "Under View All Items" << endl;
    for(unsigned int i = 1; i < todo_list_->GetSize(); i++) {
      TodoItem* const theCurrentItem = todo_list_->GetItem(i);
      cout << "under pointer" << endl; // execution stops here
      cout << i << ":" << theCurrentItem->description() << endl;
    }
  }
}

// Allows a user to view one specific item in the array.
// Calls the ViewAllItems function, uses user input - 1 to
// access the array index for that item and prints it.
void TodoUI::ViewSpecificItem() {
  ViewAllItems();
  cout << "Please enter number of choice from the menu above: \n";
  int user_int = reader.readInt(1, todo_list_->GetSize());
  TodoItem* const theCurrentItem = todo_list_->GetItem(user_int);
  cout << *theCurrentItem << endl;
}

// function
void TodoUI::DeleteAllItems() {
  todo_list_->FreeList();
}
