#include <iostream>

bool arr[10001] = {};

void eval(int n) {
  int sum = n;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  if (sum <= 10000) {
    arr[sum] = true;
    eval(sum);
  }
}

using namespace std;
int main() {
  for (int i = 1; i <= 10000; ++i) {
    eval(i);
  }
  for (int i = 1; i <= 10000; ++i) {
    if (!arr[i])
      cout << i << "\n";
  }
}
