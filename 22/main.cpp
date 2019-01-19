#include <iostream>
#include <list>
#include <utility>

using namespace std;

// node_t: printer_queue에 저장될 작업들의 타입
// .first: 중요도 값
// .second: 해당 문서의 인쇄 순서를 알고 싶은지의 여부
typedef pair<int, bool> node_t;

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // t: 테스트 케이스의 개수
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    // n: 문서의 개수
    // m: 인쇄 순서를 알고 싶은 문서의 번호
    int n, m;
    cin >> n >> m;
    // printer_queue: 인쇄할 문서들을 저장할 큐 (사실은 리스트)
    list<node_t> printer_queue;
    for (int j = 0; j < n; ++j) {
      // prioirty: 중요도
      int priority;
      cin >> priority;
      // printer_queue에 노드를 추가한다.
      printer_queue.push_back(make_pair(priority, j == m));
    }
    // count: 몇번째 인쇄인가를 저장하는 변수
    int count = 0;
    while (true) {
      // head: 큐의 가장 앞 노드
      node_t head = printer_queue.front();
      // head를 일단 printer_queue에서 제거한다
      printer_queue.pop_front();
      // max_priority: printer_queue의 최대 중요도를 구한다.
      int max_priority = 0;
      for (auto &node : printer_queue) {
        max_priority = max(max_priority, node.first);
      }
      if (head.first >= max_priority) {
        // head의 중요도가 max_priority보다 크거나 같으면 count를 증가시킨다.
        ++count;
        // 해당 문서가 중요도를 알고 싶은 문서인 경우, count를 출력한다.
        if (head.second) {
          cout << count << '\n';
          break;
        }
      } else {
        // head의 중요도가 max_priority보다 작으면 다시 printer_queue의 뒤에
        // 삽입한다.
        printer_queue.push_back(head);
      }
    }
  }
}
