#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

void solve(int depth) {
  if (depth == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << (i == m - 1 ? "\n" : " ");
    }
    return;
  }

  for (int i = 1; i <= n; ++i) {
    arr[depth] = i;
    solve(depth + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  arr.resize(m);

  solve(0);
}
