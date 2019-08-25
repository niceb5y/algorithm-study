#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    while (m--) {
      cin >> a >> b;
    }
    cout << n - 1 << "\n";
  }
}
