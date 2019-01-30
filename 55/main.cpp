#include <iostream>
#include <vector>

using namespace std;

// eval(num, cache, x, y): (x, y) 지점에서 사각형의 제일 오른쪽 아래 칸으로 갈
// 수 있는 경우의 수
int eval(const vector<vector<int>> &num, vector<vector<int>> &cache,
         const int &x, const int &y) {
  //  m, n: 사각형의 크기
  int m = num.size(), n = num[0].size();
  // ret: 함수의 결과값의 캐시
  int &ret = cache[y][x];
  // 기저: 사각형의 가장 오른쪽 아래 칸에 있는 경우.
  if (y == m - 1 && x == n - 1) {
    ret = 1;
    return ret;
  }
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  // 4방향 중에 갈 수 있는 경우의 수를 구해 전부 더한다.
  if (x != 0 && num[y][x] > num[y][x - 1]) {
    ret += eval(num, cache, x - 1, y);
  }
  if (y != 0 && num[y][x] > num[y - 1][x]) {
    ret += eval(num, cache, x, y - 1);
  }
  if (x != n - 1 && num[y][x] > num[y][x + 1]) {
    ret += eval(num, cache, x + 1, y);
  }
  if (y != m - 1 && num[y][x] > num[y + 1][x]) {
    ret += eval(num, cache, x, y + 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // m, n: 사각형의 크기
  int m, n;
  cin >> m >> n;
  // num[y][x]: (x, y)지점의 높이
  // cache[y][x]: (x, y)지점에서 사각형의 오른쪽 끝으로 갈 수 있는 방법의 수
  vector<vector<int>> num(m, vector<int>(n)), cache(m, vector<int>(n, -1));
  for (auto &row : num) {
    for (auto &elem : row) {
      cin >> elem;
    }
  }
  // 결과값 출력
  cout << eval(num, cache, 0, 0) << endl;
}
