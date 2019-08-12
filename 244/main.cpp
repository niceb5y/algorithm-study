#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; ++i) {

    int num;
    for (int j = 0; j < n; ++j) {
      cin >> num;
      pq.push(num);
    }
    while (pq.size() > (size_t)n) {
      pq.pop();
    }
  }

  cout << pq.top() << endl;
}
