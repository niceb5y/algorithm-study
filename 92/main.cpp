#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 문자 '0'을 입력받기 전까지 반복
  while (cin.peek() != '0') {
    // n: 입력받을 문자열의 줄의 수
    int n;
    cin >> n;
    // 버퍼 비우기
    cin.ignore();
    // lines[n]: n줄의 문자열을 저장할 벡터
    vector<string> lines(n);
    for (auto &line : lines) {
      getline(cin, line);
    }
    // row, col: (0부터 시작하는) 공의 위치
    int row = 0, col = 0;
    // 공이 맨 아래로 떨어질 때까지 반복
    while (row < n) {
      // 공이 문자열의 길이 범위 내에 존재할때만 col 변화가 있음.
      if (col + 1 < (int)lines[row].length()) {
        // 띄어쓰기가 없는 경우엔 위치가 문자열의 길이가 된다.
        col = min(lines[row].find_first_of(" ", col), lines[row].length());
      }
      // 줄 증가
      ++row;
    }
    // 결과 출력
    cout << col + 1 << '\n';
  }
}
