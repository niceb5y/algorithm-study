#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// n: 단어의 수
// k: 가르칠 글자의 수
// learned: 가르친 단어의 비트 마스크
int n, k, learned = 532741;
vector<string> words;

// solve(from, cnt): 앞으로 from번째 알파벳부터 가르치고 현재까지 cnt개의
// 알파벳을 가르쳤을 때, 학생들이 읽을 수 있는 단어의 수를 구하는 함수
int solve(int from, int cnt) {
  // ret: 학생들이 읽을 수 있는 단어의 수
  int ret = 0;
  // 기저: 가르칠 수 있는 글자의 수를 만족했을 때
  if (cnt == k) {
    // 몇개의 단어를 읽을 수 있는지 구한다.
    for (auto &word : words) {
      // valid: 해당 단어가 읽을 수 있는 단어인지 확인하는 변수
      bool valid = true;
      for (auto &c : word) {
        // 해당 글자를 배우지 못했으면 해당 단어는 읽을 수 없다.
        if (!(learned & (1 << (c - 'a')))) {
          valid = false;
          break;
        }
      }
      // 읽을 수 있는 단어 수만큼 ret을 증가시킨다.
      if (valid) {
        ++ret;
      }
    }
    // 결과값 반환
    return ret;
  }

  // i부터 알파벳의 끝까지 단어를 학습시킨다.
  for (int i = from; i < 26; ++i) {
    // 해당 단어를 할 수 있는 경우는 학습을 생략.
    if (learned & (1 << i))
      continue;
    // 백트래킹
    learned |= (1 << i);
    ret = max(ret, solve(i, cnt + 1));
    learned &= ~(1 << i);
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  words.resize(n);

  if (k < 5) {
    // 학습한 알파벳이 5개 미만이면 어느 단어도 읽을 수 없다.
    cout << 0 << '\n';
  } else if (k == 26) {
    // 알파벳을 모두 알고 있으면 어느 단어든 읽을 수 있다.
    cout << n << '\n';
  } else {
    // 그 외의 경우는 solve()를 통해 계산한다.
    for (auto &word : words) {
      cin >> word;
      // 앞뒤 4문자씩 제거한다.
      word = word.substr(4, word.length() - 8);
    }
    // 결과 계산
    cout << solve(0, 5) << '\n';
  }
}
