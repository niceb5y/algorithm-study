#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 1;
  cin >> n;
  vector<int> arr(n), len(n, 1);
  for (auto &i : arr) {
    cin >> i;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] < arr[i]) {
        len[i] = max(len[i], len[j] + 1);
      }
    }
    ans = max(ans, len[i]);
  }
  cout << ans << endl;
}
