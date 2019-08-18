#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pt;

int ccw(const pt &a, const pt &b, const pt &c) {
  const int _ccw = a.first * b.second - a.second * b.first +
                   b.first * c.second - b.second * c.first +
                   c.first * a.second - c.second * a.first;
  return _ccw ? (_ccw > 0) ? 1 : -1 : 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  pt a, b, c;
  cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

  cout << ccw(a, b, c) << "\n";
}
