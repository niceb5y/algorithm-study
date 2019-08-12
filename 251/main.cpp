#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> seq, lis;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  seq.resize(n);
  lis.resize(n + 1, 10000001);
  lis[0] = -10000001;
  for (auto &i : seq) {
    cin >> i;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto lo = lower_bound(lis.begin(), lis.end(), seq[i]);
    int len = distance(lis.begin(), lo);
    *lo = min(*lo, seq[i]);
    ans = max(ans, len);
  }
  cout << ans << '\n';
}
