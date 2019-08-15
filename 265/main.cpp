#include <iostream>
#include <vector>

using namespace std;

int n, ans = 987654321;
vector<vector<int>> abil;
vector<int> team_start, team_link;

void solve(int depth) {
  if (depth == n) {
    int score = 0;

    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        score += abil[team_start[i]][team_start[j]] -
                 abil[team_link[i]][team_link[j]];
      }
    }

    if (score < 0)
      score *= -1;
    if (ans > score)
      ans = score;

    return;
  }

  if ((int)team_start.size() < n / 2) {
    team_start.push_back(depth);
    solve(depth + 1);
    team_start.pop_back();
  }
  if ((int)team_link.size() < n / 2) {
    team_link.push_back(depth);
    solve(depth + 1);
    team_link.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  abil.resize(n, vector<int>(n));

  for (auto &row : abil) {
    for (auto &i : row) {
      cin >> i;
    }
  }

  solve(0);

  cout << ans << endl;
}
