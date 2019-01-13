#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  // cin/cout 속도향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  // str[i]: i+1자리의 문자열을 저장하는 벡터
  vector<string> str[50];
  // buf: 입력받을 문자열을 저장할 버퍼
  string buf;
  // 입력 버퍼 비우기
  cin.get();
  // n번 1줄씩 읽어들여, 문자열의 길이를 구하고, str에 집어넣는다.
  for (int i = 0; i < n; ++i) {
    getline(cin, buf);
    str[buf.length() - 1].push_back(buf);
  }
  // str을 순회하며, 정렬하고 출력한다.
  for (int i = 0; i < 50; ++i) {
    // last: 중복을 확인하기위해 마지막으로 출력한 줄을 저장하는 변수
    string last = "";
    // 문자열 정렬
    sort(str[i].begin(), str[i].end());
    for (auto &line : str[i]) {
      // 중복이 아닌 경우에만 출력한다.
      if (last != line) {
        cout << line << '\n';
      }
      last = line;
    }
  }
  cout << flush;
}
