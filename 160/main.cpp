#include <algorithm>
#include <cstdio>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector<bool> visited;
vector<set<int>> group(1, set<int>());
stack<int> stk;
vector<pair<int, int>> path;

void dfs(const int &n) {
  if (visited[n])
    return;
  visited[n] = true;
  for (auto &p : path) {
    if (p.first == n) {
      dfs(p.second);
    }
  }
  stk.emplace(n);
}
void dfs_r(const int &n) {
  if (visited[n])
    return;
  visited[n] = true;
  group[cnt].insert(n);
  for (auto &p : path) {
    if (p.second == n) {
      dfs_r(p.first);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  visited.resize(n + 1, false);
  path.resize(m);
  for (auto &p : path) {
    scanf("%d %d", &p.first, &p.second);
  }
  for (int i = 1; i <= n; ++i) {
    if (!visited[i])
      dfs(i);
  }
  fill(visited.begin(), visited.end(), false);
  while (!stk.empty()) {
    if (!visited[stk.top()]) {
      dfs_r(stk.top());
      group.push_back(set<int>());
      ++cnt;
    }
    stk.pop();
  }
  group.pop_back();
  printf("%d\n", cnt);
  sort(group.begin(), group.end(),
       [](set<int> a, set<int> b) { return *a.begin() < *b.begin(); });
  for (int i = 0; i < cnt; ++i) {
    for (auto &j : group[i]) {
      printf("%d ", j);
    }
    printf("-1\n");
  }
}
