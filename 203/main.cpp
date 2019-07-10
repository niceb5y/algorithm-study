#include <iostream>
#include <set>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    set<char> s;
    char prev = str[0];
    bool valid = true;
    for (size_t i = 1; i < str.size(); ++i) {
      if (s.find(str[i]) != s.end()) {
        valid = false;
        break;
      }
      if (prev != str[i]) {
        s.insert(prev);
        prev = str[i];
      }
    }
    if (valid)
      ++ans;
  }
  cout << ans << '\n';
}
