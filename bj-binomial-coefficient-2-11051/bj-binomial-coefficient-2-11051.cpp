#include <iostream>

using namespace std;

// n-1Cr-1 + n-1Cr = nCr

unsigned nCr[1001][1001];

/*
r이 0이면 결과는 1
r이 1이면 결과는 n
*/

int getnCr(int n, int r)
{
    if(nCr[n][r])
        return nCr[n][r];
    return nCr[n][r] = (getnCr(n-1, r-1) + getnCr(n-1, r)) % 10007;
}

int main(void)
{
    int N, K;
    for (int i = 1; i <= 1000; i++) {
        // 초기화
        nCr[i][0] = 1;
        nCr[i][1] = i;
        for (int j = 2; j <= 1000; j++) {
            nCr[i][j] = 0; // undefined
            if(i == j) nCr[i][j] = 1; // nCn = 1
        }
    }
    cin >> N >> K;
    cout << getnCr(N, K) << endl;
    return 0;
}
