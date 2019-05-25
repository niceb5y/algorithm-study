#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n[3];
  cin >> n[0] >> n[1] >> n[2];
  sort(&n[0], &n[3]);
  cout << n[1] << endl;
}
