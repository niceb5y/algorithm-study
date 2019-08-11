#include <iostream>

using namespace std;

int main() {
  int n, cnt = 0, i = 666;
  cin >> n;

  for (;; ++i) {
    if (to_string(i).find("666") != string::npos)
      ++cnt;
    if (cnt == n) {
      cout << i << "\n";
      return 0;
    }
  }
}
