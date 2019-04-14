#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> arr;
vector<vector<bool>> pld;
vector<vector<bool>> pld_cache;

bool chk(const int &lo, const int &hi) {
  if (pld_cache[lo][hi]) {
    return pld[lo][hi];
  }
  if (hi - lo == 0)
    return true;
  if (hi - lo == 1) {
    return arr[lo] == arr[hi];
  }
  pld[lo][hi] = (arr[lo] == arr[hi]) ? chk(lo + 1, hi - 1) : false;
  pld_cache[lo][hi] = true;
  return pld[lo][hi];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  arr.resize(n);
  pld.resize(n, vector<bool>(n));
  pld_cache.resize(n, vector<bool>(n, false));
  for (auto &i : arr) {
    cin >> i;
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int s, e;
    cin >> s >> e;
    cout << (chk(s - 1, e - 1) ? 1 : 0) << "\n";
  }
}
