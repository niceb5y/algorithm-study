#include <algorithm>
#include <iostream>

using namespace std;

long long int countN(int n, long long int num) {
  long long ret = 0;
  for (long long int i = n; i <= num; i *= n) {
    ret += num / i;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  cout << min(countN(2, n) - countN(2, m) - countN(2, n - m),
              countN(5, n) - countN(5, m) - countN(5, n - m))
       << "\n";
}
