#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string line;
  getline(cin, line);

  bool minus = false;
  int sum = 0, temp = 0;

  for (auto &c : line) {
    if (c >= '0' && c <= '9') {
      temp = temp * 10 + (c - '0');
    } else if (c == '-' || c == '+') {
      if (minus)
        sum -= temp;
      else
        sum += temp;
      temp = 0;
      if (c == '-')
        minus = true;
    }
  }

  if (minus)
    sum -= temp;
  else
    sum += temp;

  cout << sum << "\n";
}
