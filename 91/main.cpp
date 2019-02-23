#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 주어진 숫자의 개수
  int n;
  cin >> n;
  // num: 주어진 숫자들을 저장할 벡터
  vector<int> num(n);
  for (auto &i : num) {
    cin >> i;
  }
  // diff: num 배열에서 인접한 두 값의 차이들의 최대공약수
  // (== num[i] - num[i - 1], i = [1 ... n])
  // num[i] = a * m + r이고, num[i - 1] = b * m + r이면
  // diff = num[i] - num[i - 1] = (a - b) * m이다.
  int diff = num[1] - num[0];
  // 따라서 num을 순회하며 diff들의 공약수를 구하면 m을 구할 수 있다.
  for (int i = 1; i < n; ++i) {
    diff = gcd(diff, num[i] - num[i - 1]);
  }
  // ans: diff의 약수를 저장하기 위한 배열
  vector<int> ans;
  // diff의 약수를 구한다.
  for (int i = 1; i * i <= diff; ++i) {
    if (diff % i == 0) {
      ans.push_back(i);
      if (i * i < diff) {
        ans.push_back(diff / i);
      }
    }
  }
  // 결과를 출력하기 위해 정렬한다.
  sort(ans.begin(), ans.end());
  // 결과 출력
  for (size_t i = 1; i < ans.size(); ++i) {
    cout << (i == 1 ? "" : " ") << ans[i];
  }
  cout << "\n";
}
