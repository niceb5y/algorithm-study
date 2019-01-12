#include <cstdio>

int main() {
  // n: 수의 개수
  // num: 수를 입력받을 버퍼
  int n, num;
  scanf("%d", &n);
  // freq[i]: 숫자 i + 1의 입력 횟수를 저장하는 배열
  int freq[10000] = {
      0,
  };
  // n번 수를 입력받아 freq배열에 저장한다.
  for (int i = 0; i < n; ++i) {
    scanf("%d", &num);
    ++freq[num - 1];
  }
  // 1부터 n까지 순서대로 입력횟수만큼 출력한다.
  for (int i = 0; i < 10000; ++i) {
    for (int j = 0; j < freq[i]; ++j) {
      printf("%d\n", i + 1);
    }
  }
}
