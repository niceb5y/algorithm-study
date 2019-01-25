#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// get_area(): 해당 구역의 가장 큰 직사각형의 넓이를 구한다
// lo, hi: 이터레이터
long get_area(vector<long>::iterator lo, vector<long>::iterator hi) {
  // 기저: 크기가 1인 직사각형
  if (hi - lo == 1) {
    return lo[0];
  }
  // mid: 분할 정복을 위한 기준점
  int mid = (hi - lo) / 2;
  // ret: 직사각형의 최대 넓이
  long ret = max(get_area(lo, lo + mid), get_area(lo + mid, hi));
  // left, right: mid를 포함하는 최대 직사각형의 넓이를 구하기 위한 하한 / 상한
  auto left = lo + mid - 1, right = lo + mid;
  // height: [left...right]의 직사각형의 최대 높이
  long height = min(left[0], right[0]);
  ret = max(ret, height * 2);
  // left, right를 점차 확장시킨다.
  while (left > lo || right < hi - 1) {
    if (right < hi - 1 && (left == lo || *(left - 1) < *(right + 1))) {
      // 오른쪽으로 확장이 필요한 경우
      ++right;
      height = min(height, right[0]);
    } else {
      // 왼쪽으로 확장이 필요한 경우
      --left;
      height = min(height, left[0]);
    }
    // 최대값 구하기
    ret = max(ret, height * (right - left + 1));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (true) {
    // n: 입력받을 직사각형의 수
    int n;
    cin >> n;
    // 0을 입력받으면 프로그램을 종료한다.
    if (n == 0) {
      break;
    }
    // h: 직사각형들의 높이 값을 담는 벡터
    vector<long> h(n);
    for (auto &i : h) {
      cin >> i;
    }
    cout << get_area(h.begin(), h.end()) << "\n";
  }
}
