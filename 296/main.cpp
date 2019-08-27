#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tiii;

vector<int> parent, depth;
vector<tuple<int, int, int, int>> pos;
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
  int n;
  scanf("%d", &n);
  parent.resize(n + 1);
  depth.resize(n + 1, 1);
  pos.resize(n);

  for (int i = 0; i <= n; ++i) {
    parent[i] = i;
  }

  for (int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    pos[i] = make_tuple(a, b, c, i);
  }

  sort(pos.begin(), pos.end(),
       [](auto a, auto b) { return get<0>(a) < get<0>(b); });
  for (int i = 1; i < n; ++i) {
    edge.push(make_tuple(get<0>(pos[i]) - get<0>(pos[i - 1]),
                         get<3>(pos[i - 1]), get<3>(pos[i])));
  }

  sort(pos.begin(), pos.end(),
       [](auto a, auto b) { return get<1>(a) < get<1>(b); });
  for (int i = 1; i < n; ++i) {
    edge.push(make_tuple(get<1>(pos[i]) - get<1>(pos[i - 1]),
                         get<3>(pos[i - 1]), get<3>(pos[i])));
  }

  sort(pos.begin(), pos.end(),
       [](auto a, auto b) { return get<2>(a) < get<2>(b); });
  for (int i = 1; i < n; ++i) {
    edge.push(make_tuple(get<2>(pos[i]) - get<2>(pos[i - 1]),
                         get<3>(pos[i - 1]), get<3>(pos[i])));
  }

  int ans = 0;
  while (!edge.empty()) {
    auto [w, a, b] = edge.top();
    edge.pop();
    if (find(a) != find(b)) {
      merge(a, b);
      ans += w;
    }
  }

  printf("%d\n", ans);
}
