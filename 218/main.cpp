#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct birthday {
  string name;
  int day;
  int month;
  int year;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<birthday> birthdays(n);
  for (auto &b : birthdays) {
    cin >> b.name >> b.day >> b.month >> b.year;
  }

  sort(birthdays.begin(), birthdays.end(), [](auto a, auto b) {
    if (a.year != b.year)
      return a.year < b.year;
    if (a.month != b.month)
      return a.month < b.month;
    return a.day < b.day;
  });

  cout << birthdays[n - 1].name << endl;
  cout << birthdays[0].name << endl;
}
