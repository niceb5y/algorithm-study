#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int abs(int n) { return (n < 0) ? -n : n; }

struct cmp {
  bool operator()(int a, int b) {
    if (abs(a) == (abs(b)))
      return a > b;
    return abs(a) > abs(b);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, num;
  cin >> n;

  priority_queue<int, vector<int>, cmp> pq;
  while (n--) {
    cin >> num;
    if (num != 0) {
      pq.push(num);
    } else {
      if (pq.empty()) {
        cout << 0 << endl;
      } else {
        cout << pq.top() << endl;
        pq.pop();
      }
    }
  }
}
