#include <iostream>
#include <queue>

using namespace std;

// BOARD_TILE: 보드 타일의 종류 ('.', '#', 'O')
enum class BOARD_TILE { EMPTY, WALL, END };
// DIRECTION: 보드를 기울일 수 있는 방향
enum class DIRECTION { UP, DOWN, LEFT, RIGHT };

// state_t: 현재 보드의 상태를 저장하는 변수
struct state_t {
  // rx, ry: 빨간 구슬의 좌표
  // bx, by: 파란 구슬의 좌표
  // depth: 보드를 기울인 횟수 (= 트리의 깊이)
  int rx, ry, bx, by, depth;
  state_t() : state_t(0, 0, 0, 0, 0) {}
  state_t(int rx, int ry, int bx, int by, int depth)
      : rx(rx), ry(ry), bx(bx), by(by), depth(depth) {}
};

// n, m: 보드의 크기
// ex, ey: 구슬을 넣을 수 있는 구멍의 좌표
// ans: 빨간 구슬이 구멍을 통해 나왔을 때, 보드를 기울인 횟수
// (파란 구슬이 나오거나, 빼낼 수 없는 경우는 -1)
int n, m, ex, ey, ans = -1;
// visited[rx][ry][bx][by]: 두 구슬이 해당 좌표를 방문한 적 있는지의 여부
bool visited[10][10][10][10] = {};
// board: 보드의 형태
BOARD_TILE board[10][10];
// state: BFS를 위해 보드의 상태들을 저장하는 큐
queue<state_t> state;

// move_ball(&x, &y, dir): 공을 이동시키는 함수
// x, y: 현재 공의 좌표
// dir: 공을 이동할 방향
void move_ball(int &x, int &y, DIRECTION dir) {
  int dx, dy;
  switch (dir) {
  case DIRECTION::UP:
    dx = 0, dy = -1;
    break;
  case DIRECTION::DOWN:
    dx = 0, dy = 1;
    break;
  case DIRECTION::LEFT:
    dx = -1, dy = 0;
    break;
  case DIRECTION::RIGHT:
    dx = 1, dy = 0;
    break;
  }
  // 벽을 만날때까지 구슬을 이동시킨다.
  while (board[y + dy][x + dx] != BOARD_TILE::WALL) {
    x += dx;
    y += dy;
    // 구슬이 이동하는 도중에 구멍에 도달하면 정지한다.
    if (x == ex && y == ey) {
      break;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  cin.ignore();
  // init: 보드의 첫 상태
  state_t init;

  for (int i = 0; i < n; ++i) {
    // buf: 문자를 읽어올 버퍼
    string buf;
    getline(cin, buf);
    // 입력에서 보드를 읽고 처리한다.
    for (int j = 0; j < m; ++j) {
      switch (buf[j]) {
      case '.':
        board[i][j] = BOARD_TILE::EMPTY;
        break;
      case '#':
        board[i][j] = BOARD_TILE::WALL;
        break;
      case 'O':
        board[i][j] = BOARD_TILE::END;
        ey = i;
        ex = j;
        break;
      case 'R':
        init.ry = i;
        init.rx = j;
        break;
      case 'B':
        init.by = i;
        init.bx = j;
        break;
      }
    }
  }

  // 처음 상태를 큐에 넣는다.
  state.push(init);
  visited[init.rx][init.ry][init.bx][init.by] = true;

  // BFS
  while (!state.empty()) {
    state_t cur = state.front();
    state.pop();
    // 기울이는 횟수는 10번 이하여야 한다.
    if (cur.depth > 10)
      break;
    // 빨간 구슬에 도달하면 결과를 출력한다.
    if (cur.rx == ex && cur.ry == ey) {
      ans = cur.depth;
      break;
    }
    // 상하좌우로 보드를 움직인다.
    for (int i = 0; i < 4; ++i) {
      // tmp: 보드의 다음 상태
      state_t tmp = cur;
      ++tmp.depth;
      // dir: 보드를 기울이는 방향
      DIRECTION dir = static_cast<DIRECTION>(i);
      // 구슬 이동
      move_ball(tmp.rx, tmp.ry, dir);
      move_ball(tmp.bx, tmp.by, dir);
      // 파란 구슬이 구멍에 도달한 경우는 제외한다.
      if (tmp.bx == ex && tmp.by == ey)
        continue;
      // 구슬이 겹치는 경우를 처리한다.
      if (tmp.rx == tmp.bx && tmp.ry == tmp.by) {
        switch (dir) {
        case DIRECTION::UP:
          cur.ry < cur.by ? ++tmp.by : ++tmp.ry;
          break;
        case DIRECTION::DOWN:
          cur.ry < cur.by ? --tmp.ry : --tmp.by;
          break;
        case DIRECTION::LEFT:
          cur.rx < cur.bx ? ++tmp.bx : ++tmp.rx;
          break;
        case DIRECTION::RIGHT:
          cur.rx < cur.bx ? --tmp.rx : --tmp.bx;
          break;
        }
      }
      // 구슬이 tmp의 지점을 방문해 본 적이 없으면 tmp를 큐에 추가한다.
      if (!visited[tmp.rx][tmp.ry][tmp.bx][tmp.by]) {
        state.push(tmp);
        visited[tmp.rx][tmp.ry][tmp.bx][tmp.by] = true;
      }
    }
  }
  // 결과 출력
  cout << ans << "\n";
}
