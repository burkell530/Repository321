#include "todo_ui.h"
#include "todo_list.h"

// Constructor definition, initializes an instance of TodoList.
TodoUI::TodoUI() {
  todo_list_ = new TodoList;
}

// Destructor definition, deletes the todo list.
TodoUI::~TodoUI() {
  delete todo_list_;
}

// Function to interact with the user.
void TodoUI::Menu() {
  bool quit = false;
  while (quit == false) {
  cout << endl << endl << endl << endl;
  cout << "This is a program that will build a To-do list for you " << endl
  << endl
  << "Here are the choices to choose from: " << endl << endl
  << "1. Create new item \n"
  << "2. Edit item \n"
  << "3. Delete an item \n"
  << "4. View all items \n"
  << "5. View a specific item \n"
  << "6. Delete all items \n"
  << "0. Quit Program \n" << endl << endl;
  cout << "Please make a choice and enter the number: " << endl << endl;
  int userInt;
  userInt = reader.readInt(0, 6);
  cout << "Your choice was: " << userInt << endl << endl;

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

// Function deletes an item chosen by the user. 
void TodoUI::DeleteItem() {
  if (todo_list_->GetSize() == 0) {
     cout << "There are no items there " << endl << endl;
  } else {
    ViewAllItems();
    cout << "Please choose an item to delete from the list above: " << endl
      << endl;
    int user_option = reader.readInt(1, todo_list_->GetSize());
    cout << "You chose " << user_option << endl << endl;
    todo_list_->DeleteItem(user_option);
    cout << "Item deleted! " << endl << endl;
  }
}

// Function creates an item with the specifications given by the user. 
void TodoUI::CreateItem() {
  cout << "Please enter a description for the item \n";
  string user_string = reader.readString();
  if (user_string == "") {
    cout << "Your description was empty " << endl << endl;
    CreateItem();
  }
  cout << "Your description read: " << user_string << endl << endl;
  cout << "Please enter a priority for the item 1 through 5 " << endl;
  int user_priority = reader.readInt(1, 5);
  cout << "You chose " << user_priority << endl << endl;
  cout << "Please enter T for true, if the item is completed, or F for false "
    << "if it is not completed " << endl << endl;
  bool user_complete_status = reader.readBool();
  if (user_complete_status == 1) {
    cout << "You chose True" << endl << endl;
  } else {
    cout << "You chose False" << endl << endl;
  }
  TodoItem* newItem =
    new TodoItem(user_string, user_priority, user_complete_status);
  todo_list_->AddItem(newItem);
}

// Function allows the user to edit an item by changing the description, the 
// priority or the completed status. 
void TodoUI::EditItem() {
  if (todo_list_->GetSize() == 0) {
    cout << "There are no items there " << endl << endl;
  } else {
    ViewAllItems();

    cout << "Please choose an item to edit: " << endl << endl;
    int user_item_choice = reader.readInt(1, todo_list_->GetSize());
    cout << "You chose item: " << user_item_choice << endl << endl;
    cout << "From the following menu please choose an option to edit: " << endl;
    cout << "1. Edit the description of the item " << endl
         << "2. Edit the priority of the item " << endl
         << "3. Edit the completion status of the item " << endl
         << "0. Return to the main menu " << endl;

    cout << "Your choice was: " << endl << endl;
    int user_modifier_choice = reader.readInt(0, 3);

    TodoItem* const theCurrentItem = todo_list_->GetItem(user_item_choice);

    switch (user_modifier_choice) {
      case 1: {
        cout << "Please enter the a new description for the item: " << endl
          << endl;
        string temp_description = reader.readString();
        theCurrentItem->set_description(temp_description);
        cout << "Your description has been reset " << endl << endl;
        break;
      }
      case 2: {
        cout << "Please enter a priority 1 - 5 for your item: " << endl << endl;
        int temp_priority = reader.readInt(1, 5);
        theCurrentItem->set_priority(temp_priority);
        cout << "The priority of your item has been reset " << endl << endl;
        break;
      }
      case 3: {
        cout << "Please enter the new status of your item. Enter true if the "
          << "item has been completed, false if it has not. " << endl << endl;
        bool temp_completed = reader.readBool();
        theCurrentItem->set_completed(temp_completed);
        cout << "The status of your item has been updated " << endl << endl;
        break;
      }
      case 0: {
        Menu();
        break;
      }
    }
  }
}

// Function creates a list of all the items and displays it. 
void TodoUI::ViewAllItems() {
  if (todo_list_->GetSize() == 0) {
    cout << "There is nothing there " << endl << endl;
  } else {
    for (unsigned int i = 1; i <= todo_list_->GetSize(); i++) {
      TodoItem* const theCurrentItem = todo_list_->GetItem(i);
      cout << i << ": " << " Description: " << theCurrentItem->description()
        << endl      << "    Priority: " << theCurrentItem->priority() << endl;
      if (theCurrentItem->completed() == 1) {
        cout         << "    Item is completed " << endl;
      } else {
        cout         << "    Item is not completed " << endl;
      }
    }
  }
}

// Function prints a single item chosen by the user.
void TodoUI::ViewSpecificItem() {
  if (todo_list_->GetSize() == 0) {
    cout << "There are no items there " << endl << endl;
    Menu();
  } else {
    ViewAllItems();
    cout << "Please enter choice from the menu above: " << endl << endl;
    int user_int = reader.readInt(1, todo_list_->GetSize());
    TodoItem* const theCurrentItem = todo_list_->GetItem(user_int);
    cout << *theCurrentItem << endl;
  }
}

// Function to delete all the items.
void TodoUI::DeleteAllItems() {
  todo_list_->FreeList();
  todo_list_->Initialize(25);
  cout << "Items deleted " << endl;
}

