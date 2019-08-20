#include <cstdint>
#include <iostream>

using namespace std;

uint32_t bit = 0;

void add(int x) { bit |= (1 << x); }
void remove(int x) { bit &= ~(1 << x); }
bool check(int x) { return bit & (1 << x); }
void toggle(int x) { bit ^= (1 << x); }
void all() { bit = -1; }
void empty() { bit = 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  string cmd;
  cin >> n;

  while (n--) {
    cin >> cmd;

    if (cmd == "add") {
      cin >> x;
      add(x);
    } else if (cmd == "remove") {
      cin >> x;
      remove(x);
    } else if (cmd == "check") {
      cin >> x;
      cout << (check(x) ? 1 : 0) << "\n";
    } else if (cmd == "toggle") {
      cin >> x;
      toggle(x);
    } else if (cmd == "all") {
      all();
    } else if (cmd == "empty") {
      empty();
    }
  }
}
