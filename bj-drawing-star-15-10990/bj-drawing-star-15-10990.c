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
    for(i = 2; i <= N; i++) {
        print_repeat(' ', N - i);
        putchar('*');
        print_repeat(' ', 2 * i - 3);
        putchar('*');
        if(i != N) putchar('\n');
    }
    return 0;
}
