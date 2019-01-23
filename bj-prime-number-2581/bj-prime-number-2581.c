 #include <stdio.h>

/**
 * Problem : https://www.acmicpc.net/problem/2581
 * 자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.
 * 예를 들어 M=60, N=100인 경우
 * 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로,
 * 이들 소수의 합은 620이고, 최솟값은 61이 된다.
 */
 
// 0 : 정의안됨, 1 : 소수 -1 : 합성수
int primes[10001] = {0, };

int isPrime(int n)
{
    int i;
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for(i = 3; i * i <= n; i += 2) {
        // 이미 얻은 소수로만 나눠봐도 되요.
        if (n % i == 0) return 0;
    }
    return 1;
}


 int main(void)
 {
     int M, N, i;
     int min = 99999, sum = 0;
     scanf("%d %d", &M, &N);
     for(i = M; i <= N; i++) {
         if(isPrime(i)) {
             sum += i;
             min = min > i ? i : min;
         }
     }
     printf("%d", sum?sum:-1);
     if(sum)    printf("\n%d", min);
     return 0;
 }
 