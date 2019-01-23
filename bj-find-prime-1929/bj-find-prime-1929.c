 #include <stdio.h>

/*
 * Problem : https://www.acmicpc.net/problem/1929
 * M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
 */
 
// 0 : 소수, 1 : 합성수
int primes[1000001] = {0, };

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
     int M, N, i;
     int min = 99999, sum = 0;
     scanf("%d %d", &M, &N);
     Eratos(N);
     for(i = M; i <= N; i++) {
         if(primes[i] == 0)
            printf("%d\n", i);
     }
     return 0;
 }
 