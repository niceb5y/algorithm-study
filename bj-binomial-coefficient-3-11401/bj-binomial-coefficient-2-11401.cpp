#include <iostream>
#define P 1000000007ULL
using namespace std;
typedef unsigned long long ull;

/*  
 * Problem: https://www.acmicpc.net/problem/11401
 * solution: https://www.acmicpc.net/board/view/15795
 */
ull fac[4000001], n, k, inv[4000001]; // x!의 역수
ull power(ull x, ull y)
{
    ull ret = 1;
    while (y > 0) {
        if (y % 2) {
            ret *= x;
            ret %= P;
        }
        x *= x;
        x %= P; // 100...007
        y /= 2; // 이분
    }
    return ret;
}

int main(void)
{
    fac[1] = 1;
    for (int i = 2; i <= 4000000; i++)
        fac[i] = (fac[i - 1] * i) % P;
    inv[4000000] = power(fac[4000000], P - 2); // 페르마의 소정리 이용하여 inverse를 구함
    for (int i = 4000000 - 1; i > 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % P; // inv(fac(i)) = inv(fac(i+1) * (i+1))
    cin >> n >> k;
    if (n == k || !k) {
        cout << 1 << '\n';
        return 0;
    }
    ull r = (fac[n] * inv[n - k]) % P;
    r = (r * inv[k]) % P;
    cout << r << '\n';
    return 0;
}
