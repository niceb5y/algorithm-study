#include <deque>
#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // t: 테스트 케이스의 개수
  int t;
  cin >> t;
  cin.get();
  for (int i = 0; i < t; ++i) {
    // func: 수행할 함수의 모음
    string func;
    getline(cin, func);
    // n: 배열의 크기
    int n;
    cin >> n;
    cin.get();
    // num: 숫자를 저장할 덱
    deque<int> num(n);
    // reversed: 배열이 반전되었는지의 여부
    // has_error: 에러가 발생하였는지의 여부
    bool reversed = false, has_error = false;
    for (auto &j : num) {
      cin.get();
      cin >> j;
    }
    cin.ignore(2, '\n');
    for (auto &c : func) {
      if (c == 'R') {
        // 배열 반전
        reversed = !reversed;
      }
      if (c == 'D') {
        if (num.size() > 0) {
          // 원소 지우기
          if (reversed) {
            num.pop_back();
          } else {
            num.pop_front();
          }
        } else {
          // 원소가 0일때 삭제를 시도한 경우 에러를 발생시킨다.
          has_error = true;
          break;
        }
      }
    }
    if (has_error) {
      // 에러 출력
      cout << "error\n";
    } else {
      // 배열 출력
      cout << "[";
      for (int j = 0, size = num.size(); j < size; ++j) {
        if (reversed) {
          cout << (j == 0 ? "" : ",") << num[size - 1 - j];
        } else {
          cout << (j == 0 ? "" : ",") << num[j];
        }
      }
      cout << "]\n";
    }
  }
}
