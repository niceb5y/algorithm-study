#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  getline(cin, line);
  if (line[0] == ' ')
    line = line.substr(1, line.size() - 1);
  if (line[line.size() - 1] == ' ')
    line = line.substr(0, line.size() - 1);
  if (line.size() == 0)
    cout << 0 << "\n";
  else
    cout << count(line.begin(), line.end(), ' ') + 1 << "\n";
}
