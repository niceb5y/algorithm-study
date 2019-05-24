#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 987654321;

  // TC: 테스트 케이스의 수
  int TC;
  cin >> TC;

  for (int i = 0; i < TC; ++i) {
    // N: 지점의 수
    // M: 도로의 개수
    // W: 웜홀의 개수
    int N, M, W;
    cin >> N >> M >> W;

    // dist[i]: 정점 1부터 정점 i까지의 최단거리
    vector<int> dist(N + 1);
    for (int j = 1; j <= N; ++j) {
      dist[j] = INF;
    }
    dist[1] = 0;

    // path[i]: 지점 i에서 출발하는 엣지-가중치 페어의 벡터
    vector<vector<pair<int, int>>> path(N + 1);
    for (int j = 0; j < M + W; ++j) {
      int s, e, t;
      cin >> s >> e >> t;
      if (j < M) {
        // 도로인 경우
        path[s].emplace_back(make_pair(e, t));
        path[e].emplace_back(make_pair(s, t));
      } else {
        // 웜홀인 경우
        path[s].emplace_back(make_pair(e, -t));
      }
    }

    // is_exists[i]: 큐에 정점 i가 존재하는지 여부
    vector<bool> is_exists(N + 1, false);
    // cnt[i]: 정점 i를 방문한 횟수
    vector<int> cnt(N + 1, 0);

    // q: SPFA를 위한 큐
    queue<int> q({1});
    is_exists[1] = true;

    // has_cycle: 음수 사이클의 존재 여부
    bool has_cycle = false;

    while (!q.empty()) {
      // u: 현재 정점
      const int u = q.front();
      q.pop();
      is_exists[u] = false;
      // cnt 증가 후, N 이상이면 사이클이 존재하는 것으로 판단,
      // 루프를 벗어남.
      if (++cnt[u] >= N) {
        has_cycle = true;
        break;
      }

      // 인접한 지점 방문
      for (auto &p : path[u]) {
        // v: 방문할 지점
        // w: 가중치
        const int v = p.first, w = p.second;
        // 거리 갱신
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          // 큐에 v가 존재하지 않으면 추가한다.
          if (!is_exists[v]) {
            q.emplace(v);
            is_exists[v] = true;
          }
        }
      }
    }

    // 사이클 존재 여부 출력
    cout << (has_cycle ? "YES" : "NO") << "\n";
  }
}
