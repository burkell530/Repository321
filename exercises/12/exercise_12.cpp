/*
 * Name        : exercise_12.cpp
 * Author      : FILL IN
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

/*
 * Allocate memory for a dynamic array of integers.
 * @param unsigned int size - The desired size of the dynamic array
 * @return int* - A pointer to the newly allocated integer array
 */
int* MakeDynoIntArray(unsigned int size);


/*
 * Compute the sum of an array.
 * @param int* the_array - The array for which the sum will be computed
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the sum of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Sum(int* the_array, unsigned int array_size);

/*
 * Identify the max value in an array.
 * @param int* the_array - The array for which the max value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the max value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Max(int* the_array, unsigned int array_size);

/*
 * Identify the min value in an array.
 * @param int* the_array - The array for which the min value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the min value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Min(int* the_array, unsigned int array_size);

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest(int argc, char *argv[]);

// Program Execution Starts Here
int main(int argc, char* argv[]) {
  // To test your code (DO NOT ALTER)
  UnitTest(argc, argv);
  // This ends program execution
  return 0;
}

/*
 * Allocate memory for a dynamic array of integers.
 * @param unsigned int size - The desired size of the dynamic array
 * @return int* - A pointer to the newly allocated integer array
 */
int* MakeDynoIntArray(unsigned int size) {
  int * array;
  array = new int[size];
  for (unsigned int i = 0; i < size; i++) {
    array[i] = i + 1;
  }
  return array;
}
/*
 * Compute the sum of an array.
 * @param int* the_array - The array for which the sum will be computed
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the sum of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Sum(int* the_array, unsigned int array_size) {
  int sum;
  if (the_array == 0) {
    throw "NULL ARRAY REFERENCE";
  } else {
    sum = 0;
    for (unsigned int i = 0; i < array_size; i++) {
      sum = sum + the_array[i];
    }
  }
  return sum;
}

/*
 * Identify the max value in an array.
 * @param int* the_array - The array for which the max value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the max value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Max(int* the_array, unsigned int array_size) {
  if (the_array == 0)
    throw "NULL ARRAY REFERENCE";
  int max = the_array[0];
  for (unsigned int i = 0; i < array_size; i++)
    if (max < the_array[i])
      max = the_array[i];
  return max;
}

/*
 * Identify the min value in an array.
 * @param int* the_array - The array for which the min value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the min value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Min(int* the_array, unsigned int array_size) {
  if (the_array == 0)
    throw "NULL ARRAY REFERENCE";
  int min = the_array[0];
  for (unsigned int i = 0; i < array_size; i++)
    if (min > the_array[i])
      min = the_array[i];
  return min;
}


// For testing (DO NOT ALTER)
void UnitTest(int argc, char *argv[]) {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  int* my_array = NULL;  // = makeDynoIntArray(10);
  unsigned int my_array_size = 0;

  try {
    Sum(my_array, my_array_size);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL ARRAY REFERENCE"), "Sum() EXCEPTION HANDLING");
  }

  try {
    Min(my_array, my_array_size);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL ARRAY REFERENCE"), "Min() EXCEPTION HANDLING");
  }

  try {
    Max(my_array, my_array_size);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL ARRAY REFERENCE"), "Max() EXCEPTION HANDLING");
  }

  my_array_size = 3;
  my_array = MakeDynoIntArray(my_array_size);
  Test(my_array != NULL, "MakeDynoIntArray(3)");

  my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;

  Test(Sum(my_array, my_array_size) == 60, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, "Min(Array)");

  my_array[0] = 30, my_array[1] = 10, my_array[2] = 20;
  Test(Sum(my_array, my_array_size) == 60, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, "Min(Array)");

  my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
  Test(Sum(my_array, my_array_size) == 60, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, "Min(Array)");

  my_array[0] = 20, my_array[1] = 10, my_array[2] = 30;

  Test(Sum(my_array, my_array_size) == 60, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, "Min(Array)");
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
