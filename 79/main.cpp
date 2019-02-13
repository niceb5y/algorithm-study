#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// sudoku: 스도쿠를 저장할 배열
int sudoku[9][9];
// to_solve: 풀어야 하는 칸의 위치를 저장할 벡터
vector<pair<int, int>> to_solve;

// validate(x, y, num): sudoku[y][x]에 num이 적합한지 검사한다.
bool validate(int x, int y, int num) {
  for (int i = 0; i < 9; ++i) {
    // 가로 세로를 검사한다.
    if (sudoku[y][i] == num || sudoku[i][x] == num) {
      return false;
    }
  }
  // 3 * 3 구역을 검사한다.
  for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; ++i) {
    for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; ++j) {
      if (sudoku[i][j] == num) {
        return false;
      }
    }
  }
  return true;
}

// solve(n): to_solve[n]의 위치에 있는 칸을 채운다.
void solve(int n) {
  // 기저: 모든 칸이 다 찬 경우 결과를 출력한다.
  if (n == (int)to_solve.size()) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cout << sudoku[i][j] << (j == 8 ? '\n' : ' ');
      }
    }
    exit(0);
  }
  auto [y, x] = to_solve[n];
  // 백트래킹으로 스도쿠의 칸을 채워넣는다.
  for (int i = 1; i <= 9; ++i) {
    if (validate(x, y, i)) {
      sudoku[y][x] = i;
      solve(n + 1);
      sudoku[y][x] = 0;
    }
  }
}

int main() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> sudoku[i][j];
      if (sudoku[i][j] == 0) {
        to_solve.push_back(make_pair(i, j));
      }
    }
  }
  solve(0);
}
