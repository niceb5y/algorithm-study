#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int push(int n) {
  if (max_heap.size() == 0 && min_heap.size() == 0) {
    max_heap.push(n);
    return n;
  }
  if (n < max_heap.top()) {
    max_heap.push(n);
  } else {
    min_heap.push(n);
  }
  int d = max_heap.size() - min_heap.size();
  if (d > 1) {
    min_heap.push(max_heap.top());
    max_heap.pop();
  } else if (d < 0) {
    max_heap.push(min_heap.top());
    min_heap.pop();
  }

  return max_heap.top();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, num;
  cin >> n;

  while (n--) {
    cin >> num;
    cout << push(num) << "\n";
  }
}
