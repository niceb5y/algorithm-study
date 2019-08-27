#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tiii;

vector<int> parent, depth;
priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

int find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
  int pa = find(a), pb = find(b);
  if (pa == find(pb)) {
    return;
  } else if (depth[pa] > depth[pb]) {
    parent[pb] = pa;
  } else if (depth[pb] > depth[pa]) {
    parent[pa] = pb;
  } else {
    parent[pb] = pa;
    ++depth[pa];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int n, m, k;
    cin >> n >> m >> k;

    if (n == 0 && m == 0 && k == 0)
      break;

    parent.resize(n + 1);
    depth.resize(n + 1);

    vector<tuple<char, int, int>> edge;
    while (m--) {
      char c;
      int f, t;
      cin >> c >> f >> t;
      edge.push_back(make_tuple(c, f, t));
    }

    int red_first = 0, blue_first = 0;

    for (int i = 0; i <= n; ++i) {
      depth[i] = 1;
      parent[i] = i;
    }
    for (auto &e : edge) {
      auto [c, f, t] = e;
      pq.push(make_tuple(c == 'R' ? 0 : 1, f, t));
    }
    while (!pq.empty()) {
      auto [w, a, b] = pq.top();
      pq.pop();
      if (find(a) != find(b)) {
        merge(a, b);
        if (w == 1)
          ++red_first;
      }
    }

    for (int i = 0; i <= n; ++i) {
      depth[i] = 1;
      parent[i] = i;
    }
    for (auto &e : edge) {
      auto [c, f, t] = e;
      pq.push(make_tuple(c == 'B' ? 0 : 1, f, t));
    }
    while (!pq.empty()) {
      auto [w, a, b] = pq.top();
      pq.pop();
      if (find(a) != find(b)) {
        merge(a, b);
        if (w == 0)
          ++blue_first;
      }
    }
    cout << ((red_first <= k && k <= blue_first) ? 1 : 0) << "\n";
  }
}
