#include <iostream>
#include <vector>

using namespace std;

string str;

vector<vector<bool>> pld;
vector<vector<bool>> pld_cache;

bool chk(const int &lo, const int &hi) {
  if (pld_cache[lo][hi]) {
    return pld[lo][hi];
  }
  if (hi - lo == 0)
    return true;
  if (hi - lo == 1) {
    return str[lo] == str[hi];
  }
  pld[lo][hi] = (str[lo] == str[hi]) ? chk(lo + 1, hi - 1) : false;
  pld_cache[lo][hi] = true;
  return pld[lo][hi];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  getline(cin, str);
  size_t len = str.length();
  pld.resize(len, vector<bool>(len));
  pld_cache.resize(len, vector<bool>(len, false));
  for (size_t i = 0; i < len; ++i) {
    if (chk(i, len - 1)) {
      cout << i + len << endl;
      return 0;
    }
  }
}
