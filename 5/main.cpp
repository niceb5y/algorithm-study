#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // n: 배열의 길이
  int n;
  cin >> n;

  // a,b,c,d: A,B,C,D 각 배열의 값을 저장할 벡터
  // c_d: C배열과 D배열의 원소들의 합을 저장할 벡터
  // 네 수의 합을 구하는것은 O(N^4)의 복잡도를 가지므로 시간안에 계산할 수 없다.
  // 따라서 A와 B의 원소들의 합들의 배열을 A_B,  C와 D의 원소들의 합들의 배열을
  // C_D로 두고, 이 두 배열의 원소 중 각각의 합이 0이 되는 원소를 찾는다.
  vector<long long> a(n), b(n), c(n), d(n), c_d(n * n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  // C배열과 D배열의 원소들의 합을 구해서 c_d에 넣는다.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c_d[n * i + j] = c[i] + d[j];
    }
  }
  // 빠른 시간 안에 찾기 위해 이진 탐색을 적용할 예정이므로, c_d를 정렬한다.
  sort(c_d.begin(), c_d.end());

  // ret: 네 수의 합이 0이 되는 경우의 수
  long long ret = 0;
  // a, b 벡터를 순회하여 A, B 배열의 원소들의 합을 구하고, c_d배열과 비교한다.
  for (auto &i : a) {
    for (auto &j : b) {
      // equal_range를 사용하여 이진탐색으로 upper_bound와 lower_bound를 구한다.
      auto bound = equal_range(c_d.begin(), c_d.end(), -(i + j));
      // 두 값의 차이를 이용하여 같은 값을 가지는 원소의 개수를 구하여 더한다.
      ret += distance(bound.first, bound.second);
    }
  }
  cout << ret << endl;
}
