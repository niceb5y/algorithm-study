 #include <stdio.h>

/*
 * Problem : https://www.acmicpc.net/problem/4948
 * n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오. 
 */
 
// 0 : 소수, 1 : 합성수
int primes[246913] = {0, };
void workingClean(int n, int max)
{
    int k = n;
    while(n <= max) {
        n += k;
        primes[n] = 1; // n의 (>=2)배수는 합성수이다.
    }
}

void Eratos(int n)
{
    int i;
    primes[1] = 1; // 오류 방지
    primes[2] = 0; // 2는 소수이므로 2를 쓴다.
    for(i = 2; i * i <= n; i++) {
        if(primes[i] == 1) continue;
        primes[i] = 0;
        workingClean(i, n);// 자기 자신을 제외한 i의 배수를 모두 지운다.
    }
}


 int main(void)
 {
     int M, N, i, cnt;
     while(1) {
        cnt = 0;
        scanf("%d", &N);
        if(N == 0) break;
        Eratos(2 * N);
        for(i = N + 1; i <= 2 * N; i++) {
            if(primes[i] == 0)    cnt++;
        }
        printf("%d\n", cnt);
     }
     return 0;
 }
 