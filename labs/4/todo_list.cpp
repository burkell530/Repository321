#include "todo_list.h"

// Constructor initializes the array to 25 elements
// and initializes the elements to NULL.
TodoList::TodoList() {
  Initialize(25);
}

// Destructor definition calls the function FreeList
TodoList::~TodoList() {
  FreeList();
}

// Public member functions
// frees the memory for all TodoItems objects in the_array
// frees the memory for the dynamic TodoItem* array
void TodoList::FreeList() {
  if (the_array !=0) {
    for (unsigned int i = 0; i < m_current_size_of_list; i++) {
      delete the_array[i];
    }
    the_array = NULL;
  }
}

// Returns a string containing all TodoItems in the list.
// Uses the TodoItems ToFile function to create.
string TodoList::ToFile() {
  string longstream = " ";
  stringstream ss;
  for (unsigned int i = 0; i < m_current_size_of_list; i++) {
  ss << the_array[i]->ToFile() << endl;
  }
  longstream = ss.str();
  return longstream;
}

// Function initializes a new dynamic array.
void TodoList::Initialize(unsigned int in__current_number_of_slots_in_list) {
  m_current_number_of_slots_in_list = in__current_number_of_slots_in_list;
  the_array = new TodoItem*[m_current_number_of_slots_in_list];
  m_current_size_of_list = 0;
}

// Function is a dynamic instance of TodoItem. If there is room 
// in the array it will add the new dynamic instance to the first available
// spot. If the array is full it will call the function IncreaseCapacity to 
// add more room to the array. 
void TodoList::AddItem(TodoItem* in_item_to_add) {
  if (m_current_size_of_list >= m_current_number_of_slots_in_list) {
     IncreaseCapacity();
  }
  the_array[m_current_size_of_list] = in_item_to_add;
  m_current_size_of_list++;
}

// Function takes a parameter of the location to delete. This is done
// in human-readable form. After the delete is done, the function 
// ShiftElements is called to compact the array. 
void TodoList::DeleteItem(unsigned int in_location_to_delete) {
  in_location_to_delete--;
  if (in_location_to_delete >= 0
    && in_location_to_delete < m_current_size_of_list) {
     delete the_array[in_location_to_delete];
     ShiftElements(in_location_to_delete);
  }
}

// Function returns the location to retrieve the item from in the array. 
TodoItem* TodoList::GetItem(unsigned int in_location_to_retrive_item_from) {
  return the_array[in_location_to_retrive_item_from - 1];
}

// Function returns the size of the array.
unsigned int TodoList::GetSize() {
    return m_current_size_of_list;
}

// Function returns the capacity of the array. 
unsigned int TodoList::GetCapacity() {
  return m_current_number_of_slots_in_list;
}

// Function uses the bubble sort algorithm to sort the items 
// in the array by priority. 
void TodoList::Sort() {
  for (unsigned int i = m_current_size_of_list - 1; i >= 1; --i) {
    for (unsigned int j = 0; j < i; ++j) {
      if (the_array[j]->priority()
        > the_array[j + 1]->priority()) {
        TodoItem* temp = the_array[j];
        the_array[j] = the_array[j + 1];
        the_array[j + 1] = temp;
      }
    }
  }
}

// Function increases the capacity of the array by 10 when the initial
// 25 slots have been used. 
void TodoList::IncreaseCapacity() {
  m_current_number_of_slots_in_list += 10;
  TodoItem** temp_outside_ptr =
    new TodoItem*[m_current_number_of_slots_in_list];
  for (unsigned int i = 0; i < m_current_size_of_list; i++) {
    temp_outside_ptr[i] = the_array[i];
  }
  delete[] the_array;
  the_array = temp_outside_ptr;
  temp_outside_ptr = NULL;
}

// Function compacts the array after an element has been deleted. 
void TodoList::ShiftElements(unsigned int empty_space_to_fill) {
  for (unsigned int i = empty_space_to_fill; i < m_current_size_of_list; i++) {
    the_array[i] = the_array[i + 1];
  }
  m_current_size_of_list--;
}

// Function outputs a numbered list of all TodoItems present
// on the list. Will use TodoItem overloaded << operator.
ostream& operator << (ostream &out, const TodoList &item_to_write) {
  for (unsigned int i = 0; i < item_to_write.m_current_size_of_list; i++)
    out << i +1 << ". " << *item_to_write.the_array[i] << endl;
    return out;
}
