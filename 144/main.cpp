#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  getline(cin, line);
  for (size_t i = 1; i <= line.size(); ++i) {
    cout << line[i - 1];
    if (i % 10 == 0)
      cout << "\n";
  }
  cout << "\n";
}
