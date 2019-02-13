#include <iostream>
#include <vector>

using namespace std;

int main() {
  // t, p: 문자열 t 안에 존재하는지 검사할 문자열 p
  string t, p;
  // 문자열 t, p를 읽어들인다.
  getline(cin, t);
  getline(cin, p);
  // len_t, len_p: 문자열 t, p의 길이
  const int len_t = t.length(), len_p = p.length();
  // k[i]: p[0...i]에서 접두사 == 접미사인 문자열의 길이
  // ans: 문자열 t에서 문자열 p가 나타나는 위치
  vector<int> k(len_p, 0), ans;
  // 전처리 과정: k의 값들을 미리 구한다.
  for (int i = 1, j = 0; i < len_p; ++i) {
    while (j > 0 && p[i] != p[j]) {
      // 문자열이 서로 다른 경우 접두사와 접미사가 같아질 때까지 j를 변화시킨다.
      j = k[j - 1];
    }
    if (p[i] == p[j]) {
      // p[i]와 p[j]가 같으면 j값을 증가시키고 k[i]에 저장한다.
      ++j;
      k[i] = j;
    }
  }
  // k를 통해 문자열 t에 문자열 p가 있는 위치를 구한다.
  for (int i = 0, j = 0; i < len_t; ++i) {
    while (j > 0 && t[i] != p[j]) {
      // 문자열이 서로 다른 경우 k를 참고하여 부분 문자열이 같은만큼 건너뛴다.
      j = k[j - 1];
    }
    if (t[i] == p[j]) {
      if (j == len_p - 1) {
        // p가 존재하면 위치를 ans에 추가한다.
        ans.push_back(i - j + 1);
        j = k[j];
      } else {
        // 다음 문자열을 검사한다.
        ++j;
      }
    }
  }
  // 결과 출력
  const int sz_ans = ans.size();
  cout << sz_ans << '\n';
  for (int i = 0; i < sz_ans; ++i) {
    cout << ans[i] << (i == sz_ans - 1 ? "\n" : " ");
  }
}
