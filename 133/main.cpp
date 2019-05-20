#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// INF: 그래프 노드 사이의 거리를 처음에 초기화할 매우 큰 수
const int INF = 987654321;

// node: 다익스트라 우선순위 큐에 사용될 노드
struct node {
  // id: 노드의 번호
  int id;
  // dist: 1번 노드와의 거리
  int dist;
  node(const int &id, const int &dist) {
    this->id = id;
    this->dist = dist;
  }
};

// 우선순위 큐를 정렬하기 위한 구조체
struct node_cmp {
  bool operator()(const node &t, const node &u) { return t.dist < u.dist; }
};

int main() {
  // n: 노드의 수
  // m: 엣지의 수
  int n, m;
  scanf("%d %d", &n, &m);
  // dist[i]: 노드 1번부터 i번까지의 최단 거리
  // from[i]: 최단 거리일 때 i의 직전 노드
  vector<int> dist(n + 1, INF), from(n + 1);
  dist[1] = 0;

  // adj: 가중치 그래프의 인접 행렬
  vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1));
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a][b] = c;
    adj[b][a] = c;
  }

  // pq: 다익스트라 알고리즘으로 최단 거리를 구할 때 사용될 우선 순위 큐
  priority_queue<node, vector<node>, node_cmp> pq;
  pq.push(node(1, 0));

  while (!pq.empty()) {
    // top: 현재 거리가 가장 최소인 원소
    node top = pq.top();
    pq.pop();

    // 기존의 거리가 더 짧으면 계산하지 않는다.
    if (dist[top.id] < top.dist)
      continue;

    // 최단 거리 갱신
    dist[top.id] = top.dist;
    // 인접 노드의 거리를 갱신한다.
    for (int i = 1; i <= n; ++i) {
      // 연결 되지 않은 노드 생략
      if (adj[top.id][i] == -1)
        continue;
      // top 노드와 i번째 노드 사이의 엣지를 통하는 것이 최단거리인 경우
      if (dist[i] > adj[top.id][i] + dist[top.id]) {
        // 최단 거리 갱신
        dist[i] = adj[top.id][i] + dist[top.id];
        // 큐에 집어넣는다.
        pq.push(node(i, dist[i]));
        // 경로 갱신
        from[i] = top.id;
      }
    }
  }

  // 결과 출력
  printf("%d\n", n - 1);
  for (int i = 2; i <= n; ++i) {
    printf("%d %d\n", i, from[i]);
  }
}
