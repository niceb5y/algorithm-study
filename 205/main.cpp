#include <iostream>
#include <queue>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<int> pq;

  int n, x;
  cin >> n;

  while (n--) {
    cin >> x;
    if (x > 0) {
      pq.push(x);
    } else {
      if (pq.size() > 0) {
        cout << pq.top() << "\n";
        pq.pop();
      } else {
        cout << 0 << "\n";
      }
    }
  }
}
