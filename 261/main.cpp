#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> avail;
vector<int> arr;

void solve(int depth) {
  if (depth == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << (i == m - 1 ? "\n" : " ");
    }
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (depth > 0 && arr[depth - 1] > i)
      continue;
    if (avail[i]) {
      avail[i] = false;
      arr[depth] = i;
      solve(depth + 1);
      avail[i] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  avail.resize(n + 1, true);
  arr.resize(m);

  solve(0);
}
