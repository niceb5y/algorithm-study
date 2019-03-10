#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  cout.precision(10);
  cout << static_cast<double>(a) / b << endl;
}
