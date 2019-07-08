#include <cstdio>
#include <vector>

using namespace std;
int main() {
  int c;
  scanf("%d", &c);
  while (c--) {
    int n;
    scanf("%d", &n);
    vector<int> score(n);
    double avg = 0;
    for (auto &s : score) {
      scanf("%d", &s);
      avg += s;
    }
    avg /= n;
    int ans = 0;
    for (auto &s : score) {
      if (s > avg)
        ++ans;
    }
    printf("%.3lf%%\n", (double)ans * 100 / n);
  }
}
