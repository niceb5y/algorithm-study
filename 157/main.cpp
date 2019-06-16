#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<long long, long long> pos;

long long ccw(pos a, pos b, pos c) {
  return (a.first * b.second + b.first * c.second + c.first * a.second -
          a.second * b.first - b.second * c.first - c.second * a.first);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pos> point(n);
  for (auto &p : point) {
    cin >> p.first >> p.second;
  }
  pos crit;
  crit = point[0];
  for (auto &p : point) {
    if (crit.first > p.first ||
        (crit.first == p.first && crit.second > p.second))
      crit = p;
  }

  sort(point.begin(), point.end(), [crit](pos a, pos b) {
    if (a == crit)
      return true;
    if (b == crit)
      return false;
    return (a.second - crit.second) * (b.first - crit.first) <
           (b.second - crit.second) * (a.first - crit.first);
  });

  deque<int> hull({0, 1});
  for (int p2 = 2; p2 < n; ++p2) {
    while (hull.size() >= 2) {
      const int p1 = hull.back();
      hull.pop_back();
      const int p0 = hull.back();
      if (ccw(point[p0], point[p1], point[p2]) > 0) {
        hull.emplace_back(p1);
        break;
      }
    }
    hull.emplace_back(p2);
  }

  if (ccw(point[hull[0]], point[hull[hull.size() - 2]],
          point[hull[hull.size() - 1]]) == 0) {
    int back = hull.back();
    hull.pop_back();
    hull.pop_back();
    hull.push_back(back);
  }

  cout << hull.size() << endl;
}
