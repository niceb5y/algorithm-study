#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 집의 수
  int n;
  cin >> n;
  // cost: 현재 집을 r, g, b로 칠했을때의 최저비용
  tuple<int, int, int> cost;
  for (int i = 0; i < n; ++i) {
    int r, g, b;
    cin >> r >> g >> b;
    cost = (i == 0) ? make_tuple(r, g, b)
                    : make_tuple(
                          //  지금 집을 빨간색으로 칠했을때의 최소 비용
                          min(r + get<1>(cost), r + get<2>(cost)),
                          //  지금 집을 초록색으로 칠했을때의 최소 비용
                          min(g + get<0>(cost), g + get<2>(cost)),
                          //  지금 집을 파란색으로 칠했을때의 최소 비용
                          min(b + get<0>(cost), b + get<1>(cost)));
  }
  // 최소값을 출력한다.
  cout << min(min(get<0>(cost), get<1>(cost)), get<2>(cost)) << endl;
}
