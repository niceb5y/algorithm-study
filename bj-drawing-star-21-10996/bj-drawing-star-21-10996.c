#include <stdio.h>

void print_pattern_s(const char pattern, const char separator, int times)
{
    while(times--) {
        putchar(pattern);
        if(times) {
            putchar(separator);
        }
    }
}

void print_repeat_s(const char * string, int times)
{
    while(times--)  printf("%s", string);
}

int main(void)
{
    int N, i;
    scanf("%d", &N);
    if(N == 1) { putchar('*'); return 0; }
    for(i = 0; i < N; i++) {
        // 첫째 줄 계열 ()
        print_pattern_s('*', ' ', (N + N % 2) / 2);
        ///////////////
        putchar('\n');
        ///////////////
        // 둘째 줄 계열
        print_repeat_s(" *", N / 2);
        ///////////////
        putchar('\n');
        ///////////////
    }
    return 0;
}
