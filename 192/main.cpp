#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n) {
  int &ans = dp[n];
  if (ans != -1)
    return ans;
  ans = (solve(n - 1) + solve(n - 2)) % 15746;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  dp.resize(n + 1, -1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  cout << solve(n) << "\n";
}
