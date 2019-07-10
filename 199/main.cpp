#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[26] = {};
  string line;
  getline(cin, line);
  for (auto &c : line) {
    if (c >= 'a' && c <= 'z')
      ++arr[c - 'a'];
    if (c >= 'A' && c <= 'Z')
      ++arr[c - 'A'];
  }
  char ans = 0;
  int max = arr[0];
  for (int i = 1; i < 26; ++i) {
    if (arr[i] > max) {
      max = arr[i];
      ans = i;
    } else if (arr[i] == max) {
      ans = -2;
    }
  }
  cout << (char)('A' + ans) << endl;
}
