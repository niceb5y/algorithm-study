#include <iostream>
#include <string>

using namespace std;

const int LIMIT = 2000000;
int q[LIMIT];
int start = 0, len = 0;

int norm(int x) { return (x + LIMIT) % LIMIT; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  cin.get();

  string buf;
  for (int i = 0; i < n; ++i) {
    getline(cin, buf);
    if (buf.compare("pop") == 0) {
      if (len > 0) {
        cout << q[start] << '\n';
        start = norm(start + 1);
        --len;
      } else {
        cout << -1 << '\n';
      }
    } else if (buf.compare("size") == 0)
      cout << len << '\n';
    else if (buf.compare("empty") == 0)
      cout << (len == 0 ? 1 : 0) << '\n';
    else if (buf.compare("front") == 0) {
      cout << (len == 0 ? -1 : q[start]) << "\n";
    } else if (buf.compare("back") == 0)
      cout << (len == 0 ? -1 : q[norm(start + len - 1)]) << "\n";
    else if (buf.rfind("push ", 0) == 0) {
      q[norm(start + len)] = stoi(buf.substr(5));
      ++len;
    }
  }
}
