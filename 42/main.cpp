#include <iostream>
#include <vector>.

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // p: 피보나치 수열을 1000000(= m)으로 나눈 나머지의 주기
  // m = 10^k(k > 2)일때 p = 15 * 10 ^ (k - 1)
  const int p = 1500000;
  long long n;
  cin >> n;
  // fib[n]: (fib[n - 2] + fib[n - 1]) % 1000000
  vector<int> fib({0, 1});
  fib.reserve(n % p + 1);
  for (int i = 2; i <= n % p; ++i) {
    fib[i] = (fib[i - 2] + fib[i - 1]) % 1000000;
  }
  cout << fib[n % p] << endl;
}
