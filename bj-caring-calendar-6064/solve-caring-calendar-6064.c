#include <stdio.h>

/* Problem: https://www.acmicpc.net/problem/6064 */

int gcd(int a, int b)
{
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int M, int N)
{
    return M * N / gcd(M, N);
}

int try(int M, int N, int x, int y)
{
    int i;
    int cnt = x % (M + 1);
    int tempY = x;

    for(i = 0; i < N; i++) {
        int ty = tempY % N == 0 ? N : tempY % N;
        if (ty == y) break;
        tempY = ty + M;
        cnt += M;
    }
    if(cnt > LCM(M, N)) return -1;
    return cnt;
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
/*
시간 제한 돌파하기
기본 값을 정해놓은 다음 주기를 분석한다
ex> 3, 5 인 경우 최소공배수를 구하면 15이고 최대 15번 실행가능하지만 나머지 연산을 통해 각을 재볼 수 있다.
ex> <1:2>는 몇번 째 햇수인가?
1번째 : <1:1>
2번째 : <2:2>
3번째 : <3:3>
4번째 : <1:4>
<2:5>
<3:1>
7번째 : <1:2>*
...
y는 M 만큼 증가하고 N 으로 나머지 연산을 한다면, y 의 값을 알 수 있다는 것은 이해하고 있을 것이다.
이런식으로 y 를 M 만큼 계속 증가시키다보면, y 또한 맞춰질 것이다.
출처: http://mygumi.tistory.com/325 [마이구미의 HelloWorld]



*/
