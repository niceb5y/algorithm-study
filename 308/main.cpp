#include <cstring>
#include <iostream>

using namespace std;

int dp[19];

int fib(int n) {
  if (n < 2)
    return n;
  int &ret = dp[n - 2];
  if (ret != -1)
    return ret;
  ret = fib(n - 1) + fib(n - 2);
  return ret;
}

int main() {
  memset(&dp[0], -1, 19 * sizeof(int));
  int n;
  cin >> n;
  cout << fib(n) << endl;
}
