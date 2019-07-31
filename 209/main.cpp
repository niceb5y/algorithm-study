#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

void move(DIRECTION dir) {
  queue<int> candidate, result;
  switch (dir) {
  case UP:
    for (int c = 0; c < N; ++c) {
      for (int r = 0; r < N; ++r) {
        if (board[r][c] != 0) {
          candidate.push(board[r][c]);
          board[r][c] = 0;
        }
      }
      while (!candidate.empty()) {
        int cur = candidate.front();
        candidate.pop();
        if (!candidate.empty() && cur == candidate.front()) {
          cur *= 2;
          candidate.pop();
        }
        result.push(cur);
      }
      for (int r = 0; r < N && !result.empty(); ++r) {
        board[r][c] = result.front();
        result.pop();
      }
    }
    break;
  case DOWN:
    for (int c = 0; c < N; ++c) {
      for (int r = N - 1; r >= 0; --r) {
        if (board[r][c] != 0) {
          candidate.push(board[r][c]);
          board[r][c] = 0;
        }
      }
      while (!candidate.empty()) {
        int cur = candidate.front();
        candidate.pop();
        if (!candidate.empty() && cur == candidate.front()) {
          cur *= 2;
          candidate.pop();
        }
        result.push(cur);
      }
      for (int r = 0; r < N && !result.empty(); ++r) {
        board[r][c] = result.front();
        result.pop();
      }
    }
    break;
  case LEFT:
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        if (board[r][c] != 0) {
          candidate.push(board[r][c]);
          board[r][c] = 0;
        }
      }
      while (!candidate.empty()) {
        int cur = candidate.front();
        candidate.pop();
        if (!candidate.empty() && cur == candidate.front()) {
          cur *= 2;
          candidate.pop();
        }
        result.push(cur);
      }
      for (int c = 0; c < N && !result.empty(); ++c) {
        board[r][c] = result.front();
        result.pop();
      }
    }
    break;
  case RIGHT:
    for (int r = 0; r < N; ++r) {
      for (int c = N - 1; c >= 0; --c) {
        if (board[r][c] != 0) {
          candidate.push(board[r][c]);
          board[r][c] = 0;
        }
      }
      while (!candidate.empty()) {
        int cur = candidate.front();
        candidate.pop();
        if (!candidate.empty() && cur == candidate.front()) {
          cur *= 2;
          candidate.pop();
        }
        result.push(cur);
      }
      for (int c = N - 1; c >= 0 && !result.empty(); --c) {
        board[r][c] = result.front();
        result.pop();
      }
    }
    break;
  }
}

void print() {
  for (auto &row : board) {
    for (auto &block : row) {
      cout << block << " ";
    }
    cout << endl;
  }
}

int eval() {
  int ret = 0;
  for (auto &row : board) {
    for (auto &block : row) {
      ret = max(ret, block);
    }
  }
  return ret;
}

int solve(int depth) {
  if (depth == 0)
    return eval();
  int ret = 0;
  vector<vector<int>> backup = board;
  for (int i = 0; i < 4; ++i) {
    move((DIRECTION)i);
    ret = max(ret, solve(depth - 1));
    board = backup;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  board.resize(N, vector<int>(N));

  for (auto &row : board) {
    for (auto &block : row) {
      cin >> block;
    }
  }

  cout << solve(5) << endl;
}
