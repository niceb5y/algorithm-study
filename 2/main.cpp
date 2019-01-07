#include <iostream>
#include <vector>

int main() {
  using namespace std;

  // n: 지점의 개수
  int n;
  cin >> n;

  // cross[i]: i - 1 번째 지점에 있는 횡단보도의 거리
  // left[i]: i - 1 번째 지점에 있는 횡단보도의 거리
  // right[i]: i - 1 번째 지점에 있는 횡단보도의 거리
  vector<long long> cross(n), left(n - 1), right(n - 1);

  // C++11의 Range-based for loop로 입력을 받는다.
  for (auto &i : cross)
    cin >> i;
  for (auto &i : left)
    cin >> i;
  for (auto &i : right)
    cin >> i;

  // left[i]: 1번째 지점에서 i + 1번째 지점까지의 거리의 합이 되도록 계산한다.
  // right[i]: 1번째 지점에서 n번째 지점까지의 거리의 합이 되도록 계산한다.
  for (int i = 1; i < n - 1; ++i) {
    left[i] += left[i - 1];
    right[n - i - 2] += right[n - i - 1];
  }

  // ret_dist: 가장 짧은 경로의 거리
  long long ret_dist;
  // ret_cross: 가장 짧은 경로로 가기 위해 건너야 하는 지점의 횡단보도 번호 - 1
  int ret_cross;

  // i + 1번째 지점의 횡단보도를 건넜을 때의 거리를 내림차순으로 계산한다.
  for (int i = n - 1; i >= 0; --i) {
    // dist: i + 1번째 지점의 횡단보도를 건넜을 때의 거리
    // 첫 지점이나, 마지막 지점에서는 왼쪽이나 오른쪽 거리를 아예 걷지 않는
    // 경우가 있다. 조건부 삼항 연산자를 사용하여 이러한 경우에 대응해준다.
    auto dist =
        (i == 0 ? 0 : left[i - 1]) + cross[i] + (i == n - 1 ? 0 : right[i]);
    // 거리가 처음 계산되거나, 최소 이동거리가 갱신된 경우 ret_dist와
    // ret_cross를 갱신한다.
    if (dist <= ret_dist || i == n - 1) {
      ret_dist = dist;
      ret_cross = i;
    }
  }

  // 계산된 횡단보도의 지점 번호와 최소 이동거리를 출력한다.
  cout << ret_cross + 1 << " " << ret_dist << endl;
}
