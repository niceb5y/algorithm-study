#include <algorithm>
#include <cstdio>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

const int NEG_INF = -987654321;
// n: 도시의 수
// m: 비행로의 수
// s: 시작 도시의 번호
// t: 끝 도시의 번호
// grp_no: SCC 그룹 번호
int n, m, s, t, grp_no = 1;
// visited[i]: i번 도시를 방문했는지 여부
vector<bool> visited;
// grp[i]: i번 원소가 속해있는 SCC 그룹
// grp_cnt[i]: i번째 SCC 그룹의 원소의 수
// dp[i]: i번째 도시에서 도시 t까지 여행했을때 방문할 수 있는 도시의 최대 개수
vector<int> grp, grp_cnt({0}), dp;
// grp_adj[i]: i번째 SCC 그룹과 인접한 그룹의 목록
vector<set<int>> grp_adj;
// stk: dfs가 끝난 원소를 담아둘 스택
stack<int> stk;
// path: 도시 간 경로
vector<pair<int, int>> path;

// dfs(n): 도시 n을 시작으로 DFS를 통해 도시를 순회하여 stk에 담는다.
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

// dfs_r(n): 도시 n을 시작으로 dfs()와 반대 방향으로 도시를 순회하고 그룹을
// 만든다.
void dfs_r(const int &n) {
  if (visited[n])
    return;
  visited[n] = true;
  grp[n] = grp_no;
  ++grp_cnt[grp_no];
  for (auto &p : path) {
    if (p.second == n) {
      dfs_r(p.first);
    }
  }
}

// solve(from): from부터 도시 t까지 여행했을 때 방문할 수 있는 도시의 최대
// 개수를 구한다.
int solve(const int &from) {
  // 기저: 도시 t와 같은 그룹에 속함
  if (from == grp[t])
    return grp_cnt[from];
  // 메모이제이션
  int &ret = dp[from];
  if (ret != NEG_INF) {
    return ret;
  }
  // 방문할 수 있는 도시의 최대값을 구한다.
  for (auto &adj : grp_adj[from]) {
    ret = max(ret, solve(adj) + grp_cnt[from]);
  }
  return ret;
}

int main() {
  // 초기화
  scanf("%d %d %d %d", &n, &m, &s, &t);
  visited.resize(n + 1, false);
  grp.resize(n + 1);
  path.resize(m);
  for (auto &p : path) {
    scanf("%d %d", &p.first, &p.second);
  }
  // DFS로 각 지점을 순회하고 각 지점이 끝나는 순서대로 스택에 삽입한다.
  for (int i = 1; i <= n; ++i) {
    if (!visited[i])
      dfs(i);
  }
  // visited 초기화
  fill(visited.begin(), visited.end(), false);
  // 스택 순서대로 dfs_r을 통해 순회하여 SCC를 구한다.
  while (!stk.empty()) {
    if (!visited[stk.top()]) {
      grp_cnt.emplace_back(0);
      dfs_r(stk.top());
      ++grp_no;
    }
    stk.pop();
  }
  // 초기화
  grp_adj.resize(grp_no);
  dp.resize(grp_no, NEG_INF);
  // SCC 그룹의 인접 그룹을 구한다.
  for (auto &p : path) {
    if (grp[p.first] != grp[p.second])
      grp_adj[grp[p.first]].emplace(grp[p.second]);
  }
  // 결과 출력
  printf("%d\n", (solve(grp[s]) < 0 ? 0 : solve(grp[s])));
}
