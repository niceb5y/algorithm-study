#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // m, n: 토마토를 담는 창고의 크기 n * m
  // unripened: 익지 않은 토마토의 개수
  // day: 토마토가 모두 익기 위한 최소 날짜
  int m, n, unripened = 0, day = 0;
  cin >> m >> n;
  // storage: 토마토가 들어간 창고 (n * m)
  vector<vector<short>> storage(n, vector<short>(m));
  // to_check: 오늘 검사해야 하는 토마토들의 좌표
  // temp: 다음 날에 검사해야 하는 토마토들의 좌표
  vector<pair<int, int>> to_check, temp;
  // 창고를 채운다.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> storage[i][j];
      if (storage[i][j] == 0) {
        // 익지 않은 토마토가 있는 경우 unripened를 증가시킨다.
        ++unripened;
      } else if (storage[i][j] == 1) {
        // 익은 토마토는 to_check에 추가한다.
        to_check.push_back(make_pair(i, j));
      }
    }
  }
  // 더이상 검사할 토마토가 없어질때까지 반복
  while (unripened > 0 && !to_check.empty()) {
    for (auto &pos : to_check) {
      // x, y: 검사할 토마토의 좌표
      auto [y, x] = pos;
      // ripen(x. y): 해당 좌표의 토마토를 익도록 한다.
      auto ripen = [&storage, &temp, &unripened](int x, int y) {
        if (storage[y][x] == 0) {
          storage[y][x] = 1;
          temp.push_back(make_pair(y, x));
          --unripened;
        }
      };
      // 상하좌우의 토마토를 익게 한다.
      if (x > 0)
        ripen(x - 1, y);
      if (x < m - 1)
        ripen(x + 1, y);
      if (y > 0)
        ripen(x, y - 1);
      if (y < n - 1)
        ripen(x, y + 1);
    }
    // to_check에 temp를 대입한다.
    to_check = temp;
    temp.clear();
    // 날짜 증가
    ++day;
  }
  // 결과 출력
  cout << (unripened != 0 ? -1 : day) << '\n';
}
