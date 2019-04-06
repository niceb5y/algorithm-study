#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// tree: 땅에 심어져 있는 나무의 종류와 수를 저장하는 구조체
struct tree {
  char type;
  int count;
};

// arr[i][j]: 구역 [i][j]에 심어져 있는 나무의 종류와 수를 저장하는 변수
tree arr[1501][1501];

// r, c: 땅의 크기 (행, 열)
// sum_a[i][j]: i열의 [0, j]행의 부분합
// sum_b[i][j]: j행의 [0, i]열의 부분합
int r, c, sum_a[1501][1501] = {}, sum_b[1501][1501] = {}, dp[1501][1501];

// solve(i, j): i행 j열까지 계산했을 때 두 나무의 합의 최대를 구하는 함수
int solve(const int &i, const int &j) {
  int &ret = dp[i][j];
  if (ret != -1) {
    return ret;
  }

  // 기저: 1열 1행에 도달.
  if (i == 1 && j == 1)
    return 0;

  // 왼쪽으로 이동
  if (i > 1)
    ret = max(ret, solve(i - 1, j) + sum_a[i][j - 1]);

  // 위로 이동
  if (j > 1)
    ret = max(ret, solve(i, j - 1) + sum_b[i - 1][j]);

  // 왼쪽 위 대각선 이동
  if (i > 1 && j > 1)
    ret = max(ret, solve(i - 1, j - 1) + sum_a[i][j - 1] + sum_b[i - 1][j]);

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 초기화
  cin >> r >> c;
  fill_n(&dp[0][0], 1501 * 1501, -1);

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      string buf;
      cin >> buf;

      arr[i][j].type = buf[0];
      arr[i][j].count = stoi(buf.substr(1, buf.length() - 1));

      sum_a[i][j] = sum_a[i][j - 1] + (buf[0] == 'A' ? arr[i][j].count : 0);
      sum_b[i][j] = sum_b[i - 1][j] + (buf[0] == 'B' ? arr[i][j].count : 0);
    }
  }

  // 결과 출력
  cout << solve(r, c) << endl;
}
