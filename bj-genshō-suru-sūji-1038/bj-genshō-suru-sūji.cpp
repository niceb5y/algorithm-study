#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1000000;

int N;
int rptr = 9; // 일의자리 숫자들은 감소하는 수
queue<unsigned long long> q;
unsigned long long dp2[MAXN + 1];

void dp(void)
{
    while (rptr <= N) {
        if (q.empty()) return;
        unsigned long long decrease_num = q.front();
        q.pop();
        // 끝자리 수 chk
        int one = decrease_num % 10;
        // 그 수보다 작은 수를 붙임
        for (int i = 0; i < one; i++) {
            q.push(decrease_num * 10 + i);
            dp2[++rptr] = decrease_num * 10 + i;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
        dp2[i] = i;
    }
    dp();
    if( !dp2[N] && N) cout << -1 << '\n';
    else cout << dp2[N] << '\n';
    return 0;
}
