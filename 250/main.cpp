#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  map<int, int> num;
  int n, m, tmp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    num[tmp]++;
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    cout << num[tmp] << (i == m - 1 ? "\n" : " ");
  }
}
