#include <iostream>

using namespace std;

unsigned long long f[1500001];

int main(void)
{
    unsigned long long n;
    f[0] = 0;
    f[1] = 1;
    cin >> n;
    // cin.get(); // 정수형일 경우 필요없음
    for (int i = 2; i <= 1500000; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 1000000;
    }
    cout << f[n % 1500000] << endl;
    return 0;
}
