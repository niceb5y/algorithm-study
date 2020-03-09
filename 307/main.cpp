#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  int i, x, burger = 2000, drink = 2000;
  for (i = 0; i < 3; ++i) {
    cin >> x;
    burger = min(x, burger);
  }
  for (; i < 5; ++i) {
    cin >> x;
    drink = min(x, drink);
  }
  cout << burger + drink - 50 << endl;
}
