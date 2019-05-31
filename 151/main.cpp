#include <iostream>

using namespace std;
int main() {
  int n, cur, cnt = 0;
  cin >> n;
  cur = n;
  do {
    cur = (cur % 10) * 10 + (cur / 10 + cur % 10) % 10;
    ++cnt;
  } while (cur != n);
  cout << cnt << endl;
}
