#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    if (i < 100 || i / 100 - (i % 100) / 10 == (i % 100) / 10 - i % 10)
      ++ans;
  }
  cout << ans << "\n";
}
