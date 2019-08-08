#include <cmath>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int A, B, V;
  cin >> A >> B >> V;

  cout << (int)ceil((double)(V - A) / (A - B)) + 1 << "\n";
}
