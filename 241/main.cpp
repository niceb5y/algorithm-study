#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr(n), nge(n, -1);
  stack<int> stk;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    while (!stk.empty() && arr[stk.top()] < arr[i]) {
      nge[stk.top()] = arr[i];
      stk.pop();
    }
    stk.push(i);
  }

  for (int i = 0; i < n; ++i) {
    cout << nge[i] << (i == n - 1 ? "\n" : " ");
  }
}
