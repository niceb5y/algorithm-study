#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 1)
    n++;
  n /= 2;
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    ans *= 2;
    ans %= 16769023;
  }
  cout << ans << endl;
  return 0;
}
