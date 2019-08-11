#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  num.resize(n);
  for (auto &i : num) {
    cin >> i;
  }

  int ans = 0;

  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int sum = num[i] + num[j] + num[k];
        if (sum <= m && sum > ans)
          ans = sum;
      }
    }
  }

  cout << ans << "\n";
}
