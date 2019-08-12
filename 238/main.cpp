#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, two = 0, five = 0;
  cin >> n;

  for (int i = 2; i <= n; ++i) {
    int tmp = i;
    while (tmp % 2 == 0) {
      ++two;
      tmp /= 2;
    }
    while (tmp % 5 == 0) {
      ++five;
      tmp /= 5;
    }
  }

  cout << min(two, five) << "\n";
}
