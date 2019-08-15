#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, add = 0, sub = 0, mul = 0, dvd = 0, ans_min = 1000000001,
       ans_max = -1000000001;
vector<int> num;

void solve(int value, int depth) {
  if (depth == n) {
    ans_max = max(ans_max, value);
    ans_min = min(ans_min, value);
    return;
  }
  if (add > 0) {
    --add;
    solve(value + num[depth], depth + 1);
    ++add;
  }
  if (sub > 0) {
    --sub;
    solve(value - num[depth], depth + 1);
    ++sub;
  }
  if (mul > 0) {
    --mul;
    solve(value * num[depth], depth + 1);
    ++mul;
  }
  if (dvd > 0) {
    --dvd;
    solve(value / num[depth], depth + 1);
    ++dvd;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  num.resize(n);
  for (auto &i : num) {
    cin >> i;
  }
  cin >> add >> sub >> mul >> dvd;

  solve(num[0], 1);

  cout << ans_max << "\n" << ans_min << "\n";
}
