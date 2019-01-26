#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// point_t: 한 점의 좌표를 저장하는 구조체
struct point_t {
  short x, y;
  point_t() : point_t(0, 0) {}
  point_t(short x, short y) : x(x), y(y) {}
  bool operator<(const point_t &r) const {
    return (y == r.y) ? (x < r.x) : (y < r.y);
  }
};

// dist: 두 점 사이의 거리의 제곱을 반환하는 함수
int dist(const point_t &pt1, const point_t &pt2) {
  return pow((pt1.x - pt2.x), 2) + pow((pt1.y - pt2.y), 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 점의 개수
  int n;
  cin >> n;
  // points: 점들을 저장하는 벡터
  vector<point_t> points(n);
  for (auto &i : points) {
    cin >> i.x >> i.y;
  }
  // 점을 x좌표에 맞춰서 정렬한다.
  sort(points.begin(), points.end(),
       [](const point_t &l, const point_t &r) { return l.x < r.x; });

  // ans: 두 점 사이의 거리의 제곱의 최소값
  int ans = dist(points[0], points[1]);
  // candidate: 최소의 거리를 가질 수 있는 점의 벡터
  set<point_t> candidate({points[0], points[1]});
  // idx: 거리를 검사할 구간의 시작 points[idx]
  int idx = 0;
  for (int i = 2; i < n; ++i) {
    // cur: 다른 점들과 비교할 기준점
    point_t &cur = points[i];
    while (idx < i) {
      // p: candidate에 필요한지 검사할 점
      point_t &p = points[idx];
      // cur와 p의 차의 제곱이 ans 이상이면 p를 cur에서 제거한다.
      if (pow(cur.x - p.x, 2) > ans) {
        candidate.erase(p);
        ++idx;
      } else {
        break;
      }
    }
    // d: 두 점 사이의 최소 거리를 올림 한 값
    int d = ceil(sqrt((double)ans));
    // lo, hi: 비교를 할 점들의 범위 [lo, hi)
    auto lo = candidate.lower_bound(point_t(-10001, cur.y - d));
    auto hi = candidate.upper_bound(point_t(10001, cur.y + d));
    // ans의 최소값을 구한다
    for (auto it = lo; it != hi; ++it) {
      ans = min(ans, dist(cur, *it));
    }
    // 기준점을 candidate에 넣는다.
    candidate.insert(cur);
  }
  cout << ans << endl;
}
