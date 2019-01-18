#include <stdio.h>

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
    int N, n;
    int count = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        if(isPrime(n)) count++;
    }
    printf("%d\n", count);
}
