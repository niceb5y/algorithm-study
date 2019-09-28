#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> q(k, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    bool valid = false;
    for (int j = 0; j < k; ++j) {
      if (q[j] < x) {
        q[j] = x;
        valid = true;
        break;
      }
    }
    if (!valid) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
