#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);
  size_t len1 = str1.length(), len2 = str2.length();
  vector<vector<int>> dist(len1 + 1, vector<int>(len2 + 1));
  for (size_t i = 0; i <= len1; ++i) {
    dist[i][0] = i;
  }
  for (size_t i = 0; i <= len2; ++i) {
    dist[0][i] = i;
  }
  for (size_t i = 1; i <= len1; ++i) {
    for (size_t j = 1; j <= len2; ++j) {
      int val = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
      dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j - 1] + 1);
      dist[i][j] = min(dist[i][j], dist[i - 1][j - 1] + val);
    }
  }
  cout << dist[len1][len2] << endl;
}
