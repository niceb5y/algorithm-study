#include <iostream>

using namespace std;

int solve(int k, int n) {
  if (k == 1)
    return n * (n + 1) / 2;
  int ret = 0;
  for (int i = 1; i <= n; ++i)
    ret += solve(k - 1, i);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k, n;
    cin >> k >> n;
    cout << solve(k, n) << "\n";
  }
}
