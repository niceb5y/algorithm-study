#include <iostream>

using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  getchar();
  for (int i = 0; i < n; ++i) {
    sum += getchar() - '0';
  }
  cout << sum << "\n";
}
