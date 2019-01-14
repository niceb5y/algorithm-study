#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  // num: 수를 저장할 문자열
  string num;
  // num에 숫자를 입력받는다.
  cin >> num;
  // num을 오름차순으로 정렬한다.
  sort(num.begin(), num.end());
  // num을 뒤집는다.
  reverse(num.begin(), num.end());
  // num을 출력한다.
  cout << num << endl;
}
