#include <iostream>
using std::cout;
using std::endl;

int SumTo(int number) {
  if (number <= 1)
    return number;
  else
    return SumTo(number - 1) + number;
}

int main() {
  cout << SumTo(5) << endl;
  return 0;
}
