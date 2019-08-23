#include <iostream>
#include <vector>

using namespace std;

int g, p;

vector<int> parent;

int find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b) { parent[find(a)] = find(b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> g >> p;
  parent.resize(g + 1);

  int ans = 0;
  for (int i = 0; i <= g; ++i) {
    parent[i] = i;
  }

  while (p--) {
    int x;
    cin >> x;
    int px = find(x);
    if (px < 1)
      break;
    merge(px, px - 1);
    ++ans;
  }

  cout << ans << "\n";
}
