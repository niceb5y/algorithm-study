#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, t, k, s;
  cin >> n >> t;
  vector<int> d(t + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> k >> s;
    for (int j = t; j >= k; --j) {
      d[j] = max(d[j], d[j - k] + s);
    }
  }
  cout << d[t] << endl;
}
