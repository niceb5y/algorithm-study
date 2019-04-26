#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

// pnt: 점의 좌표 x, y를 저장하는 구조체
struct pnt {
  int x;
  int y;
};

// sa(a, b, c):  점 a, b, c로 이루어진 삼각형 abc의 sign area를 구하는 함수
int sa(const pnt &a, const pnt &b, const pnt &c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

// dist(a, b): 두 점 a, b의 거리를 구하는 함수
double dist(const pnt &a, const pnt &b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
  // c 받을 좌표의 수
  int c;
  scanf("%d", &c);
  // pos: 좌표들을 저장할 벡터
  vector<pnt> pos(c);

  // crit: 기준점의 좌표
  pnt crit = {1001, 1001};
  for (auto &p : pos) {
    // 좌표 입력
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    // 기준점을 구한다.
    if (p.x < crit.x || (p.x == crit.x && p.y < crit.y)) {
      crit.x = p.x;
      crit.y = p.y;
    }
  }

  // 기준점과 이루는 각도에 따라 정렬한다.
  sort(pos.begin(), pos.end(), [crit](const pnt &a, const pnt &b) {
    // a가 기준점인 경우
    if (a.x == crit.x && a.y == crit.y)
      return true;
    // b가 기준점인경우
    if (b.x == crit.x && b.y == crit.y)
      return false;
    // a와 b의 기울기에 따라 결정
    // 기울기를 구할 때 분모가 0인 경우가 있을 수 있으므로 분모를 이항하여 계산
    return (a.y - crit.y) * (b.x - crit.x) < (b.y - crit.y) * (a.x - crit.x);
  });

  // hull: convex hull의 인덱스를 저장할 deque
  deque<int> hull({0, 1});
  // graham's scan 알고리즘으로 convex hull을 구한다.
  for (int p2 = 2; p2 < c; ++p2) {
    while (hull.size() >= 2) {
      const int p1 = hull.back();
      hull.pop_back();
      const int p0 = hull.back();
      if (sa(pos[p0], pos[p1], pos[p2]) > 0) {
        hull.emplace_back(p1);
        break;
      }
    }
    hull.emplace_back(p2);
  }

  // ans: 가장 먼 두 점의 거리
  double ans = 0;
  // h: convex hull의 크기
  const int h = hull.size();
  // gh(i): convex hull의 i번째 원소를 가져오는 변수
  const auto gh = [pos, hull, h](const int &i) { return pos[hull[i % h]]; };

  // rotating calipers 알고리즘으로 가장 먼 두 점의 거리를 구한다.
  for (int i = 0, j = 1; i < h; ++i) {
    while (sa(gh(i), gh(i + 1), gh(j)) < sa(gh(i), gh(i + 1), gh(j + 1))) {
      j = (j + 1) % h;
    }
    ans = max(ans, dist(gh(i), gh(j)));
  }

  // 결과 출력
  printf("%.6lf\n", ans);
}
