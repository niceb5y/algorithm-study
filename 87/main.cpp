#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // heights: 난쟁이들의 키를 저장하는 벡터
  vector<short> heights(9);
  for (auto &h : heights) {
    cin >> h;
  }
  // 키를 오름차순으로 정렬한다.
  sort(heights.begin(), heights.end());
  // 두 난쟁이 i, j를 고른다.
  for (int i = 8; i >= 1; --i) {
    for (int j = i - 1; j >= 0; --j) {
      // sum: 난쟁이들의 키의 합
      int sum = 0;
      // i, j를 제외한 난쟁이들의 키의 합이 100이 되는지 확인한다.
      for (int k = 0; k < 9; ++k) {
        if (k != i && k != j) {
          sum += heights[k];
        }
      }
      // 합이 100이면 키를 출력한다.
      if (sum == 100) {
        for (int k = 0; k < 9; ++k) {
          if (k != i && k != j) {
            cout << heights[k] << '\n';
          }
        }
        exit(0);
      }
    }
  }
}
