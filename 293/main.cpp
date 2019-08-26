#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tiii;

int v, e, ans = 0;
vector<int> parent, depth;
priority_queue<tiii, vector<tiii>, greater<tiii>> edge;

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

  cin >> v >> e;
  parent.resize(v + 1);
  depth.resize(v + 1, 1);
  for (int i = 0; i <= v; ++i) {
    parent[i] = i;
  }

  while (e--) {
    int a, b, w;
    cin >> a >> b >> w;
    edge.push(make_tuple(w, a, b));
  }

  while (!edge.empty()) {
    auto [w, a, b] = edge.top();
    edge.pop();
    if (find(a) != find(b)) {
      merge(a, b);
      ans += w;
    }
  }

  cout << ans << "\n";
}
