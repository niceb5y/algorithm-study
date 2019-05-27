#include <iostream>
#include <numeric>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b;
  cin >> a >> b;
  cout << lcm(a, b) << "\n";
}
