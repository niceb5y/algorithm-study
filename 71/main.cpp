#include <iostream>

using namespace std;

// node: 이진 검색 트리의 노드
// n: 노드의 개수
int node[10000], n = 0;

// print(lo, hi): [lo, hi) 범위의 이진 트리를 후위 순회하여 출력한다.
void print(const int &lo, const int &hi) {
  // root: 트리의 루트
  int &root = node[lo];
  // 기저: 노드가 1개면 출력한다.
  if (lo == hi - 1) {
    cout << root << '\n';
    return;
  }
  // 기저: 노드가 1 미만이면 탐색을 중지한다.
  if (lo > hi - 1)
    return;
  // mid: 트리의 오른쪽 서브트리가 시작하는 지점
  int mid = lo + 1;
  while (mid < hi && node[mid] < root) {
    ++mid;
  }
  // 왼쪽 서브트리 출력
  print(lo + 1, mid);
  // 오른쪽 서브트리 출력
  print(mid, hi);
  // 루트 출력
  cout << root << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin.peek() != EOF) {
    cin >> node[n++];
  }
  print(0, n - 1);
}
