#include <iostream>
#include <memory>
#include <string>

using namespace std;

// queue_t: 큐 구현
class queue_t {
private:
  // node: queue_t의 노드
  class node {
  public:
    // next: 다음 노드를 가리키는 포인터
    shared_ptr<node> next;
    // value: 노드의 값
    int value;
    // 생성자
    // value: 노드의 값
    node(int value) {
      this->value = value;
      next = nullptr;
    }
  };
  // head: queue_t의 첫 노드(더미 노드)
  shared_ptr<node> head;
  // length: queue_t의 (더미 노드를 제외한)노드의 길이
  int length;

public:
  // 생성자
  queue_t() {
    head = make_shared<node>(-1);
    length = 0;
  }
  // push(value): value의 값을 가지는 노드를 만들어 집어넣는다.
  void push(int value) {
    shared_ptr<node> cur(head);
    while (cur->next != nullptr)
      cur = cur->next;
    cur->next = make_shared<node>(value);
    ++length;
  }
  // pop(): 가장 앞 노드를 제거하고 값을 반환한다.
  int pop() {
    if (length == 0)
      return -1;
    shared_ptr<node> cur(head->next);
    int ret = cur->value;
    head->next = cur->next;
    --length;
    return ret;
  }
  // size(): 노드의 길이를 반환한다.
  int size() { return length; }
  // empty(): 노드가 비었는지 확인한다.
  bool empty() { return length == 0; }
  // front(): queue_t의 가장 앞 노드를 확인한다.
  int front() {
    if (length == 0)
      return -1;
    return head->next->value;
  }
  // back(): queue_t의 가장 뒷 노드를 확인한다.
  int back() {
    if (length == 0)
      return -1;
    shared_ptr<node> cur(head->next);
    while (cur->next != nullptr)
      cur = cur->next;
    return cur->value;
  }
};

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // n: 입력받을 명령어의 개수
  int n;
  cin >> n;
  // 버퍼 지우기
  cin.get();

  // queue: 사용할 큐
  queue_t queue = queue_t();
  // buf: 텍스트 버퍼
  string buf;
  // n번 명령을 받아 명렁에 맞게 처리한다.
  for (int i = 0; i < n; ++i) {
    getline(cin, buf);
    if (buf.compare("pop") == 0)
      cout << queue.pop() << '\n';
    else if (buf.compare("size") == 0)
      cout << queue.size() << '\n';
    else if (buf.compare("empty") == 0)
      cout << (queue.empty() ? 1 : 0) << '\n';
    else if (buf.compare("front") == 0)
      cout << queue.front() << '\n';
    else if (buf.compare("back") == 0)
      cout << queue.back() << '\n';
    else if (buf.rfind("push ", 0) == 0) {
      queue.push(stoi(buf.substr(5)));
    }
  }
  cout << flush;
}
