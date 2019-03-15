#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;                         // 입력 사탕 수
bool isPrime[500001];          // index : n이, value : 소수인지 아닌지
int dp[500001];                // index : 해당 가격을 만들 수 있는 모든 경우의 수
unordered_map<int, int> candy; // <캔디의 가격, 캔디의 수>

void erase_multiple(int n, int threshold)
{
    int k = n;
    while (n <= threshold)
    {
        n += k;
        isPrime[n] = true;
    }
}

void find_prime(int n)
{
    int i;
    isPrime[0] = isPrime[1] = true;
    isPrime[2] = false; // 2는 소수이므로 true
    for (i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
            continue;
        erase_multiple(i, n); // 자기자신을 제외한 i의 배수를 모두 지운다.
    }
    for (int i = 0; i < n; i++)
    {
        isPrime[i] = !isPrime[i];
    }
}

int main(void)
{
    find_prime(500000);
    int zero_counter = 1; // 0원 사탕, 모든 경우에 수에 곱한다.
    int candy_price_sum = 0;
    cin >> N; // <= 50
    for (int i = 0; i < N; i++)
    {
        int curr;
        cin >> curr;
        candy_price_sum++;
        if (curr == 0)
        {
            ++zero_counter;
            continue;
        }
        candy[curr]++;
    }

    // 각 캔디 종류별 루프를 돈다.
    for (auto i = candy.begin(); i != candy.end(); i++)
    {
        // cout << i->first << " : " << i->second << endl;
        // 해당 가격 캔디를 만들수 있는지 챌린지
        for (int j = candy_price_sum; j >= 0; j--)
        {
            // 같은 가격 캔디가 여러개 있을 경우의 수도 따짐.
            for (int k = 1; k < i->second; k++)
            {
            }
        }
    }

    return 0;
}
