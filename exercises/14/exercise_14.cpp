/*
 * Name        : exercise_14.cpp
 * Author      : FILL IN
 * Description : Working with Bubble and Selection Sort
 */
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*
 * Apply the bubble sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int BubbleSort(int the_array[], unsigned int size);

/*
 * Apply the optimized bubble sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int OptimizedBubbleSort(int the_array[], unsigned int size);

/*
 * Apply the selection sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int SelectionSort(int the_array[], unsigned int size);

/*
 * Swap the values of two integer variables.
 * @param int &value_1 - The first value to be swapped.
 * @param int &value_2 - The second value to be swapped.
 */
void SwapValues(int &value_1, int &value_2);

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();
bool CompareArrays(int array_one[], int array_two[], unsigned int size);
bool GRADER = false;
const unsigned int kSize = 5;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE HERE -- FUNCTION DEFINITION

void SwapValues(int &value_1, int &value_2) {
  // DO NOT ALTER THE NEXT 3 LINES!!!
  if (GRADER) {
    cout << value_1 << " " << value_2 << endl;
  }
  // Code SWAP Algorithm Here
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  int main[kSize] = { 10, 20, 30, 40, 50 };
  int test[kSize] = { 50, 40, 30, 20, 10 };
  int passes;

  // Bubble Sort
  BubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "BubbleSort([50, 40, 30, 20, 10])");

  BubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "BubbleSort([10, 20, 30, 40, 50])");

  test[0] = 10, test[1] = 30, test[2] = 20, test[3] = 50, test[4] = 40;

  BubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "BubbleSort([10, 30, 20, 50, 40])");

  main[0] = 10, main[1] = 30, main[2] = 30, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 30, test[2] = 10, test[3] = 30, test[4] = 50;

  BubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "BubbleSort([50, 30, 10, 30, 50])");

  main[0] = 50, main[1] = 50, main[2] = 50, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 50, test[2] = 50, test[3] = 50, test[4] = 50;

  passes = BubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "BubbleSort([50, 50, 50, 50, 50])");
  Test(passes == 4, "BubbleSort Number of Passes");

  // Optimized Bubble Sort
  main[0] = 10, main[1] = 20, main[2] = 30, main[3] = 40, main[4] = 50;
  test[0] = 50, test[1] = 40, test[2] = 30, test[3] = 20, test[4] = 10;

  OptimizedBubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize),
       "OptimizedBubbleSort([50, 40, 30, 20, 10])");

  OptimizedBubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize),
       "OptimizedBubbleSort([10, 20, 30, 40, 50])");

  test[0] = 10, test[1] = 30, test[2] = 20, test[3] = 50, test[4] = 40;

  OptimizedBubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize),
       "OptimizedBubbleSort([10, 30, 20, 50, 40])");

  main[0] = 10, main[1] = 30, main[2] = 30, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 30, test[2] = 10, test[3] = 30, test[4] = 50;

  OptimizedBubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize),
       "OptimizedBubbleSort([50, 30, 10, 30, 50])");

  main[0] = 50, main[1] = 50, main[2] = 50, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 50, test[2] = 50, test[3] = 50, test[4] = 50;

  passes = OptimizedBubbleSort(test, kSize);
  Test(CompareArrays(main, test, kSize),
       "OptimizedBubbleSort([50, 50, 50, 50, 50])");
  Test(passes == 1, "OptimizedBubbleSort Number of Passes");

  // Selection Sort
  main[0] = 10, main[1] = 20, main[2] = 30, main[3] = 40, main[4] = 50;
  test[0] = 50, test[1] = 40, test[2] = 30, test[3] = 20, test[4] = 10;

  SelectionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "SelectionSort([50, 40, 30, 20, 10])");

  SelectionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "SelectionSort([10, 20, 30, 40, 50])");

  test[0] = 10, test[1] = 30, test[2] = 20, test[3] = 50, test[4] = 40;

  SelectionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "SelectionSort([10, 30, 20, 50, 40])");

  main[0] = 10, main[1] = 30, main[2] = 30, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 30, test[2] = 10, test[3] = 30, test[4] = 50;

  SelectionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "SelectionSort([50, 30, 10, 30, 50])");

  main[0] = 50, main[1] = 50, main[2] = 50, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 50, test[2] = 50, test[3] = 50, test[4] = 50;

  passes = SelectionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), "SelectionSort([50, 50, 50, 50, 50])");
  Test(passes == 5, "SelectionSort Number of Passes");

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n\n";

  GRADER = true;
  cout << "Starting Algorithm Test\n";
  cout << string(temp.length() - 1, '-') << endl;

  main[0] = 9, main[1] = 1, main[2] = 5, main[3] = 2, main[4] = 7;
  cout << "Bubble Sort Expected\n" << "--------------------\n"
       << "9 1\n9 5\n9 2\n9 7\n5 2\n\n";
  cout << "Bubble Sort Actual\n" << "--------------------\n";
  BubbleSort(main, kSize);

  cout << endl << endl;
  main[0] = 9, main[1] = 1, main[2] = 5, main[3] = 2, main[4] = 7;
  cout << "Selection Sort Expected\n" << "--------------------\n"
       << "9 1\n9 2\n9 9\n\n";
  cout << "Selection Sort Actual\n" << "--------------------\n";
  SelectionSort(main, kSize);
  cout << string(temp.length() - 1, '-') << endl;
  cout << "Algorithm Test Complete!\n\n";
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

bool CompareArrays(int array_one[], int array_two[], unsigned int size) {
  for (unsigned int i = 0; i < size; i++)
    if (array_one[i] != array_two[i])
      return false;
  return true;
}
