#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string num1, num2;
  cin >> num1 >> num2;
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());
  cout << (stoi(num1) < stoi(num2) ? num2 : num1) << '\n';
}
