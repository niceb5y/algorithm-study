#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int sum = i, tmp = i;
    while (tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (sum == n) {
      cout << i << "\n";
      return 0;
    }
  }

  cout << 0 << "\n";
}
