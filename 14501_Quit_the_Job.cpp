#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scheduleLen;
vector<pair<int, int>> schedule;
vector<int> cache;
int solve(int index);
int main() {
	cin >> scheduleLen;
	cache = vector<int>(scheduleLen, -1);
	for (int i = 0,time,cost; i < scheduleLen; i++) {
		cin >> time;
		cin >> cost;
		schedule.push_back(make_pair(time, cost));
	}
	solve(0);
	cout << cache[0];
	return 0;
}
int solve(int index) {
	if (index >= scheduleLen) {
		return 0;
	}
	if (cache[index] != -1) {
		return cache[index];
	}
	int tempMax = 0;
	if (index + schedule[index].first <= scheduleLen) {
		tempMax = max(tempMax, solve(index + schedule[index].first) + schedule[index].second);
	}
	tempMax = max(tempMax, solve(index + 1));
	cache[index] = tempMax;
	return tempMax;
}