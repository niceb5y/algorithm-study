#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  bool asc = true, desc = true;
  int n, tmp;
  cin >> n;
  for (int i = 0; i < 7; ++i) {
    cin >> tmp;
    if (n > tmp)
      asc = false;
    if (n < tmp)
      desc = false;
    n = tmp;
  }
  if (asc)
    cout << "ascending" << endl;
  else if (desc)
    cout << "descending" << endl;
  else
    cout << "mixed" << endl;
}
