#include <iostream>

using namespace std;
int main() {
  int n, five, three;
  cin >> n;
  five = n / 5;
  n = n % 5;
  while (five >= 0) {
    if (n % 3 == 0) {
      three = n / 3;
      n %= 3;
      break;
    }
    n += 5;
    --five;
  }
  cout << (n == 0 ? three + five : -1) << endl;
}
