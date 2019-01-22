#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// adj: 간접행렬
int adj[1000][1000];
// visited[i]: (i + 1)번 정점을 방문한 적 있는지 여부
bool visited[1000];

// dfs(n, v): 깊이 우선 탐색
// n: 정점의 수
// v: 처음 탐험할 정점의 번호
void dfs(int n, int v) {
  // visited 초기화
  for (int i = 0; i < n; ++i) {
    visited[i] = false;
  }
  // to_visit: 방문할 정점을 담은 스택
  stack<int> to_visit;
  // 처음으로 방문할 정점을 to_visit에 push한다.
  to_visit.push(v);
  // 방문할 정점이 스택에 남지 않을 때 까지 반복
  while (!to_visit.empty()) {
    // top: 이번에 방문할 정점
    int top = to_visit.top();
    to_visit.pop();
    // 처음 top에 방문하는 경우
    if (!visited[top - 1]) {
      // 정점 번호 출력
      cout << ((top == v) ? "" : " ") << top;
      visited[top - 1] = true;
      // 인접 정점을 스택에 추가한다.
      for (int i = n - 1; i >= 0; --i) {
        if (adj[top - 1][i] > 0 && !visited[i]) {
          to_visit.push(i + 1);
        }
      }
    }
  }
  cout << endl;
}

// bfs(n, v): 너비 우선 탐색
// n: 정점의 수
// v: 처음 탐험할 정점의 번호
void bfs(int n, int v) {
  // visited 초기화
  for (int i = 0; i < n; ++i) {
    visited[i] = false;
  }
  // to_visit: 방문할 정점을 담은 큐
  queue<int> to_visit;
  // 처음으로 방문할 정점을 to_visit에 push한다.
  to_visit.push(v);
  // 방문할 정점이 큐에 남지 않을 때 까지 반복
  while (!to_visit.empty()) {
    // front: 이번에 방문할 정점
    int front = to_visit.front();
    to_visit.pop();
    // 처음 front에 방문하는 경우
    if (!visited[front - 1]) {
      // 정점 번호 출력
      cout << ((front == v) ? "" : " ") << front;
      visited[front - 1] = true;
      // 인접 정점을 큐에 추가한다.
      for (int i = 0; i < n; ++i) {
        if (adj[front - 1][i] > 0 && !visited[i]) {
          to_visit.push(i + 1);
        }
      }
    }
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 정점의 개수
  // m: 간선의 개수
  // 처음 방문할 정점의 번호
  int n, m, v;
  cin >> n >> m >> v;
  // 인접행렬 초기화
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      adj[i][j] = 0;
    }
  }
  // x, y: 간선이 연결하는 두 정점의 번호
  int x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    ++adj[x - 1][y - 1];
    ++adj[y - 1][x - 1];
  }
  dfs(n, v);
  bfs(n, v);
}
