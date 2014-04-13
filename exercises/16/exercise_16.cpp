/*
 * Name        : exercise_16.cpp
 * Author      : Lauri Burke
 * Description : Working with a Dynamic Array in a Class
 */
#include <iostream>
#include <string>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class ShoppingList {
 public:
  ShoppingList();
  ShoppingList(unsigned int max_items);
  ~ShoppingList();
  unsigned int max_items() const;
  unsigned int item_count() const;
  bool AddItem(string item);
  string GetItem(unsigned int index) const;
  string& GetItem(unsigned int index);
  void Reset(unsigned int max_items);

 private:
  void Initialize(unsigned int inCapacity);
  void FreeList();
  string* mItemsArray;
  unsigned int mListCapacity;
  unsigned int mNumberOfItemsOnList;
};

// For testing (DO NOT ALTER)
void UnitTest(int test);
void Test(bool test, string more_info = "");

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  int choice;
  cout << "0 to test without Assertions\n"
       << "All other tests below should break on an Assertion\n"
       << "1 - GetItem(0) from an empty list\n"
       << "2 - GetItem(26) from size 25 list\n"
       << "3 - GetItem(0) = \"oranges\" on an empty list\n"
       << "4 - GetItem(1) from a list of size 1\n" << "5 - Reset(0)\n"
       << "6 - GetItem(6) from size 5 list\n" << "Choice: ";
  cin >> choice;
  cout << endl;
  UnitTest(choice);
  // This ends program execution
  return 0;
}
void ShoppingList::Initialize(unsigned int inCapacity) {
  mListCapacity = inCapacity;
  mItemsArray = new string[mListCapacity];
  mNumberOfItemsOnList = 0;
}

  /*
   * Default constructor.
   * Initializes mListCapacity to 25, mItemsArray to size mListCapacity
   * and mNumberOfItemsOnList to 0.
   */
ShoppingList::ShoppingList() {
  Initialize(25);
}

void ShoppingList::FreeList() {
  if (mItemsArray != 0) {
    mItemsArray = 0;
  }
}

void ShoppingList::Reset(unsigned int inCapacityOfList) {
  FreeList();
  Initialize(inCapacityOfList);
}

  /*
   * Overloaded constructor.
   * Initializes mListCapacity to max_items, mItemsArray to size max_items
   * and item_count to 0.
   * @param unsigned int max_items - The desired size of the mItemsArray array
   */
ShoppingList::ShoppingList(unsigned int inCapacityOfList) {
  Initialize(inCapacityOfList);
}

  /*
   * Destructor.
   * Frees the memory associated with mItemsArray.
   */
ShoppingList::~ShoppingList() {
  FreeList();
}

  /*
   * Accessor for mListCapacity
   * @return unsigned int - The maximum number of items in this ShoppingList
   */
unsigned int ShoppingList::max_items() const {
  return mListCapacity;
}

  /*
   * Accessor for mNumberOfItemsOnList
   * @return unsigned int - The count of number of items in this ShoppingList
   */
unsigned int ShoppingList::item_count() const {
  return mNumberOfItemsOnList;
}

  /*
   * Place an item at a specified index in the array and increment the count of
   * items in the array.
   * @param string item - The item to be added to the array
   * @return bool - True if the item can be added, otherwise return false
   */
bool ShoppingList::AddItem(string inItemToAdd) {
  if (mNumberOfItemsOnList < mListCapacity) {
    mItemsArray[mNumberOfItemsOnList] = inItemToAdd;
    mNumberOfItemsOnList++;
    return true;
  } else {
    return false;
  }
}

  /*
   * Retrieve the item at a specified index in the array.
   * The first line of this function is an assertion to check to see if the
   * index is valid.
   * @param unsigned int index - The zero-based index of the item to be
   *                             retrieved
   * @return string - The value of the item at the specified index
   */
string ShoppingList::GetItem(unsigned int index) const {
  assert(index >= 0 && index < mNumberOfItemsOnList);
  return mItemsArray[index];
}

  /*
   * Retrieve a reference to the item at a specified index in the array.
   * The first line of this function is an assertion to check to see if the
   * index is valid.
   * @param unsigned int index - The zero-based index of the item to be
   *                             retrieved
   * @return string& - A reference to the value of the item at the specified index
   */
string& ShoppingList::GetItem(unsigned int index) {
  assert(index >= 0 && index < mNumberOfItemsOnList);
  return mItemsArray[index];
}

  // Why Two GetItem with the same number/type of parameters?
  // http://www.geeksforgeeks.org/function-overloading-and-const-functions/

  /*
   * Reset the items array by freeing its associated memory and re-allocating to
   * a specified size.
   * The first line of this function is an assertion to check to see if the
   * parameter is greater than 0
   * @param unsigned int max_items - The desired new max size of mItemsArray
   */


// For testing (DO NOT ALTER)
void UnitTest(int test) {
  string temp = "This unit test will test your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;

  ShoppingList* myList = new ShoppingList;
  cout << "* DEFAULT CONSTRUCTOR *\n\n";

  Test(myList->max_items() == 25, "max_items()");
  Test(myList->item_count() == 0, "item_count()");
  if (test == 1)
    myList->GetItem(0);
  Test(myList->AddItem("apples") == true, "AddItem(\"apples\")");
  Test(myList->item_count() == 1, "item_count()");
  Test(myList->GetItem(0) == "apples", "GetItem(0)");

  myList->GetItem(0) = "oranges";
  Test(myList->GetItem(0) == "oranges", "GetItem(0) = \"oranges\"");

  for (unsigned int i = 0; i < myList->max_items(); i++)
    myList->AddItem("grapes");

  Test(myList->item_count() == 25, "item_count() - Full List");
  Test(myList->AddItem("bananas") == false, "AddItem(\"bananas\")");
  Test(myList->max_items() == 25, "max_items()");
  if (test == 2)
    myList->GetItem(26);

  delete myList;
  myList = new ShoppingList(1);

  cout << "\n* OVERLOADED CONSTRUCTOR *\n\n";
  Test(myList->max_items() == 1, "max_items()");
  Test(myList->item_count() == 0, "item_count()");
  if (test == 3)
    myList->GetItem(0) = "oranges";
  Test(myList->AddItem("apples") == true, "AddItem(\"apples\")");
  Test(myList->item_count() == 1, "item_count()");
  Test(myList->GetItem(0) == "apples", "GetItem(0)");
  if (test == 4)
    myList->GetItem(1);

  cout << "\n* RESET FUNCTION *\n\n";
  if (test == 5)
    myList->Reset(0);

  myList->Reset(5);
  Test(myList->max_items() == 5, "max_items() - Reset to 5");
  Test(myList->item_count() == 0, "item_count()");
  if (test == 6)
    myList->GetItem(6);

  for (unsigned int i = 0; i < myList->max_items(); i++)
    myList->AddItem("grapes");
  Test(myList->item_count() == 5, "item_count() - Full List");
  Test(myList->AddItem("bananas") == false, "AddItem(\"bananas\")");
  Test(myList->max_items() == 5, "max_items()");

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n\n";
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << test_number << " " << more_info << "!\n";
  test_number++;
}
