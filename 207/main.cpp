#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int sum = 1, ans = 1, n;
  cin >> n;
  while (sum < n) {
    sum += 6 * (ans++);
  }
  cout << ans << "\n";
}
