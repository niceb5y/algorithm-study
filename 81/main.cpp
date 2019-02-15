#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

// quest_t: 퀘스트의 STR, INT, PNT를 저장하는 타입
typedef tuple<int, int, int> quest_t;

// n: 퀘스트의 개수
// dp[n][m]: STR이 (n + 1), INT가 (m + 1)일때 할 수 있는 퀘스트의 최댓값
int n, dp[1000][1000];
// quests: 주어진 퀘스트들을 저장하는 벡터
vector<quest_t> quests;
// progress[i]: 해당 시점에 (i + 1)번째 퀘스트를 했는지 여부
vector<bool> progress;

// solve(cur_str, cur_int): 주어진 STR, INT를 통해 깰 수 있는 퀘스트의 최댓값
int solve(const int &cur_str, const int &cur_int) {
  // norm(n): n이 1000을 넘지 않도록 일반화 해주는 람다 식
  auto norm = [](int n) { return min(n, 1000); };
  // point: 퀘스트를 클리어하여 얻을 수 있는 PNT
  // ret: 함수의 반환값
  int point = 0, &ret = dp[norm(cur_str) - 1][norm(cur_int) - 1];
  if (ret != -1)
    return ret;
  ret = 0;
  // cleared: 이번 함수에서 완료한 퀘스트들을 저장하는 벡터
  vector<int> cleared;
  for (int i = 0; i < n; ++i) {
    // quest_str, quest_list, quest_pnt: 해당 퀘스트의 STR, INT, PNT
    auto [quest_str, quest_int, quest_pnt] = quests[i];
    if ((cur_str >= quest_str) || (cur_int >= quest_int)) {
      // 현재 STR, INT로 깰 수 있는 퀘스트인 경우 ret값을 증가시킨다.
      ++ret;
      if (!progress[i]) {
        // 이전에 깬 적 없는 퀘스트의 경우 포인트를 point를 증가시킨다.
        progress[i] = true;
        point += quest_pnt;
        cleared.push_back(i);
      }
    }
  }
  for (int i = 0; i <= point; ++i) {
    // 얻은 포인트의 분배를 바꿔가며 최대값을 찾는다.
    int next_str = cur_str + i, next_int = norm(cur_int + point - i);
    if (next_str > 1000) {
      break;
    }
    ret = max(ret, solve(next_str, next_int));
  }
  // 다음 함수의 작동을 위해 완료한 퀘스트들의 진행 상황을 되돌린다.
  for (auto &i : cleared) {
    progress[i] = false;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  // 변수들을 초기화한다.
  quests.resize(n);
  progress.resize(n, false);
  fill_n(&dp[0][0], sizeof(dp) / sizeof(int), -1);
  // 퀘스트들을 입력받아 저장한다.
  for (auto &quest : quests) {
    int quest_str, quest_int, quest_pnt;
    cin >> quest_str >> quest_int >> quest_pnt;
    quest = make_tuple(quest_str, quest_int, quest_pnt);
  }
  // 결과 출력
  cout << solve(1, 1) << '\n';
}
