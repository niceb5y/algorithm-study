#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // n, m: 성곽의 크기
  // room_count: 방의 개수
  int n, m, room_count = 0;
  cin >> n >> m;

  // wall[i][j]: i열 j행의 벽
  // room[i][j]: i열 j행의 방 번호
  vector<vector<int>> wall(m, vector<int>(n)), room(m, vector<int>(n, -1));
  // area[i]: 방 번호 i번의 넓이
  vector<int> area;

  // 좌표를 순회하며 벽을 입력받는다.
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> wall[i][j];
    }
  }

  // 좌표를 순회하며 BFS를 통해 구역을 분할한다.
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      // 이미 방문했던 좌표의 경우 다시 방문하지 않는다.
      if (room[i][j] != -1)
        continue;
      // room_size: 방의 넓이
      int room_size = 0;
      // q: BFS를 위한 큐
      queue<pair<int, int>> q;
      // 현재 위치를 큐에 집어넣는다.
      q.emplace(make_pair(i, j));

      // Queue를 이용한 BFS
      while (!q.empty()) {
        // row, col: 좌표
        int row = q.front().first, col = q.front().second;
        // 좌표 유효성 검사
        if (room[row][col] != -1) {
          q.pop();
          continue;
        }
        room[row][col] = room_count;
        ++room_size;
        // cur: 현재 위치의 벽
        int cur = wall[row][col];
        // 서쪽 벽 검사
        if (!(cur & 1))
          q.emplace(make_pair(row, col - 1));
        // 북쪽 벽 검사
        if (!(cur & 2))
          q.emplace(make_pair(row - 1, col));
        // 동쪽 벽 검사
        if (!(cur & 4))
          q.emplace(make_pair(row, col + 1));
        // 남쪽 벽 검사
        if (!(cur & 8))
          q.emplace(make_pair(row + 1, col));
        // 현재 원소를 뽑아낸다.
        q.pop();
      }
      // 방 넓이를 배열에 추가한다.
      area.push_back(room_size);
      // 방의 개수 증가
      ++room_count;
    }
  }
  // max_area: 방의 넓이의 최대값
  int max_area = 0;
  // area를 순회하며 최대값을 구한다.
  for (auto &i : area) {
    max_area = max(max_area, i);
  }

  // max_sum_area: 두 방을 합친 넓이의 최댓값
  int max_sum_area = 0;
  // 인접한 두 좌표의 방이 다른 경우 합친 넓이를 구하고, 최댓값을 갱신한다.
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      // 좌우 인접 확인
      if (j > 0 && room[i][j] != room[i][j - 1]) {
        max_sum_area =
            max(max_sum_area, area[room[i][j]] + area[room[i][j - 1]]);
      }
      // 상하 인접 확인
      if (i > 0 && room[i][j] != room[i - 1][j]) {
        max_sum_area =
            max(max_sum_area, area[room[i][j]] + area[room[i - 1][j]]);
      }
    }
  }

  // 결과 출력
  cout << room_count << "\n" << max_area << "\n" << max_sum_area << "\n";
}
