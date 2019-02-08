#include <iostream>

using namespace std;

int f[46];

int main(void)
{
    int n;
    f[0] = 0;
    f[1] = 1;
    cin >> n;
    // cin.get(); // 정수형일 경우 필요없음
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}
