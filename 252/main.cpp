#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

long long setHeight(int mid) {
  long long ret = 0;
  for (auto it = lower_bound(tree.begin(), tree.end(), mid); it != tree.end();
       ++it) {
    ret += *it - mid;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  tree.resize(n);
  for (auto &t : tree) {
    cin >> t;
  }
  sort(tree.begin(), tree.end());

  int lo = 0, hi = tree[n - 1];
  int ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (setHeight(mid) >= m) {
      lo = mid + 1;
      ans = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans << "\n";
}
