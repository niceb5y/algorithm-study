#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  double _max = 0, ans = 0;
  vector<double> score(n);
  for (auto &s : score) {
    scanf("%lf", &s);
    _max = max(_max, s);
  }
  for (auto &s : score) {
    ans += s / _max * 100;
  }
  printf("%.2lf\n", ans / n);
}
