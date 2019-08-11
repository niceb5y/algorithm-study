#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> board;

int eval(int r, int c) {
  int b_first = 0, w_first = 0;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          if (board[r + i][c + j] == 'B')
            ++w_first;
          else
            ++b_first;
        } else {
          if (board[r + i][c + j] == 'B')
            ++b_first;
          else
            ++w_first;
        }
      } else {
        if (j % 2 == 0) {
          if (board[r + i][c + j] == 'B')
            ++b_first;
          else
            ++w_first;
        } else {
          if (board[r + i][c + j] == 'B')
            ++w_first;
          else
            ++b_first;
        }
      }
    }
  }
  return (b_first > w_first) ? w_first : b_first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  board.resize(n, vector<char>(m));

  for (auto &row : board) {
    for (auto &c : row) {
      cin >> c;
    }
  }

  int ans = 64;

  for (int r = 0; r < n - 7; ++r) {
    for (int c = 0; c < m - 7; ++c) {
      int cur = eval(r, c);
      if (cur < ans)
        ans = cur;
    }
  }

  cout << ans << "\n";
}
