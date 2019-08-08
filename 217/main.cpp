#include <iostream>
#include <numeric>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    int limit = lcm(m, n);
    while (x <= limit && (x - 1) % n + 1 != y)
      x += m;
    cout << (x > limit ? -1 : x) << endl;
  }
}
