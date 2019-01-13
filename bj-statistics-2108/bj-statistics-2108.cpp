#include <cmath>
#include <cstdio>
#include <iostream>

/* Problem : https://www.acmicpc.net/problem/2108 */

using namespace std;

int N, cnt;
int numbers_counting[8001] = {
    0,
}; // 0 : -4000 /  1 : -3999 / ... / 4000 : 0 / 4001 : 1 / ... / 8000 : 4000

inline int idx(int idx) {
  // -4000 넣으면 0, 0넣으면 4000, 4000넣으면 8000
  return idx + 4000;
}

inline int iidx(int iidx) { return iidx - 4000; }

int main(int argc, char *argv[]) {
  int maxValue = -9999;
  int minValue = 9999;
  int user_input;
  int center_count = 0;
  int center_number = -9999;
  int sum = 0;
  int freq = 0; // 최빈값카운팅
  int freq_value = 0;
  int freq_first = 0; // 최빈값중 두 번째로 작은 값 출력 때문에
  int average;
  cin >> N; // 수의 개수 입력
  cnt = N;
  while (cnt--) {
    cin >> user_input;
    if (user_input > maxValue)
      maxValue = user_input;
    if (user_input < minValue)
      minValue = user_input;
    numbers_counting[idx(user_input)]++;
  }
  for (int i = 0; i < 8001; i++) {
    sum += numbers_counting[i] * iidx(i);
    if (freq < numbers_counting[i]) {
      // 이거 최빈값 갱신!
      freq_first = 0;             // 플래그 초기화
      freq = numbers_counting[i]; // 최빈값계산
      //  최빈값 중 두 번째로 작은 값을 출력한다. 어떻게 하지
      freq_value = iidx(i);
    } else if (freq == numbers_counting[i] && freq_first == 0) {
      // 요건 최빈값이 여러 개 있을경우!
      freq_first = 1; //플래그 on
      freq = numbers_counting[i];
      freq_value = iidx(i);
    }
    center_count += numbers_counting[i];
    if (center_number == -9999 && center_count > N / 2)
      center_number = iidx(i);
  }
  average = (int)floor((double)sum / N + 0.5);
  printf("%d\n", average);
  printf("%d\n", center_number);
  printf("%d\n", freq_value);
  printf("%d\n", maxValue - minValue);
  return 0;
}
