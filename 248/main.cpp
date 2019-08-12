#include <iostream>

using namespace std;

const long long P = 1000000007;

long long fact(long long n) {
  long long ret = 1;
  for (int i = 2; i <= n; ++i) {
    ret = (ret * i) % P;
  }
  return ret;
}

long long power(long long n, long long k) {
  if (k == 0)
    return 1;
  long long ret = power(n, k / 2);
  ret *= ret;
  ret %= P;
  if (k % 2 == 1)
    ret = (ret * n) % P;
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;

  cout << (fact(n) * power((fact(k) * fact(n - k)) % P, P - 2)) % P << "\n";
}
