#include <iostream>

using namespace std;

int n;
long long w;
int price[15];

int main() {
  cin >> n >> w;
  for (int i = 0; i < n; ++i) {
    cin >> price[i];
  }
  long long coin = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (price[i] < price[i + 1]) {
      coin += w / price[i];
      w %= price[i];
    } else if (price[i] > price[i + 1]) {
      w += coin * price[i];
      coin = 0;
    }
  }
  w += coin * price[n - 1];
  cout << w << "\n";
}
