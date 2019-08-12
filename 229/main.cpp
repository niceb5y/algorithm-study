#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto &i : arr) {
    cin >> i.first >> i.second;
  }
  sort(arr.begin(), arr.end(),
       [](auto a, auto b) { return a.first < b.first; });

  vector<int> len(n, 1);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[i].second > arr[j].second && len[j] + 1 > len[i]) {
        len[i] = len[j] + 1;
      }
    }
  }

  int max_len = 0;
  for (auto &i : len) {
    if (i > max_len)
      max_len = i;
  }

  cout << n - max_len << "\n";
}
