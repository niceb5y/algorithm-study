#include <stdio.h>
#include <unistd.h>
#include "../util/util.h"
/* Problem: https://www.acmicpc.net/problem/1475 */

int main(int argc, char *argv[])
{
    int i, counter_max = 0, counter_another_max = 0;
    char N[8]; // 방 번호 N (0 ~ 1,000,000)
    int counter[10] = {0, }; // 0 ~ 9 가 몇 개 필요한지를 센다
    scanf("%s", N);
    for (i = 0; N[i] != '\0'; i++) { // 999966 -> 3
        if(N[i] - '0' == 6 || N[i] - '0' == 9) {
            counter[N[i] - '0'] += 1;
            counter_max = counter_max < counter[6]+counter[9] ? counter[6]+counter[9] : counter_max;
        }
        else {
            counter[N[i] - '0'] += 1;
            counter_another_max = counter_another_max < counter[N[i] - '0'] ? counter[N[i] - '0'] : counter_another_max;
        }
         //printf("최대 횟수(69) : %d 최대 횟수(다른거) : %d\n", counter_max, counter_another_max);
    }
    //for (i = 0; i < 10; i++) {
    //    printf("%d ", counter[i]);
    //}

    //putchar('\n');
    if(counter_max * 2 <= counter_another_max) {
        printf("%d\n", counter_another_max);
    }
    else {
        // counter_max / 2 + (counter_max % 2) 이랑 counter_another_max 중에 큰 값
        int tmp = counter_max / 2 + (counter_max % 2) > counter_another_max ? counter_max / 2 + (counter_max % 2) : counter_another_max;
        printf("%d\n", tmp);
    }

    return unlink(*argv);
}
