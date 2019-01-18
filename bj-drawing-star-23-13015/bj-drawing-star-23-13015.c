#include <stdio.h>

void print_repeat(char letter, int times)
{
    while(times--)  putchar(letter);
}

int main(void)
{
    int N;
    int i;
    scanf("%d", &N);
    print_repeat('*', N);
    print_repeat(' ', 2 * N - 3);
    print_repeat('*', N);
    putchar('\n');
    for(i = 0; i <= N - 3; i++) {
        print_repeat(' ', i+1);
        putchar('*');
        print_repeat(' ', N-2);
        putchar('*');
        print_repeat(' ', 2 * (N - i - 1) - 3);// 5 3 1
        putchar('*');
        print_repeat(' ', N-2);
        putchar('*');
        putchar('\n');
    }
    print_repeat(' ', N - 1);
    putchar('*');
    print_repeat(' ', N-2);
    putchar('*');
    print_repeat(' ', N-2);
    putchar('*');
    putchar('\n');
    for(i = 0; i <= N - 3; i++) {
        print_repeat(' ', N - i - 2);
        putchar('*');
        print_repeat(' ', N-2);
        putchar('*');
        print_repeat(' ', 2 * i + 1);// 1 3 5
        putchar('*');
        print_repeat(' ', N-2);
        putchar('*');
        putchar('\n');
    }
    print_repeat('*', N);
    print_repeat(' ', 2 * N - 3);
    print_repeat('*', N);
    return 0;
}
