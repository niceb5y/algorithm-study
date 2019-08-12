#include <iostream>

using namespace std;

long long pow(int a, int b, int c) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return (pow(a, b / 2, c) * pow(a, b / 2, c)) % c;
  return ((pow(a, b / 2, c) * pow(a, b / 2, c) % c) * a) % c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> a >> b >> c;

  cout << pow(a, b, c) << "\n";
}
