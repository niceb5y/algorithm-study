#include <cmath>
#include <iostream>

using namespace std;

void solve(int from, int by, int to, int n) {
  if (n != 1)
    solve(from, to, by, n - 1);
  cout << from << " " << to << "\n";
  if (n != 1)
    solve(by, from, to, n - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  cout << (long long)pow(2, n) - 1 << "\n";
  solve(1, 2, 3, n);
}
