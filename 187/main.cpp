#include <iostream>
#include <set>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  set<int> s;
  for (int i = 0; i < 10; ++i) {
    int n;
    cin >> n;
    s.insert(n % 42);
  }
  cout << s.size() << endl;
}
