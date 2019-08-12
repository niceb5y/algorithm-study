#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  stack<int> stk;

  int k;
  cin >> k;

  while (k--) {
    int n;
    cin >> n;
    if (n == 0) {
      stk.pop();
    } else {
      stk.push(n);
    }
  }

  int ans = 0;
  while (!stk.empty()) {
    ans += stk.top();
    stk.pop();
  }

  cout << ans << "\n";
}
