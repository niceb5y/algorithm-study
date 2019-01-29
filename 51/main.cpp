#include <iostream>
#include <memory>
#include <string>

using namespace std;

// deque_t: 원형 큐를 이용한 덱 구현
class deque_t {
private:
  // node: deque_t의 노드
  class node {
  public:
    // next: 다음 노드를 가리키는 포인터
    shared_ptr<node> next;
    shared_ptr<node> prev;
    // value: 노드의 값
    int value;
    // 생성자
    // value: 노드의 값
    node(int value) {
      this->value = value;
      next = nullptr;
      prev = nullptr;
    }
  };
  // head: deque_t의 첫 노드(더미 노드)
  shared_ptr<node> head;
  // length: deque_t의 (더미 노드를 제외한)노드의 길이
  int length;

public:
  // 생성자
  deque_t() {
    head = make_shared<node>(-1);
    head->next = head;
    head->prev = head;
    length = 0;
  }
  // push_front(value): value의 값을 가지는 노드를 만들어 앞에 집어넣는다.
  void push_front(int value) {
    shared_ptr<node> tmp(head->next);
    shared_ptr<node> cur = make_shared<node>(value);
    head->next = cur;
    cur->prev = head;
    cur->next = tmp;
    tmp->prev = cur;
    ++length;
  }
  // push_back(value): value의 값을 가지는 노드를 만들어 뒤에 집어넣는다.
  void push_back(int value) {
    shared_ptr<node> tmp(head->prev);
    shared_ptr<node> cur = make_shared<node>(value);
    cur->next = head;
    head->prev = cur;
    tmp->next = cur;
    cur->prev = tmp;
    ++length;
  }
  // pop_front(): 가장 앞 노드를 제거하고 값을 반환한다.
  int pop_front() {
    if (length == 0)
      return -1;
    shared_ptr<node> cur(head->next);
    int ret = cur->value;
    shared_ptr<node> tmp = cur->next;
    head->next = tmp;
    tmp->prev = head;
    --length;
    return ret;
  }
  // pop_back(): 가장 앞 노드를 제거하고 값을 반환한다.
  int pop_back() {
    if (length == 0)
      return -1;
    shared_ptr<node> cur(head->prev);
    int ret = cur->value;
    shared_ptr<node> tmp = cur->prev;
    head->prev = tmp;
    tmp->next = head;
    --length;
    return ret;
  }
  // size(): 노드의 길이를 반환한다.
  int size() { return length; }
  // empty(): 노드가 비었는지 확인한다.
  bool empty() { return length == 0; }
  // front(): deque_t의 가장 앞 노드를 확인한다.
  int front() {
    if (length == 0)
      return -1;
    return head->next->value;
  }
  // back(): deque_t의 가장 뒷 노드를 확인한다.
  int back() {
    if (length == 0)
      return -1;
    return head->prev->value;
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
  // deque: 사용할 덱
  deque_t deque = deque_t();
  // buf: 텍스트 버퍼
  string buf;
  // n번 명령을 받아 명렁에 맞게 처리한다.
  for (int i = 0; i < n; ++i) {
    getline(cin, buf);
    if (buf.compare("pop_front") == 0)
      cout << deque.pop_front() << '\n';
    else if (buf.compare("pop_back") == 0)
      cout << deque.pop_back() << '\n';
    else if (buf.compare("size") == 0)
      cout << deque.size() << '\n';
    else if (buf.compare("empty") == 0)
      cout << (deque.empty() ? 1 : 0) << '\n';
    else if (buf.compare("front") == 0)
      cout << deque.front() << '\n';
    else if (buf.compare("back") == 0)
      cout << deque.back() << '\n';
    else if (buf.rfind("push_front ", 0) == 0) {
      deque.push_front(stoi(buf.substr(11)));
    } else if (buf.rfind("push_back ", 0) == 0) {
      deque.push_back(stoi(buf.substr(10)));
    }
  }
  cout << flush;
}
