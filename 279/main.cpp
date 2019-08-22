#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> seq, pos, lis;

void print_lis(long long hi, long long count, long long next) {
  for (int i = hi - 1; i >= 0; --i) {
    if (count == 0)
      return;
    if (pos[i] == count && seq[i] <= next) {
      print_lis(i, count - 1, seq[i]);
      cout << (count == 1 ? "" : " ") << seq[i];
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  seq.resize(n);
  pos.resize(n, 1);
  lis.resize(n + 1, 10000000001);
  lis[0] = -10000000001;
  for (auto &i : seq) {
    cin >> i;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto lo = lower_bound(lis.begin(), lis.end(), seq[i]);
    int len = distance(lis.begin(), lo);
    pos[i] = len;
    *lo = min(*lo, seq[i]);
    ans = max(ans, len);
  }

  cout << ans << '\n';
  print_lis(n, ans, 10000000001);
  cout << '\n';
}
