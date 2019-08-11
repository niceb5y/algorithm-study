#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first && a.second > b.second)
    return 1;
  else if (a.first < b.first && a.second < b.second)
    return -1;
  else
    return 0;
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  vector<int> ans(n, 1);

  for (auto &p : arr) {
    cin >> p.first >> p.second;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      if (compare(arr[i], arr[j]) < 0)
        ans[i]++;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}
