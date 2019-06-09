#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// map(c): 문자열 c를 사상시켜주는 알고리즘
// A-Z,a-z를 0-25,26-51로 사상시키는 함수
int map(char c) { return (c < 'a') ? (c - 'A') : (c - 'G'); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // n: 파이프의 수
  // c[u][v]: 정점 u와 정점 v를 연결하는 파이프의 최대 유량
  // f[u][v]: 정점 u와 정점 v를 연결하는 파이프의 현재 유량
  int n, c[52][52] = {}, f[52][52] = {};
  vector<int> adj[52];

  // 값 초기화
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char cu, cv;
    int capacity;
    // 파이프의 정보를 입력받아 그래프를 만든다.
    cin >> cu >> cv >> capacity;
    const int u = map(cu), v = map(cv);
    // 비방향성 그래프이므로 양방향 추가
    c[u][v] = c[v][u] += capacity;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // ans: A에서 Z까지의 최대 유량
  // prev[i]: 정점 i 직전에 방문한 정점
  int ans = 0, prev[52];
  // s: 시작점 'A'
  // t: 끝점 'Z'
  const int s = 0, t = 25;

  while (true) {
    // prev 정보 초기화
    fill_n(&prev[0], 52, -1);
    // 큐를 이용하여 BFS로 경로를 탐색한다.
    queue<int> q;
    q.push(s);
    // 정점을 모두 방문하거나, 'Z'에 도달할 때 까지 반복
    while (!q.empty()) {
      // cur: 이번에 방문할 정점
      int cur = q.front();
      q.pop();
      // cur의 인접 정점 방문
      for (auto &next : adj[cur]) {
        // cur정점과 next정점 사이의 유량이 남아있고, 방문하지 않은 정점인 경우
        if (c[cur][next] > f[cur][next] && prev[next] == -1) {
          prev[next] = cur;
          q.push(next);
          // 정점 'Z'에 도달한 경우 순회 종료
          if (next == t)
            break;
        }
      }
    }

    // 'Z'에 도달할 수 없는 경우 순회 종료
    if (prev[t] == -1)
      break;

    // flow_limit: 현재 경로로 보낼 수 있는 유량의 최대값
    // cur: 유량을 계산하기 위해 방문할 정점
    int flow_limit = 1000, cur = t;
    // 'Z'에서 'A'로 거슬러가며 flow_limit을 구한다.
    while (cur != s) {
      flow_limit = min(flow_limit, c[prev[cur]][cur] - f[prev[cur]][cur]);
      cur = prev[cur];
    }
    cur = t;
    // 'Z'에서 'A'로 거슬러가며 flow_limit만큼 물을 흘려보낸다.
    while (cur != s) {
      f[prev[cur]][cur] += flow_limit;
      f[cur][prev[cur]] -= flow_limit;
      cur = prev[cur];
    }

    // flow_limit의 총 합을 구한다.
    ans += flow_limit;
  }

  // 결과 출력
  cout << ans << "\n";
}
