#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;                         // 입력 사탕 수
bool isPrime[500001];          // index : n이, value : 소수인지 아닌지
unsigned long long dp[500001]; // index : 해당 가격을 만들 수 있는 모든 경우의 수
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
        candy_price_sum += curr;
        if (curr == 0)
        {
            ++zero_counter;
            continue;
        }
        candy[curr]++;
    }

    // 각 캔디 종류별 루프를 돈다.
    dp[0] = 1; // 기저 : 0개 살수 있는 경우의 수는 1

    for (int i = 1; i <= 500000; i++)
    {
        dp[i] = 0;
    }

    for (auto i = candy.begin(); i != candy.end(); i++)
    {
        // cout << i->first << " : " << i->second << endl;
        // 해당 가격 캔디를 만들수 있는지 챌린지
        for (int j = candy_price_sum; j >= 0; j--)
        {
            // 같은 가격 캔디가 여러개 있을 경우의 수도 따짐.
            for (int k = 1; k <= i->second; k++)
            {
                // cout << "캔디종류 : " << i->first << ", 계수카운터 : " << k << endl;
                if ((j - k * i->first) < 0)
                    break;
                //
                dp[j] += dp[j - k * i->first];
            }
        }
    }

    // 소수인거만 주워담는다.
    unsigned long long answer = 0;
    for (int i = 2; i <= candy_price_sum; i++)
    {
        // 0원캔디는 아무데나 붙을수 있기 때문에 단순히 해당 경우의수에서 곱해준다.
        //cout << i << "원을 살 수 있는 경우의 수 : " << dp[i] << endl;
        if (isPrime[i])
        {
            answer += zero_counter * dp[i];
        }
    }
    cout << answer << endl;

    return 0;
}
