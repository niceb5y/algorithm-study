#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    bool valid = true;
    if (line == "0")
      break;
    int len = line.length();
    for (int i = 0; i < len / 2; ++i) {
      if (line[i] != line[len - i - 1]) {
        valid = false;
        break;
      }
    }
    cout << (valid ? "yes" : "no") << endl;
  }
}
