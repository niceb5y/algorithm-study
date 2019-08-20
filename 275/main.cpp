#include <iostream>

using namespace std;

int dp[1000001], pre[1000001];

int solve(int n) {
  int &ret = dp[n];

  if (ret != -1)
    return ret;

  if (n == 1)
    return 0;

  ret = 1000001;

  if (n % 3 == 0 && solve(n / 3) + 1 < ret) {
    ret = solve(n / 3) + 1;
    pre[n] = n / 3;
  }

  if (n % 2 == 0 && solve(n / 2) + 1 < ret) {
    ret = solve(n / 2) + 1;
    pre[n] = n / 2;
  }

  if (solve(n - 1) + 1 < ret) {
    ret = solve(n - 1) + 1;
    pre[n] = n - 1;
  }

  return ret;
}

void print(int n) {
  cout << n;
  if (n > 1) {
    cout << " ";
    print(pre[n]);
  } else {
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  fill_n(&dp[0], 1000001, -1);

  int n;
  cin >> n;
  cout << solve(n) << "\n";
  print(n);
}
