#include <iostream>
#include <memory>

using namespace std;

class node {
private:
  // left: 왼쪽 자식 노드를 가리키는 포인터
  unique_ptr<node> left;
  // right: 오른쪽 자식 노드를 가리키는 포인터
  unique_ptr<node> right;
  // id: 노드의 식별자
  char id;

public:
  //  생성자
  // id: 노드의 식별자
  node(const char &id) {
    this->id = id;
    left = nullptr;
    right = nullptr;
  }

  // addChild(): 해당 id를 가진 노드를 찾아 자식 노드를 추가하는 함수
  // id: 자식 노드를 추가할 부모 노드의 id
  // left_child_id: 부모 노드의 왼쪽 자식 노드의 id
  // right_child_id: 부모 노드의 오른쪽 자식 노드의 id
  void addChild(const char &id, const char &left_child_id,
                const char &right_child_id) {
    if (id == this->id) {
      if (left_child_id != '.') {
        left = make_unique<node>(left_child_id);
      }
      if (right_child_id != '.') {
        right = make_unique<node>(right_child_id);
      }
    } else {
      if (left != nullptr) {
        left->addChild(id, left_child_id, right_child_id);
      }
      if (right != nullptr) {
        right->addChild(id, left_child_id, right_child_id);
      }
    }
  }

  // 전위 순회 : 루트 -> 왼쪽 자식 -> 오른쪽 자식
  void preorder_traversal() {
    cout << this->id;
    if (left != nullptr) {
      left->preorder_traversal();
    }
    if (right != nullptr) {
      right->preorder_traversal();
    }
  }
  // 중위 순회 : 왼쪽 자식 -> 루트 -> 오른쪽 자식
  void inorder_traversal() {
    if (left != nullptr) {
      left->inorder_traversal();
    }
    cout << this->id;
    if (right != nullptr) {
      right->inorder_traversal();
    }
  }
  // 후위 순회 : 왼쪽 자식 -> 오른쪽 자식 -> 루트
  void postorder_traversal() {
    if (left != nullptr) {
      left->postorder_traversal();
    }
    if (right != nullptr) {
      right->postorder_traversal();
    }
    cout << this->id;
  }
};

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // n:이진 트리의 노드의 개수
  int n;
  cin >> n;

  // 루트 노드
  node root = node('A');
  // n번 입력을 받아 자식 노드를 추가한다.
  for (int i = 0; i < n; ++i) {
    char id, left_child_id, right_child_id;
    cin >> id >> left_child_id >> right_child_id;
    root.addChild(id, left_child_id, right_child_id);
  }
  // 전위 순회
  root.preorder_traversal();
  cout << '\n';
  // 중위 순회
  root.inorder_traversal();
  cout << '\n';
  // 후위 순회
  root.postorder_traversal();
  cout << '\n';
  cout << flush;
}
