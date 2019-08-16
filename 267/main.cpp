#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2 * n - 1; ++j) {
      if (j <= n - 1 + i && j >= n - 1 - i && (n - i) % 2 != j % 2)
        cout << "*";
      else if (j == n + i)
        break;
      else {
        cout << " ";
      }
    }
    cout << "\n";
  }
}
