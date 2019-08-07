#include <iostream>

using namespace std;

long long get_dist(int warp) {
  long long n = (warp + 1) / 2;
  if (warp % 2 == 0) {
    return n * (n + 1);
  }
  return get_dist(warp + 1) - n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long T, X, Y;
  cin >> T;

  while (T--) {
    cin >> X >> Y;

    long long ans = 1, dist = Y - X;
    while (get_dist(ans) < dist)
      ++ans;
    cout << ans << "\n";
  }
}
