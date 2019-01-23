 #include <stdio.h>

/**
 * Problem : https://www.acmicpc.net/problem/2581
 * 자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.
 * 예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.
 */
 
int primes[10000];

int isPrime(int n)
{
    int i;
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for(i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}


 int main(void)
 {

     return 0;
 }
 