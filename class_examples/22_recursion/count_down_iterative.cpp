#include <iostream>
using std::cout;
using std::endl;

void CountDown(int number) {
  for (int i = number; i >= 0; i--)
    cout << i << endl;
}

int main() {
  CountDown(5);
  return 0;
}
