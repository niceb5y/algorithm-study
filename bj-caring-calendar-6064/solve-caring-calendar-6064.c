#include <stdio.h>

/* Problem: https://www.acmicpc.net/problem/6064 */

int LCM(int M, int N)
{
    int i, j;
    int LCM;
    j = M > N ? M : N;
    for(i = j; ;i++) {
        if(i % M == 0 && i % N == 0) {
            LCM = i;
            break;
        }
    }
    return LCM;
}

int try(int M, int N, int x, int y)
{
    int i = 0, j = 0, cnt = 0;
    int last = LCM(M, N);
    while(++cnt <= last) {
        i++; j++;
        if(i > M) i = 1;
        if(j > N) j = 1;
        // printf("%d : <%d:%d>\n", cnt, i, j);
        if(x == i && y == j) return cnt;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int TestCase; // 테스트 케이스
    int M, N, x, y;
    scanf("%d", &TestCase);
    while (TestCase--) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        printf("%d\n", try(M, N, x, y));
    }
    return 0;
}
