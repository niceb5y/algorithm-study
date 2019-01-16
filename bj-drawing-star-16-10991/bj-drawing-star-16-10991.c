#include <stdio.h>

void print_repeat(char letter, int times)
{
    while(times--)  putchar(letter);
}

int main(void)
{
    int N, i, j;
    scanf("%d", &N);
    print_repeat(' ', N - 1);
    putchar('*');
    putchar('\n');
    for(i = 2; i <= N; i++) {
        print_repeat(' ', N - i);
        for(j = 0; j < i - 1; j++) {
            putchar('*');
            putchar(' ');
        }
        putchar('*');
        if(i != N) putchar('\n');
    }
    return 0;
}
