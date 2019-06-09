#include <iostream>
#include <vector>

using namespace std;

// adj[i]: 사람 i가 할 수 있는 일들의 배열
vector<vector<int>> adj;
// visited[i]: i번 사람을 순회하였는지 여부
vector<bool> visited;
// match[i]: i번 일을 하는 사람의 번호
vector<int> match;

bool DFS(int a) {
  // 이미 순회가 완료된 사람은 매칭 불가
  if (visited[a])
    return false;
  visited[a] = true;
  // 일을 순회하며 가능한 일을 매칭시킨다.
  for (auto &b : adj[a]) {
    // 일이 매칭될 수 있거나, 이미 다른 사람에게 일이 매칭되었지만 그
    // 사람에게 다른 일을 대신 매칭시킬 수 있는 경우
    if (match[b] == -1 || DFS(match[b])) {
      match[b] = a;
      // 일이 매칭 됨
      return true;
    }
  }
  // 일이 매칭 되지 않음
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 사람의 수
  // m: 일의 수
  // k: 일을 두 번 처리할 수 있는 사람의 수
  // first: 첫번째 일의 매칭 수
  // second: 두번째 일의 매칭 수
  int n, m, k, first = 0, second = 0;
  // 초기화
  cin >> n >> m >> k;
  adj.resize(n + 1);
  visited.resize(n + 1);
  match.resize(m + 1, -1);
  for (int i = 1; i <= n; ++i) {
    int sz;
    cin >> sz;
    adj[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      cin >> adj[i][j];
    }
  }
  // 사람들을 순회하여 일을 매칭한다.
  // 첫번째 매칭
  for (int i = 1; i <= n; ++i) {
    fill(visited.begin(), visited.end(), false);
    if (DFS(i))
      ++first;
  }
  // 두번째 매칭
  for (int i = 1; i <= n; ++i) {
    fill(visited.begin(), visited.end(), false);
    if (DFS(i))
      ++second;
    // 일을 두 개 이상 처리한 사람이 k명이 되면 종료.
    if (second == k)
      break;
  }

  // 결과 출력
  cout << first + second << "\n";
}
