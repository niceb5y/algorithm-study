#include <iostream>

using namespace std;
int main() {
  int t, a, b;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b;
    cout << "Case #" << i + 1 << ": " << a + b << "\n";
  }
}
