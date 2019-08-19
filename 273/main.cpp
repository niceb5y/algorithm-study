#include <iostream>
#include <utility>

using namespace std;

typedef pair<long long, long long> pt;
typedef pair<pt, pt> line;

int ccw(const pt &a, const pt &b, const pt &c) {
  const long long _ccw = a.first * b.second - a.second * b.first +
                         b.first * c.second - b.second * c.first +
                         c.first * a.second - c.second * a.first;
  return _ccw ? (_ccw > 0) ? 1 : -1 : 0;
}

bool is_intersect(const line &ab, const line &cd) {
  const pt &a = ab.first > ab.second ? ab.second : ab.first;
  const pt &b = ab.first > ab.second ? ab.first : ab.second;
  const pt &c = cd.first > cd.second ? cd.second : cd.first;
  const pt &d = cd.first > cd.second ? cd.first : cd.second;

  int chk1 = ccw(a, b, c) * ccw(a, b, d);
  int chk2 = ccw(c, d, a) * ccw(c, d, b);

  return (chk1 == 0 && chk2 == 0) ? (a <= d && c <= b)
                                  : (chk1 <= 0 && chk2 <= 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  line l1, l2;

  cin >> l1.first.first >> l1.first.second >> l1.second.first >>
      l1.second.second >> l2.first.first >> l2.first.second >>
      l2.second.first >> l2.second.second;

  cout << (is_intersect(l1, l2) ? 1 : 0) << "\n";
}
