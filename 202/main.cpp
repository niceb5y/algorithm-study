#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  getline(cin, line);
  int ans = line.size(), size = line.size();
  if (line[size - 1] == 13) {
    --size;
    --ans;
  }

  for (int i = 0; i < size - 1; ++i) {
    auto cmp = [i, line](string str) {
      return line[i] == str[0] && line[i + 1] == str[1];
    };
    if (cmp("c=") || cmp("c-") || cmp("d-") || cmp("lj") || cmp("nj") ||
        cmp("s=") || cmp("z="))
      ans--;
  }
  for (int i = 0; i < size - 2; ++i) {
    if (line[i] == 'd' && line[i + 1] == 'z' && line[i + 2] == '=')
      ans--;
  }
  cout << ans << "\n";
}
