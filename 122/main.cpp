#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int n;
vector<int> d;
vector<vector<int>> m;

int minmult(int lo, int hi) {

  int &ret = m[lo - 1][hi - 1];
  if (ret != -1)
    return ret;
  if (lo == hi)
    return 0;
  ret = numeric_limits<int>::max();
  for (int i = lo; i <= hi - 1; ++i) {
    ret = min(ret,
              minmult(lo, i) + minmult(i + 1, hi) + d[lo - 1] * d[i] * d[hi]);
  }
  return ret;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  d.resize(n + 1);
  cin >> d[0];
  cin >> d[1];
  for (int i = 1; i < n; ++i) {
    cin.ignore(10, ' ');
    cin >> d[i + 1];
  }
  m.resize(n, vector<int>(n, -1));
  cout << minmult(1, n) << endl;
}
