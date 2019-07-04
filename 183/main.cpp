#include <iostream>

using namespace std;
int main() {
  int a, b;
  while (true) {
    cin >> a >> b;
    if (a == b && a == 0)
      break;
    cout << a + b << "\n";
  }
}
