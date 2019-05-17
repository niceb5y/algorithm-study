#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// node: Union-Find에 사용할 Up-tree 노드
// .first: 부모 노드
// .second: 노드의 높이
typedef pair<int, int> node;
// pt: 2차원 평면 상의 좌표
typedef pair<int, int> pt;
// line: 한 선분의 시작과 끝
typedef pair<pt, pt> line;

// lines: 선분을 저장하는 벡터
vector<line> lines;
// nodes: Union-Find에 사용되는 Up-tree 노드의 정보를 담은 벡터
vector<node> nodes;

// ccw(a, b, c): a, b, c 세 점의 배치를 알려주는 함수
// > 0: 반시계 방향
// = 0: 일직선
// < 0: 시계 방향
int ccw(const pt &a, const pt &b, const pt &c) {
  const int _ccw = a.first * b.second - a.second * b.first +
                   b.first * c.second - b.second * c.first +
                   c.first * a.second - c.second * a.first;
  //  오버플로우 방지를 위해 스케일링
  return _ccw ? (_ccw > 0) ? 1 : -1 : 0;
}

// is_intersect(ab, cd): 두 선분 ab, cd가 교차하는지 알려주는 함수
bool is_intersect(const line &ab, const line &cd) {
  const pt &a = ab.first > ab.second ? ab.second : ab.first;
  const pt &b = ab.first > ab.second ? ab.first : ab.second;
  const pt &c = cd.first > cd.second ? cd.second : cd.first;
  const pt &d = cd.first > cd.second ? cd.first : cd.second;

  // ab 선분 기준 검사
  int chk1 = ccw(a, b, c) * ccw(a, b, d);
  // cd 선분 기준 검사
  int chk2 = ccw(c, d, a) * ccw(c, d, b);

  // 두 선분이 평행한 경우, 겹치는지 확인
  // 두 선분이 평행하지 않은 경우, 선분이 한 점에서 만나는지 확인
  return (chk1 == 0 && chk2 == 0) ? (a <= d && c <= b)
                                  : (chk1 <= 0 && chk2 <= 0);
}

// find_set(n): n번 노드의 부모를 찾는 함수
int find_set(int n) {
  while (n != nodes[n].first) {
    n = nodes[n].first;
  }
  return n;
}

// union_set: 두 선분 그룹을 합치는 함수
// height 검사를 통해 트리의 높이 증가를 억제시킨다.
void union_set(int x, int y) {
  int a = find_set(x), b = find_set(y);
  if (nodes[a].second <= nodes[b].second) {
    if (nodes[a].second == nodes[b].second)
      ++nodes[b].second;
    nodes[a].first = b;
  } else
    nodes[b].first = a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 초기화
  int n;
  cin >> n;
  lines.resize(n);
  for (auto &l : lines) {
    cin >> l.first.first >> l.first.second >> l.second.first >> l.second.second;
  }

  // 트리 노드 초기화
  nodes.resize(n);
  for (int i = 0; i < n; ++i) {
    nodes[i].first = i;
    nodes[i].second = 1;
  }

  // 선분 그룹을 구한다.
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (find_set(i) != find_set(j)) {
        if (is_intersect(lines[i], lines[j])) {
          union_set(i, j);
        }
      }
    }
  }

  // group_count: n번째 선분 그룹의 선분의 수
  vector<int> group_count(n);
  // group_size: 선분 그룹의 수
  int group_size = 0;
  // group_count_max: 선분 그룹의 선분의 수의 최대값
  int group_count_max = 0;
  for (int i = 0; i < n; ++i) {
    const int parent = find_set(i);
    // group_count 증가
    ++group_count[parent];
    // group_count_max 최대값 갱신
    group_count_max = max(group_count_max, group_count[parent]);
    // 선분 그룹의 루트 노드인경우 group_size 증가
    if (parent == i)
      ++group_size;
  }

  // 결과 출력
  cout << group_size << "\n" << group_count_max << "\n";
}
