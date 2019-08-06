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

  vector<pair<int, int>> pos(n);
  for (auto &p : pos) {
    cin >> p.second >> p.first;
  }

  sort(pos.begin(), pos.end());

  for (auto &p : pos) {
    cout << p.second << " " << p.first << "\n";
  }
}
