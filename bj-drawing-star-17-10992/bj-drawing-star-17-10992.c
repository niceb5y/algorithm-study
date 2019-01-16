#include <stdio.h>

void print_repeat(char letter, int times)
{
    while(times--)  putchar(letter);
}

int main(void)
{
    int N, i;
    scanf("%d", &N);
    print_repeat(' ', N - 1);
    putchar('*');
    putchar('\n');
    for(i = 2; i < N; i++) {
        print_repeat(' ', N - i);
        putchar('*');
        print_repeat(' ', 2 * i - 3);
        putchar('*');
        putchar('\n');
    }
    if(N != 1)
        print_repeat('*', N * 2 - 1);
    return 0;
}
