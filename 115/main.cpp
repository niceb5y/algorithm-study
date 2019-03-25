#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 배송해야 하는 물품의 수
  int n;
  cin >> n;
  // dest[i]: i번째 물품이 도착해야 하는 지점
  // dp[i]: i번째 지점에 물품을 배송하는 최소 비용
  // psum[i]: 지점 i에 물품을 배송할 때 필요한 거리의 부분 합
  // 부분 합을 미리 계산(O(n))하여 필요한 구간 합을 O(1)에 찾을 수 있다.
  vector<int> dest(n + 1, 0), dp(n + 1, 0), psum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> dest[i];
  }
  // cost_truck: 트럭을 통해 물품 하나를 1의 거리만큼 이동하는 데 드는 비용
  // cost_heli: 헬기를 통해 물품을 이동하는 데 드는 비용
  int cost_truck, cost_heli;
  cin >> cost_truck >> cost_heli;
  // dest를 오름차순으로 정렬한다.
  sort(dest.begin(), dest.end());
  for (int i = 1; i <= n; ++i) {
    // i번째 물품을 트럭으로 물품을 이동했을 경우의 비용
    dp[i] = dp[i - 1] + dest[i] * cost_truck;
    // dest의 부분 합을 구한다.
    psum[i] = psum[i - 1] + dest[i];
    // j: 헬기를 통해 이동하는 물품의 범위 [j, i]
    for (int j = i; j >= 0; --j) {
      // mid: 헬기를 통해 물품을 운송해야 하는 지점
      // 물품을 j와 i의 중간 지점으로 운송해야 가격이 최소가 된다.
      int mid = (i + j) / 2;
      // dist_sum_r: mid에서 (mid, i] 지점으로 운송할때 비용의 합.
      // dist_sum_l: mid에서 [j, mid) 지점으로 운송할때 비용의 합.
      int dist_sum_r = (psum[i] - psum[mid]) - (dest[mid] * (i - mid)),
          dist_sum_l = (dest[mid] * (mid - j)) - (psum[mid - 1] - psum[j - 1]);
      // sum_cost_truck: 헬기로 운송 된 물품을 트럭으로 이동하는 비용의 총합
      int sum_cost_truck = (dist_sum_l + dist_sum_r) * cost_truck;
      // 비용의 최솟값을 구한다.
      dp[i] = min(dp[i], dp[j - 1] + sum_cost_truck + cost_heli);
    }
  }
  // 결과 출력
  cout << dp[n] << "\n";
}
