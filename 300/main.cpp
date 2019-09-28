#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int w, n;
  cin >> w >> n;
  vector<int> parcel(n);
  vector<vector<pair<int, int>>> sum(400001);

  for (auto &p : parcel) {
    cin >> p;
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sum[parcel[i] + parcel[j]].push_back(make_pair(i, j));
    }
  }

  for (int i = 1; i <= 400000; ++i) {
    if (w - i > 0 && w - i <= 400000 && sum[i].size() > 0 &&
        sum[w - i].size() > 0) {
      for (auto &a : sum[i]) {
        for (auto &b : sum[w - i]) {
          if (a.first != b.first && a.first != b.second &&
              a.second != b.first && a.second != b.second) {
            cout << "YES\n";
            return 0;
          }
        }
      }
    }
  }

  cout << "NO\n";
}
