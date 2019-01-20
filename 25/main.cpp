#include <iostream>
#include <tuple>

using namespace std;

// result: count()함수의 반환 형식
typedef tuple<int, int, int> result;

// num: 종이를 표현할 행렬이 담긴 2차원 배열
// n: 종이의 한 변의 길이
int num[2187][2187], n;

// 더하기 연산자 재지정
result operator+(const result &l, const result &r) {
  return make_tuple(get<0>(l) + get<0>(r), get<1>(l) + get<1>(r),
                    get<2>(l) + get<2>(r));
}

// 출력 연산자 재지정
ostream &operator<<(ostream &os, const result &res) {
  os << get<0>(res) << '\n' << get<1>(res) << '\n' << get<2>(res);
  return os;
}
// count(): 행렬로 표현되는 종이를 규칙에 맞게 잘랐을 때, 종이의 개수를
// 반환한다.
result count(const int &x, const int &y, const int &size) {
  // first: 해당 배열의 첫번째 원소
  const int &first = num[y][x];
  // 기저: 크기가 1인 경우 값을 반환한다.
  if (size == 1) {
    return make_tuple(first == -1, first == 0, first == 1);
  }
  // 모든 원소가 같은 값인지 검사한다.
  for (int i = y; i < y + size; ++i) {
    for (int j = x; j < x + size; ++j) {
      // 모든 원소가 같은 값을 갖지 않는 경우 종이를 9등분 하기 위해
      // 재귀호출한다.
      if (first != num[i][j]) {
        // ret: 함수의 반환값
        result ret = make_tuple(0, 0, 0);
        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            ret = ret + count(x + k * size / 3, y + l * size / 3, size / 3);
          }
        }
        return ret;
      }
    }
  }
  // 모든 원소가 같은 값을 갖는 경우 첫번째 값을 검사하여 반환한다.
  return make_tuple(first == -1, first == 0, first == 1);
}

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> num[i][j];
    }
  }
  cout << count(0, 0, n) << endl;
}
