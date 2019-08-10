#include <iostream>
#include <utility>

using namespace std;
int main() {
  pair<int, int> pos[3];
  for (auto &p : pos) {
    cin >> p.first >> p.second;
  }
  cout << ((pos[0].first == pos[1].first)
               ? pos[2].first
               : (pos[0].first == pos[2].first ? pos[1].first : pos[0].first))
       << " "
       << ((pos[0].second == pos[1].second)
               ? pos[2].second
               : (pos[0].second == pos[2].second ? pos[1].second
                                                 : pos[0].second))
       << "\n";
}
