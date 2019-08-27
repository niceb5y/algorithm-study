#include <cmath>
#include <cstdio>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

typedef tuple<double, int, int> tdii;

vector<int> parent, depth;
vector<pair<int, int>> pos;
priority_queue<tdii, vector<tdii>, greater<tdii>> edge;

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
  int n;
  scanf("%d", &n);
  parent.resize(n + 1);
  depth.resize(n + 1, 1);
  pos.resize(n + 1);
  for (int i = 0; i <= n; ++i) {
    parent[i] = i;
  }

  for (int i = 1; i <= n; ++i) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    pos[i] = make_pair(a, b);
    for (int j = 1; j < i; ++j) {
      edge.push(make_tuple(sqrt(pow(pos[i].first - pos[j].first, 2) +
                                pow(pos[i].second - pos[j].second, 2)),
                           i, j));
    }
  }

  double ans = 0;
  while (!edge.empty()) {
    auto [w, a, b] = edge.top();
    edge.pop();
    if (find(a) != find(b)) {
      merge(a, b);
      ans += w;
    }
  }

  printf("%.2lf\n", ans);
}
