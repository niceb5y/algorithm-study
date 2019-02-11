#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 트리 노드의 수
  int n;
  cin >> n;
  // adj: 트리의 인접 리스트
  vector<list<int>> adj(n);
  // parent[i]: (i + 1)번 노드의 부모
  vector<int> parent(n, -1);
  // 루트는 자기 자신을 가리킨다.
  parent[0] = 1;
  // to_visit: 부모를 찾기 위해 방문해야 하는 노드들의 번호
  list<int> to_visit;
  // 인접 리스트 입력
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y);
    adj[y - 1].push_back(x);
  }
  // to_visit에 루트를 추가한다.
  to_visit.push_back(1);
  // bfs를 통해 각 노드들의 부모를 찾는다.
  while (!to_visit.empty()) {
    int cur = to_visit.front();
    for (auto &child : adj[cur - 1]) {
      if (parent[child - 1] == -1) {
        parent[child - 1] = cur;
        to_visit.push_back(child);
      }
    }
    to_visit.pop_front();
  }
  // 결과물 출력
  for (int i = 1; i < n; ++i) {
    cout << parent[i] << '\n';
  }
}
