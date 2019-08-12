#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    map<string, int> m;
    int n;
    cin >> n;

    while (n--) {
      string item, category;
      cin >> item >> category;
      m[category]++;
    }

    int ans = 1;
    for (auto &cat : m) {
      ans *= (cat.second + 1);
    }

    cout << --ans << "\n";
  }
}
