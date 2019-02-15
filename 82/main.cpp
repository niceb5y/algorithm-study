#include <iostream>

using namespace std;

// str1: 문자열 1
// str2: 문자열 2
// str3: 문자열 3
string str1, str2, str3;

// cache: 메모라이제이션을 위한 캐시
int cache[101][101][101];

// lcs(len1, len2, len3): 세 문자열(str1[0...len1], str2[0...len2],
// str3[0...len3])의 부분 문자열 중 가장 긴 문자열의 길이를 찾는다.
int lcs(int len1, int len2, int len3) {
  if (len1 == 0 || len2 == 0 || len3 == 0) {
    // 기저: 한 문자열의 길이가 0이면 lcs의 길이는 0이다.
    return 0;
  }
  // ret: 메모라이제이션 된 값
  int &ret = cache[len1 - 1][len2 - 1][len3 - 1];
  if (ret != -1) {
    return ret;
  }
  if (str1[len1 - 1] == str2[len2 - 1] && str1[len1 - 1] == str3[len3 - 1]) {
    // 마지막 문자열이 같으면, 마지막 문자를 제외하고 재귀호출을 한다.
    ret = lcs(len1 - 1, len2 - 1, len3 - 1) + 1;
  } else {
    // 그렇지 않은 경우, str1과 str2d와 str3중에서 마지막 문자를 각각 제외하여
    // 재귀호출 하고 더 큰 값을 구하여 반환한다.
    ret = max(max(lcs(len1 - 1, len2, len3), lcs(len1, len2 - 1, len3)),
              lcs(len1, len2, len3 - 1));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // 문자열 읽어오기
  getline(cin, str1);
  getline(cin, str2);
  getline(cin, str3);
  // x, y, z: str1, str2, str3의 문자열의 길이
  int x = str1.length(), y = str2.length(), z = str3.length();
  // 캐시 초기화
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      for (int k = 0; k < z; ++k) {
        cache[i][j][k] = -1;
      }
    }
  }
  // 결과 출력
  cout << lcs(x, y, z) << endl;
}
