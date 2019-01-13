#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 입력의 크기
  // num: 수를 입력받을 버퍼
  // max: 수의 최대값
  // min: 수의 최소값
  // sum: 수의 총합
  int n, num, min = 4000, max = -4000, sum = 0;
  // freq[i]: 숫자 i - 4001이 등장한 횟수
  int freq[8001] = {
      0,
  };
  // vec: 숫자를 저장할 벡터
  vector<int> vec(0, 0);
  cin >> n;
  // n번 숫자를 입력받아 num에 저장하고 처리한다
  for (int i = 0; i < n; ++i) {
    cin >> num;
    // 총합 계산
    sum += num;
    // 벡터에 값 추가
    vec.push_back(num);
    // 빈도 계산
    ++freq[num + 4000];
    // 최소 계산
    if (num < min) {
      min = num;
    }
    // 최대 계산
    if (num > max) {
      max = num;
    }
  }

  // freqMax: 빈도의 최대값, freqMost: 최빈 빈도값
  int freqMax = 0, freqMost = 0;
  // isUnique: freqMax가 유일한 최대값인지 저장하는 변수
  bool isUnique = true;
  for (int i = 0; i < 8001; ++i) {
    // freqMax를 갱신하면서 freqMost도 구한다.
    if (freq[i] > freqMax) {
      freqMax = freq[i];
      isUnique = true;
      freqMost = i;
    } else if (freq[i] == freqMax) {
      // 같은 freqMax를 갖는 경우, 처음 한번만 변경한다.
      if (isUnique) {
        isUnique = false;
        freqMost = i;
      }
    }
  }

  // 숫자 정렬
  sort(vec.begin(), vec.end());

  // 평균 계산
  cout << round((float)sum / n) << '\n';
  // 중간값 계산
  cout << vec[n / 2] << '\n';
  // 최빈값 계산
  cout << freqMost - 4000 << '\n';
  // 범위 계산
  cout << max - min << '\n';
  cout << flush;
}
