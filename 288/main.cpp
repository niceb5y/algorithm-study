#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> parent, depth;

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

  cin >> n >> m;

  parent.resize(n + 1);
  depth.resize(n + 1, 1);

  for (int i = 0; i <= n; ++i) {
    parent[i] = i;
  }

  while (m--) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 0)
      merge(a, b);
    else
      cout << (find(a) == find(b) ? "YES" : "NO") << "\n";
  }
}
