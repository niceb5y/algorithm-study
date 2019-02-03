#include <algorithm>
#include <cstdio>

// eval(r,c): 좌표 (r,c)의 숫자를 구하는 함수
int eval(int r, int c) {
  if (r >= -c) {
    if (r >= c) {
      return (4 * r + 3) * r + c + 1;
    } else {
      return eval(c - 1, c - 1) + c - r;
    }
  } else {
    if (r < c) {
      return (4 * r + 1) * r - c + 1;
    } else {
      return eval(c, c + 1) - c + r + 1;
    }
  }
}

// get_digit(n): 숫자 n의 자리수를 구하는 함수
int get_digit(int n) {
  int digit = 0;
  do {
    ++digit;
    n /= 10;
  } while (n > 0);
  return digit;
}

int main() {
  // r1, c1: 좌표 (r1, c1)
  // r2, c2: 좌표 (r2, c2)
  // digit: 좌표 ([r1...r2], [c1...c2])중 가장 큰 수의 자리수
  int r1, c1, r2, c2, digit;
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
  // 최대 자리수를 구한다.
  digit = get_digit(std::max(std::max(eval(r1, c1), eval(r1, c2)),
                             std::max(eval(r2, c1), eval(r2, c2))));
  for (int r = r1; r <= r2; ++r) {
    for (int c = c1; c <= c2; ++c) {
      // 형식에 맞게 결과 출력
      printf((c == c1 ? "%*d" : " %*d"), digit, eval(r, c));
    }
    printf("\n");
  }
}
