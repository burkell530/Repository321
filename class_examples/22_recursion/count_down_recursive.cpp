#include <iostream>
using std::cout;
using std::endl;

void CountDown(int number) {
  cout << number << endl;
  if (number > 0)
    CountDown(number - 1);
}

int main() {
  CountDown(5);
  return 0;
}
