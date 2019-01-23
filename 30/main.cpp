#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 삼각형의 크기
  int n;
  cin >> n;
  // sum[i]: (i + 1)번째 삼각형으로 왔을때의 수의 최대 합을 저장할 벡터
  vector<int> sum;
  for (int i = 0; i < n; ++i) {
    // tmp[i]: 임시로 sum[i]의 값을 저장할 벡터
    vector<int> tmp(i + 1);
    for (int j = 0; j <= i; ++j) {
      // num: 삼각형의 해당 지점의 숫자값
      int num;
      cin >> num;
      if (i == 0) {
        // 첫번째 줄은 더하지 않는다.
        tmp[j] = num;
      } else {
        // 두번째 줄부터 더한다.
        // 가장 바깥쪽 숫자는 한쪽씩만 더한다.
        if (j == 0) {
          tmp[j] = sum[j] + num;
        } else if (j == i) {
          tmp[j] = sum[j - 1] + num;
        } else {
          // 다른 숫자들은 숫자 하나를 택해서 더한다.
          tmp[j] = max(sum[j - 1], sum[j]) + num;
        }
      }
    }
    // tmp값을 sum에 대입하기
    sum = tmp;
  }
  // ans: 수의 최대 합
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, sum[i]);
  }
  cout << ans << endl;
}
