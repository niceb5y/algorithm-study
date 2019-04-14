#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c;
  cin >> n >> c;
  vector<int> house(n);
  for (int i = 0; i < n; ++i) {
    cin >> house[i];
  }
  sort(house.begin(), house.end());
  int ans = 0, left = 0, right = 1000000001;
  while (left <= right) {
    int mid = (left + right) / 2;
    int count = 1;
    int last = house[0];
    for (int i = 1; i < n; ++i) {
      if (house[i] - last >= mid) {
        last = house[i];
        ++count;
      }
    }
    if (count >= c) {
      left = mid + 1;
      ans = mid;
    } else {
      right = mid - 1;
    }
  }
  cout << ans << endl;
}
