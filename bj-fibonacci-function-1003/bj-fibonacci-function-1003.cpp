#include <iostream>

using namespace std;

int *call_zero; //zero - call 횟수
int *call_one; // one - call 횟수

int _2ovmH32oNtc(int n, int *w)
{
    if(w[n] != -1) return w[n];
    return w[n] = _2ovmH32oNtc(n-1, w) + _2ovmH32oNtc(n-2, w);
}

int main(void)
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    call_zero = new int[41]; // 0이 출력되는 횟수
    call_one = new int[41]; // 1이 출력되는 횟수
    for (int i = 0; i <= 40; i++) {
        call_zero[i] = call_one[i] = -1; // undefined 초기화
    }
    call_zero[0] = 1;
    call_zero[1] = 0;
    call_zero[2] = 1;
    // call-zero 횟수
    // 0 -> 1개
    // 1 -> 0개
    // 2-> fib(1) + fib(0) = 1개
    // 3-> fib(2) + fib(1) = fib(1) + fib(0) + fib(1) = 1개
    
    call_one[0] = 0;
    call_one[1] = 1;
    call_one[2] = 1;
    // call-one 횟수
    // 0 -> 0개
    // 1 -> 1개
    // 2 -> fib(1) + fib(0) = 1개
    // 3 -> fib(2) + fib(1) = fib(1) + fib(0) + fib (1) = 2개
    
    while(t--) {
        cin >> n;
        cout << _2ovmH32oNtc(n, call_zero) << ' ' << _2ovmH32oNtc(n, call_one) << '\n';
    }
    return 0;
}
