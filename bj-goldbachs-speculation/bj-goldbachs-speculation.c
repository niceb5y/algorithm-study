 #include <stdio.h>

/*
 * Problem : https://www.acmicpc.net/problem/9020
 * 2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오.
 * 만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.
 */
 
// 0 : 소수, 1 : 합성수
int primes[5001] = {0, };

// 0 : 합성수, 1 : 소수
int primes_[72] = {0, };
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

void reduce()
{
    
}


 int main(void)
 {
    int T, n, i, j;
    Eratos(5000); // 소수를 구해 놓는다.
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); // 4 ~ 10,000
    }
    return 0;
 }
 