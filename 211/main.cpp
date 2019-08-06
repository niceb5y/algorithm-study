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

  vector<pair<int, string>> pos(n);
  for (auto &p : pos) {
    cin >> p.first >> p.second;
  }

  stable_sort(pos.begin(), pos.end(),
              [](auto a, auto b) { return a.first < b.first; });

  for (auto &p : pos) {
    cout << p.first << " " << p.second << "\n";
  }
}
