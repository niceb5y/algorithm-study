#include <iostream>
#include <stack>

using namespace std;

// str1: 문자열 1
// str2: 문자열 2
string str1, str2;

// cache: 메모라이제이션을 위한 캐시
int cache[1000][1000];

// lcs(len1, len2): 두 문자열(str1[0...len1], str2[0...len2])의 부분 문자열 중
// 가장 긴 문자열의 길이를 찾는다.
int lcs(int len1, int len2) {
  if (len1 == 0 || len2 == 0) {
    // 기저: 한 문자열의 길이가 0이면 길이는 0이다.
    return 0;
  }
  // ret: 메모라이제이션 된 값
  int &ret = cache[len1 - 1][len2 - 1];
  if (ret != -1) {
    // 마지막 문자열이 같으면, 마지막 문자를 제외하고 재귀호출을 한다.
    return ret;
  }
  if (str1[len1 - 1] == str2[len2 - 1]) {
    // 마지막 문자열이 같으면, 마지막 문자를 제외하고 재귀호출을 한다.
    ret = lcs(len1 - 1, len2 - 1) + 1;
  } else {
    // 그렇지 않은 경우, str1과 str2에서 마지막 문자를 각각 제외하여 재귀호출
    // 하고 더 큰 값을 구하여 반환한다.
    ret = max(lcs(len1 - 1, len2), lcs(len1, len2 - 1));
  }
  return ret;
}

void lcs2(int len1, int len2) {
  // n, m: 문자열 1, 2의 인덱스
  int n = len1 - 1, m = len2 - 1;
  // lcs_string: LCS 문자열을 담을 스택
  stack<char> lcs_string;
  while (n >= 0 && m >= 0) {
    if (str1[n] == str2[m]) {
      // 두 문자가 같으면 문자를 스택에 넣는다
      lcs_string.push(str1[n]);
      --n;
      --m;
    } else if (cache[n][m] == cache[n - 1][m]) {
      --n;
    } else {
      --m;
    }
  }
  // 스택이 빌 때까지 pop하고 출력한다.
  while (!lcs_string.empty()) {
    cout << lcs_string.top();
    lcs_string.pop();
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // 문자열 읽어오기
  getline(cin, str1);
  getline(cin, str2);
  // n, m: str1, str2의 문자열의 길이
  int n = str1.length(), m = str2.length();
  // 캐시 초기화
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cache[i][j] = -1;
    }
  }
  // 값 출력
  cout << lcs(n, m) << endl;
  lcs2(n, m);
}
