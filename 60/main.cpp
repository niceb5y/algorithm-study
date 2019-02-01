#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // seq: 파도반 수열
  long seq[100] = {1, 1, 1, 2, 2};
  for (int i = 5; i < 100; ++i) {
    seq[i] = seq[i - 5] + seq[i - 1];
  }
  int t, n;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cout << seq[n - 1] << '\n';
  }
}
