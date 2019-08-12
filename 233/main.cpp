#include <algorithm>
#include <iostream>
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

  sort(arr.begin(), arr.end());

  cout << arr[0] * arr[n - 1] << "\n";
}
