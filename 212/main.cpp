#include <iostream>
#include <queue>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  queue<int> q;
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i)
    q.push(i);

  while (true) {
    if (q.size() == 1) {
      cout << q.front() << "\n";
      break;
    }
    q.pop();
    if (q.size() == 1) {
      cout << q.front() << "\n";
      break;
    }
    q.push(q.front());
    q.pop();
  }
}
