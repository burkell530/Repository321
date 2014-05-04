#include <iostream>
using std::cout;
using std::endl;

int SumTo(int number) {
  int sum = 0;
  for (int i = 1; i <= number; i++)
    sum += i;
  return sum;
}

int main() {
  cout << SumTo(5) << endl;
  return 0;
}
