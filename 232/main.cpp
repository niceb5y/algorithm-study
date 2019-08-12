#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
      break;

    if (b % a == 0)
      cout << "factor";
    else if (a % b == 0)
      cout << "multiple";
    else
      cout << "neither";

    cout << "\n";
  }
}
