#include <stdio.h>

void print_repeat(char letter, int times)
{
    while(times--)  putchar(letter);
}

int main(void)
{
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N - 1; i++) {
        // * ' ' 계열. 0 -> 1 -> 2
        j = i;
        while(j--) {
            putchar('*');
            putchar(' ');
        };
        print_repeat('*', 4 * (N - i - 1) + 1);
        // ' ' * 계열 0 -> 1 -> 2
        j = i;
        while(j--) {
            putchar(' ');
            putchar('*');
        };
        putchar('\n');


        ///////////////////////////////////////////////////////////
        // 2번째 계열 줄
        j = i + 1;
        while(j--) {
            putchar('*'); //무조건
            putchar(' '); //무조건
        };
        // ' ' : 9 -> 5 -> 1
        print_repeat(' ', 4 * (N - i - 2) + 1);
        j = i + 1;
        while(j--) {
            putchar(' '); //무조건
            putchar('*'); //무조건
        };
        putchar('\n');
    }


    // 허리 : 0->2->4->6 + *
    j = N * 2 - 2;
    while(j--) {
        putchar('*');
        putchar(' ');
    }
    putchar('*');
    putchar('\n');
    // 위에걸 거꾸로
    for(i = N - 2; i >= 0; i--) {
        j = i + 1;
        while(j--) {
            putchar('*'); //무조건
            putchar(' '); //무조건
        };
        // ' ' : 9 -> 5 -> 1
        print_repeat(' ', 4 * (N - i - 2) + 1);
        j = i + 1;
        while(j--) {
            putchar(' '); //무조건
            putchar('*'); //무조건
        };
        putchar('\n');
        j = i;
        while(j--) {
            putchar('*');
            putchar(' ');
        };
        print_repeat('*', 4 * (N - i - 1) + 1);
        // ' ' * 계열 0 -> 1 -> 2
        j = i;
        while(j--) {
            putchar(' ');
            putchar('*');
        };
        putchar('\n');
    }
    return 0;
}
