#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  // num: 수를 저장할 문자열
  string num;
  // num에 숫자를 입력받는다.
  cin >> num;
  // num을 내림차순으로 정렬한다.
  sort(num.begin(), num.end(), std::greater<char>());
  // num을 출력한다.
  cout << num << endl;
}
