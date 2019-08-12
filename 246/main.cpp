#include <iostream>
#include <utility>

using namespace std;

bool paper[128][128];

typedef pair<int, int> _pair;

_pair operator+(_pair a, _pair b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

_pair eval(int r, int c, int size) {
  bool valid = true;
  for (int i = r; i < r + size; ++i) {
    for (int j = c; j < c + size; ++j) {
      if (paper[i][j] != paper[r][c]) {
        valid = false;
        break;
      }
    }
  }
  if (valid)
    return paper[r][c] == 0 ? make_pair(1, 0) : make_pair(0, 1);
  return eval(r, c, size / 2) + eval(r + size / 2, c, size / 2) +
         eval(r, c + size / 2, size / 2) +
         eval(r + size / 2, c + size / 2, size / 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> paper[i][j];
    }
  }

  _pair ans = eval(0, 0, n);
  cout << ans.first << "\n" << ans.second << "\n";
}
