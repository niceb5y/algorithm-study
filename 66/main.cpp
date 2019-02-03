#include <iostream>

using namespace std;

// n: 체스판의 폭
// board: 체스판에 퀸이 놓인 위치를 저장하는 변수
int n, board[15];

// place(): n*n의 칸을 가지는 체스판에 퀸을 놓는 경우의 수
int place(const int &depth) {
  // 기저: 체스판의 마지막에 도달하면 값을 반환한다.
  if (depth == n)
    return 1;
  // sum: 퀸을 놓는 경우의 수
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    // 해당 행에 이미 퀸이 있으면 넘어간다.
    if (board[i] != -1)
      continue;
    // ok: 해당 칸에 퀸을 놓는게 유효한지 저장하는 변수
    int ok = true;
    for (int j = 0; j < n; ++j) {
      // 대각선에 퀸이 있는지 검사한다.
      if (board[j] != -1 && abs(i - j) == abs(depth - board[j])) {
        ok = false;
      }
    }
    if (ok) {
      // 퀸을 놓는다.
      board[i] = depth;
      // 경우의 수를 더한다.
      sum += place(depth + 1);
      // 퀸을 뺀다.
      board[i] = -1;
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  // board 초기화
  for (auto &x : board) {
    x = -1;
  }
  // 결과 출력
  cout << place(0) << '\n';
}
