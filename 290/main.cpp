#include <iostream>
#include <map>
#include <vector>

using namespace std;

int cnt;

map<int, int> parent, depth, friends;
map<string, int> id;

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
    friends[pa] += friends[pb];
  } else if (depth[pb] > depth[pa]) {
    parent[pa] = pb;
    friends[pb] += friends[pa];
  } else {
    parent[pb] = pa;
    ++depth[pa];
    friends[pa] += friends[pb];
  }
}

int get_id(const string &name) {
  if (id.find(name) != id.end()) {
    return id[name];
  }
  id[name] = ++cnt;
  parent[cnt] = cnt;
  depth[cnt] = 1;
  friends[cnt] = 1;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    parent.clear();
    depth.clear();
    id.clear();
    friends.clear();
    cnt = 0;

    int f;
    cin >> f;

    while (f--) {
      string na, nb;
      cin >> na >> nb;

      int a = get_id(na), b = get_id(nb);
      merge(a, b);

      cout << friends[find(a)] << "\n";
    }
  }
}
