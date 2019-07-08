#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    cin.ignore(1);
    string line;
    getline(cin, line);
    for (auto &c : line) {
      for (int j = 0; j < n; ++j) {
        cout << c;
      }
    }
    cout << "\n";
  }
}
