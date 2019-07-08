#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int pos[26];
  fill_n(&pos[0], 26, -1);
  string line;
  getline(cin, line);
  for (size_t i = 0; i < line.size(); ++i) {
    if (pos[line[i] - 'a'] == -1) {
      pos[line[i] - 'a'] = i;
    }
  }
  for (int i = 0; i < 26; ++i) {
    cout << pos[i] << (i == 25 ? "\n" : " ");
  }
}
