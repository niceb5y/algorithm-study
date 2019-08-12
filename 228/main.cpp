#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr(n), len1(n, 1), len2(n, 1);

  for (auto &n : arr) {
    cin >> n;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[i] > arr[j] && len1[j] + 1 > len1[i]) {
        len1[i] = len1[j] + 1;
      }

      if (arr[n - i - 1] > arr[n - j - 1] &&
          len2[n - j - 1] + 1 > len2[n - i - 1]) {
        len2[n - i - 1] = len2[n - j - 1] + 1;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (len1[i] + len2[i] - 1 > ans)
      ans = len1[i] + len2[i] - 1;
  }
  cout << ans << "\n";
}
