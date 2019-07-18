#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> coord;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  coord.resize(n);
  for (auto &c : coord) {
    cin >> c.first >> c.second;
  }
  sort(coord.begin(), coord.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
      return a.first < b.first;
    return a.second < b.second;
  });
  for (auto &c : coord) {
    cout << c.first << " " << c.second << "\n";
  }
}
