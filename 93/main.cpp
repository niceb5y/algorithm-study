#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// schedule: 회의의 시작과 끝 시간을 저장하는 pair
// .first, .second: 시작 시간, 끝 시간
typedef pair<int, int> schedule;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 회의의 수
  // last_meeting: 마지막으로 회의가 끝난 시간
  // count: 최대 사용할 수 있는 회의 수
  int n, last_meeting = 0, count = 0;
  cin >> n;
  // meetings: 회의의 목록을 저장하는 벡터
  vector<schedule> meetings(n);
  for (auto &meeting : meetings) {
    cin >> meeting.first >> meeting.second;
  }
  // 회의를 끝나는 시간이 빠른 순으로(끝나는 시간이 같으면 시작하는 시간이 빠른
  // 순으로) 정렬한다.
  sort(meetings.begin(), meetings.end(),
       [](const schedule &s1, const schedule &s2) {
         return s1.second == s2.second ? s1.first < s2.first
                                       : s1.second < s2.second;
       });
  for (auto &meeting : meetings) {
    // 시간이 겹치는지 확인
    if (meeting.first >= last_meeting) {
      // 회의실이 비어있으면 숫자를 1 증가시킨다.
      ++count;
      // 마지막 회의가 끝난 시간을 갱신한다.
      last_meeting = meeting.second;
    }
  }
  // 결과 출력
  cout << count << '\n';
}
