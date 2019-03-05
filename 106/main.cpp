#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node_t {
  int id;
  int left;
  int right;
};

struct range_t {
  int min;
  int max;
  range_t(int min, int max) : min(min), max(max){};
};

// n: 트리의 노드의 수
// max_level: 트리의 최대 레벨
// col: 노드의 열 값
int n, max_level = 0, col = 0;
// nodes: 트리 노드를 저장하는 벡터
vector<node_t> nodes;
// levels[i]: (i + 1)의 레벨을 갖는 노드들의 col 값의 최대 최소를 저장하는 벡터
vector<range_t> levels;

// find_root(): 트리 노드의 루트를 찾는다.
int find_root() {
  // parents[i]: (i + 1)번째 노드의 부모
  // 존재하지 않는 경우 (= 루트) -1 값을 갖는다.
  vector<int> parents(n, -1);
  for (int i = 0; i < n; ++i) {
    int left = nodes[i].left, right = nodes[i].right;
    // 왼쪽 자식 노드가 있으면 현재 노드를 부모로 설정한다.
    if (left != -1) {
      parents[left - 1] = i + 1;
    }
    // 오른쪽 자식 노드가 있으면 현재 노드를 부모로 설정한다.
    if (right != -1) {
      parents[right - 1] = i + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    // 루트 노드의 id를 반환한다.
    if (parents[i] == -1) {
      return i + 1;
    }
  }
  // 잘못된 트리인 경우 -1을 반환한다.
  return -1;
}

// eval(cur, level): 트리를 중위순회하며 너비와 깊이를 계산한다.
void eval(const int &cur, const int &level) {
  max_level = max(max_level, level);
  // 왼쪽 자식 노드가 존재하는 경우 순회
  if (nodes[cur - 1].left != -1) {
    eval(nodes[cur - 1].left, level + 1);
  }
  // col을 구하고 해당 레벨의 최대 최소를 갱신한다.
  ++col;
  levels[level].min = min(levels[level].min, col);
  levels[level].max = max(levels[level].max, col);
  // 오른쪽 자식 노드가 존재하는 경우 순회
  if (nodes[cur - 1].right != -1) {
    eval(nodes[cur - 1].right, level + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // 변수 입력 & 초기화
  cin >> n;
  nodes.resize(n);
  levels.resize(n, range_t(10001, 0));
  for (auto &node : nodes) {
    cin >> node.id >> node.left >> node.right;
  }
  // 노드를 순서대로 정렬한다.
  sort(nodes.begin(), nodes.end(),
       [](node_t a, node_t b) { return a.id < b.id; });

  // root: 트리의 루트
  const int root = find_root();
  eval(root, 0);
  // ans_level: 가장 너비가 넓은 레벨
  // ans_width: 가장 너비가 넓은 레벨의 너비
  int ans_level = 0, ans_width = 0;
  for (int i = 0; i <= max_level; ++i) {
    const int width = levels[i].max - levels[i].min + 1;
    if (width > ans_width) {
      ans_level = i + 1;
      ans_width = width;
    }
  }
  // 결과 출력
  cout << ans_level << " " << ans_width << "\n";
}
