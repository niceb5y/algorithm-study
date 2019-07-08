#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, _max = -1000000, _min = 1000000;
  cin >> n;
  while (n--) {
    cin >> m;
    _max = max(_max, m);
    _min = min(_min, m);
  }
  cout << _min << " " << _max << "\n";
}
