#include <stdio.h>

void print_repeat_s(const char * string, int times)
{
    while(times--)  printf("%s", string);
}

int main(void)
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        if(i % 2 == 0) {
            // * ' ' 계열
            print_repeat_s("* ", N - 1);
            putchar('*');
        } else {
            // ' ' * 계열
            print_repeat_s(" *", N);
        }
        putchar('\n');
    }
    return 0;
}
