#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << ((c - b > 0) ? (a / (c - b) + 1) : -1) << endl;
}
