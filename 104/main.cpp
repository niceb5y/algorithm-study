#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin.peek() != EOF) {
    string line;
    getline(cin, line);
    cout << line << "\n";
  }
}
