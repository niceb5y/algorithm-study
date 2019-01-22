#include <iostream>

// pre_order: pre order로 출력된 트리의 노드를 저장하는 배열
// in_order: in order로 출력된 트리의 노드를 저장하는 배열
// post_order: pre order로 출력된 트리의 노드를 저장하는 배열
int pre_order[100000], in_order[100000], post_order[100000];

// convert(): in_order와 post_order를 이용하여 pre_order를 구하는 함수
// pre_lo: pre_order의 하한
// pre_hi: pre_order의 상한
// in_lo: in_order의 하한
// in_hi: in_order의 상한
// post_lo: post_order의 하한
// post_hi: post_order의 상한
void convert(const int &pre_lo, const int &pre_hi, const int &in_lo,
             const int &in_hi, const int &post_lo, const int &post_hi) {
  // root_num: 루트의 번호
  int root_num = post_order[post_hi];
  // 루트 저장하기
  pre_order[pre_lo] = root_num;
  // 기저: 크기가 1인 노드는 더 이상 처리를 필요로 하지 않음
  if (in_hi == in_lo) {
    return;
  }
  // in_root: in order에서 루트의 위치
  int in_root = 0;
  for (int i = in_lo; i <= in_hi; ++i) {
    if (in_order[i] == root_num) {
      in_root = i;
      break;
    }
  }
  // left_size: 왼쪽 자식 노드의 수
  // right_size: 오른쪽 자식 노드의 수
  int left_size = in_root - in_lo, right_size = in_hi - in_root;
  // 왼쪽 자식 노드가 존재하면 재귀 호출
  if (left_size > 0) {
    convert(pre_lo + 1, pre_lo + left_size, in_lo, in_root - 1, post_lo,
            post_lo + left_size - 1);
  }
  // 오른쪽 자식 노드가 존재하면 재귀 호출
  if (right_size > 0) {
    convert(pre_lo + left_size + 1, pre_hi, in_root + 1, in_hi,
            post_lo + left_size, post_hi - 1);
  }
}

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 트리 노드의 수
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> in_order[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> post_order[i];
  }
  // pre order로 변환
  convert(0, n - 1, 0, n - 1, 0, n - 1);
  // pre_order 출력
  for (int i = 0; i < n; ++i) {
    cout << (i == 0 ? "" : " ") << pre_order[i];
  }
  cout << endl;
}
