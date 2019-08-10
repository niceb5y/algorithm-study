#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int dx = (x1 - x2) * (x1 - x2), dy = (y1 - y2) * (y1 - y2),
        dr = (r1 - r2) * (r1 - r2), sr = (r1 + r2) * (r1 + r2);

    if (dx == 0 && dy == 0) {
      cout << (dr == 0 ? -1 : 0);
    } else {
      int d = dx + dy;
      if (d > dr && d < sr)
        cout << 2;
      else if (d == sr || (d == dr && d > 0))
        cout << 1;
      else
        cout << 0;
    }
    cout << "\n";
  }
}
