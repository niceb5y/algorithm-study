#include <iostream>

using namespace std;

int down_size_product(int n, int times)
{
    if (n==0 || times == 0) return 0;
    int n2 = n;
    int res = n;
    while(--times) {
        res *= --n2;
    }
    return res;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    int res1 = down_size_product(n, k);
    int res2 = down_size_product(k, k);
    if(res2 == 0) cout << 1 << '\n';
    else cout << res1 / res2 << '\n';
    return 0;
}
