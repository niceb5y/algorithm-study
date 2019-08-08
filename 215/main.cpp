#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int H, W, N;
    scanf("%d%d%d", &H, &W, &N);
    printf("%d%02d\n", (N - 1) % H + 1, (N - 1) / H + 1);
  }
}
