#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > button({
	vector<int>({ 0, 1, 2 }),
	vector<int>({ 3, 7, 9, 11 }),
	vector<int>({ 4, 10, 14, 15 }),
	vector<int>({ 0, 4, 5, 6, 7 }),
	vector<int>({ 6, 7, 8, 10, 12 }),
	vector<int>({ 0, 2, 14, 15 }),
	vector<int>({ 3, 14, 15 }),
	vector<int>({ 4, 5, 7, 14, 15 }),
	vector<int>({ 1, 2, 3, 4, 5 }),
	vector<int>({ 3, 4, 5, 9, 13 })
	});
vector<int> clocks(16,12);
bool allSynced(vector<int> clockInput);
void trigSwitch(vector<int> clockinput, int switchNum);
int sync(vector<int> clockinput, int switchNum);
int main() {
	int testcase = 0;
	cin >> testcase;
	cin.ignore();
	for (int trial = 0; trial < testcase; trial++) {
		for (int i = 0; i < 16; i++) {
			cin >> clocks[i];
			cin.ignore();
		}
		int result = sync(clocks, 0);
		if (result == INT8_MAX) {
			cout << "-1" << endl;
		}
		else {
			cout << result << endl;
		}
	}
	return 0;
}
bool allSynced(vector<int> clockInput) {
	bool synced = true;
	for (int clock : clockInput) {
		if (clock % 12 != 0) {
			synced = false;
			break;
		}
	}
	return synced;
}
void trigSwitch(vector<int> clockinput, int switchNum) {
	for (int targetClock: button[switchNum]) {
		clocks[targetClock] += 3;
	}
 }

int sync(vector<int> clockinput, int switchNum) {
	int minClick = INT8_MAX;
	if(switchNum >= button.size()) {
		if (allSynced(clocks)) {
			return 0;
		}
		else {
			return INT8_MAX;
		}
	}
	for (int click = 0; click < 4; click++) {
		minClick = min(minClick, click + sync(clocks, switchNum + 1));
		trigSwitch(clockinput, switchNum);
	}
	return minClick;
}