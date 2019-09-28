#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned long long n;
  cin >> n;

  for (unsigned long long i = 1;; ++i) {
    unsigned long long limit = 1;
    for (unsigned long long j = 0; j <= i; ++j) {
      limit *= 2;
    }
    --limit;
    limit *= (i + 1);
    limit += i;
    if (n <= limit) {
      cout << i << endl;
      return 0;
    }
  }
}
