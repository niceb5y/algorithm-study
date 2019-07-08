#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0, loc = 1;
  for (int i = 1; i <= 9; ++i) {
    cin >> n;
    if (n > ans) {
      ans = n;
      loc = i;
    }
  }
  cout << ans << "\n" << loc << "\n";
}
