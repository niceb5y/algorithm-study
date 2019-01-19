#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 정렬할 수의 개수
  // k: 정렬된 배열의 [k-1]번째 원소
  int n, k;
  cin >> n >> k;
  // vec: 정렬할 수가 담길 벡터
  vector<int> vec(n);
  for (auto &i : vec) {
    cin >> i;
  }
  // 정렬
  sort(vec.begin(), vec.end());
  // k번째 수를 출력한다.
  cout << vec[k - 1] << endl;
}
