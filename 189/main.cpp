#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  cin.ignore(1);
  string line;
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    int score = 0, point = 0;
    for (auto &c : line) {
      if (c == 'O') {
        score += (++point);
      } else {
        point = 0;
      }
    }
    cout << score << "\n";
  }
}
