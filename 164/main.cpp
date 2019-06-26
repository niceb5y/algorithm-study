#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> node;
const int INF = 987654321;

int main() {
  int v, e, k;
  scanf("%d %d %d", &v, &e, &k);
  vector<int> dist(v + 1, INF);

  vector<vector<node>> adj(v + 1, vector<node>());
  for (int i = 0; i < e; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back(make_pair(c, b));
  }

  priority_queue<node, vector<node>, greater<node>> pq;
  dist[k] = 0;
  pq.push(make_pair(0, k));

  while (!pq.empty()) {
    node top = pq.top();
    pq.pop();

    if (dist[top.second] < top.first)
      continue;

    dist[top.second] = top.first;
    for (auto &edge : adj[top.second]) {
      if (dist[edge.second] > edge.first + dist[top.second]) {
        dist[edge.second] = edge.first + dist[top.second];
        pq.push(make_pair(dist[edge.second], edge.second));
      }
    }
  }

  for (int i = 1; i <= v; ++i) {
    if (dist[i] == INF) {
      printf("INF\n");
    } else {
      printf("%d\n", dist[i]);
    }
  }
}
