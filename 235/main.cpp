#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto &i : arr) {
    cin >> i;
  }

  int num = 1, denom = 1;
  for (int i = 1; i < n; ++i) {
    num *= arr[i - 1];
    denom *= arr[i];
    int div = gcd(num, denom);
    num /= div;
    denom /= div;
    cout << num << "/" << denom << "\n";
  }
}
