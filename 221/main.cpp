#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int len[3];
  while (true) {
    for (auto &l : len)
      cin >> l;
    if (len[0] == 0 && len[1] == 0 && len[2] == 0)
      break;
    sort(&len[0], &len[0] + 3);

    cout << ((len[0] * len[0] + len[1] * len[1] == len[2] * len[2]) ? "right"
                                                                    : "wrong")
         << "\n";
  }
}
