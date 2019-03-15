#include <iostream>
#include <vector>

using namespace std;

int N;                // 입력 수
bool isPrime[500001]; // index : n이, value : 소수인지 아닌지
long long branch[500005];
int candy[10001];         // index: 어떤 가격 종류의 캔디인가 , value : 몇 개인가
vector<int> candy_unique; // 가격 종류별 캔디

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
    int zero_counter = 1;
    int candy_price_sum = 0;
    cin >> N; // <= 50

    for (int i = 0; i < N; i++)
    {
        int D; // 한 캔디의 가격이자 종류
        cin >> D;
        candy_price_sum += D;
        if (D == 0)
        {
            zero_counter++;
            continue;
        }
        if (candy[D] == 0)
            candy_unique.push_back(D); // 유니크 캔디 종류 추가
        candy[D]++;                    // 캔디의 개수를 늘렸다.
    }
    int number_of_unique_candy = candy_unique.size();
    for (int i = 0; i < number_of_unique_candy; i++)
    {
        for (int j = candy_price_sum; j >= 0; j--)
        {
            for (int k = 1; k <= candy[candy_unique.at((i))]; k++)
            {
                if (j + k * candy_unique.at(i) >= 500001)
                    break;
                branch[j + k * candy_unique.at(i)] += branch[j];
            }
        }
        candy_price_sum += candy_unique.at(i) * candy[candy_unique.at(i)];
        candy_price_sum = min(candy_price_sum, 500000);
    }
    long long answer = 0;
    for (int i = 2; i < 500001; i++)
        if (!isPrime[i])
            answer += branch[i];
    answer *= zero_counter;
    cout << answer << endl;
    return 0;
}
